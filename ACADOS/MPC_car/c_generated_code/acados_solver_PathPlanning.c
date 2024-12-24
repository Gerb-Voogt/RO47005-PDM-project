/*
 * Copyright (c) The acados authors.
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */

// standard
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// acados
// #include "acados/utils/print.h"
#include "acados_c/ocp_nlp_interface.h"
#include "acados_c/external_function_interface.h"

// example specific
#include "PathPlanning_model/PathPlanning_model.h"


#include "PathPlanning_constraints/PathPlanning_constraints.h"
#include "PathPlanning_cost/PathPlanning_cost.h"



#include "acados_solver_PathPlanning.h"

#define NX     PATHPLANNING_NX
#define NZ     PATHPLANNING_NZ
#define NU     PATHPLANNING_NU
#define NP     PATHPLANNING_NP
#define NP_GLOBAL     PATHPLANNING_NP_GLOBAL
#define NY0    PATHPLANNING_NY0
#define NY     PATHPLANNING_NY
#define NYN    PATHPLANNING_NYN

#define NBX    PATHPLANNING_NBX
#define NBX0   PATHPLANNING_NBX0
#define NBU    PATHPLANNING_NBU
#define NG     PATHPLANNING_NG
#define NBXN   PATHPLANNING_NBXN
#define NGN    PATHPLANNING_NGN

#define NH     PATHPLANNING_NH
#define NHN    PATHPLANNING_NHN
#define NH0    PATHPLANNING_NH0
#define NPHI   PATHPLANNING_NPHI
#define NPHIN  PATHPLANNING_NPHIN
#define NPHI0  PATHPLANNING_NPHI0
#define NR     PATHPLANNING_NR

#define NS     PATHPLANNING_NS
#define NS0    PATHPLANNING_NS0
#define NSN    PATHPLANNING_NSN

#define NSBX   PATHPLANNING_NSBX
#define NSBU   PATHPLANNING_NSBU
#define NSH0   PATHPLANNING_NSH0
#define NSH    PATHPLANNING_NSH
#define NSHN   PATHPLANNING_NSHN
#define NSG    PATHPLANNING_NSG
#define NSPHI0 PATHPLANNING_NSPHI0
#define NSPHI  PATHPLANNING_NSPHI
#define NSPHIN PATHPLANNING_NSPHIN
#define NSGN   PATHPLANNING_NSGN
#define NSBXN  PATHPLANNING_NSBXN



// ** solver data **

PathPlanning_solver_capsule * PathPlanning_acados_create_capsule(void)
{
    void* capsule_mem = malloc(sizeof(PathPlanning_solver_capsule));
    PathPlanning_solver_capsule *capsule = (PathPlanning_solver_capsule *) capsule_mem;

    return capsule;
}


int PathPlanning_acados_free_capsule(PathPlanning_solver_capsule *capsule)
{
    free(capsule);
    return 0;
}


int PathPlanning_acados_create(PathPlanning_solver_capsule* capsule)
{
    int N_shooting_intervals = PATHPLANNING_N;
    double* new_time_steps = NULL; // NULL -> don't alter the code generated time-steps
    return PathPlanning_acados_create_with_discretization(capsule, N_shooting_intervals, new_time_steps);
}


int PathPlanning_acados_update_time_steps(PathPlanning_solver_capsule* capsule, int N, double* new_time_steps)
{
    if (N != capsule->nlp_solver_plan->N) {
        fprintf(stderr, "PathPlanning_acados_update_time_steps: given number of time steps (= %d) " \
            "differs from the currently allocated number of " \
            "time steps (= %d)!\n" \
            "Please recreate with new discretization and provide a new vector of time_stamps!\n",
            N, capsule->nlp_solver_plan->N);
        return 1;
    }

    ocp_nlp_config * nlp_config = capsule->nlp_config;
    ocp_nlp_dims * nlp_dims = capsule->nlp_dims;
    ocp_nlp_in * nlp_in = capsule->nlp_in;

    for (int i = 0; i < N; i++)
    {
        ocp_nlp_in_set(nlp_config, nlp_dims, nlp_in, i, "Ts", &new_time_steps[i]);
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, i, "scaling", &new_time_steps[i]);
    }
    return 0;
}

/**
 * Internal function for PathPlanning_acados_create: step 1
 */
void PathPlanning_acados_create_set_plan(ocp_nlp_plan_t* nlp_solver_plan, const int N)
{
    assert(N == nlp_solver_plan->N);

    /************************************************
    *  plan
    ************************************************/

    nlp_solver_plan->nlp_solver = SQP;

    nlp_solver_plan->ocp_qp_solver_plan.qp_solver = PARTIAL_CONDENSING_HPIPM;

    nlp_solver_plan->nlp_cost[0] = EXTERNAL;
    for (int i = 1; i < N; i++)
        nlp_solver_plan->nlp_cost[i] = EXTERNAL;

    nlp_solver_plan->nlp_cost[N] = EXTERNAL;

    for (int i = 0; i < N; i++)
    {
        nlp_solver_plan->nlp_dynamics[i] = DISCRETE_MODEL;
        // discrete dynamics does not need sim solver option, this field is ignored
        nlp_solver_plan->sim_solver_plan[i].sim_solver = INVALID_SIM_SOLVER;
    }

    nlp_solver_plan->nlp_constraints[0] = BGH;

    for (int i = 1; i < N; i++)
    {
        nlp_solver_plan->nlp_constraints[i] = BGH;
    }
    nlp_solver_plan->nlp_constraints[N] = BGH;

    nlp_solver_plan->regularization = PROJECT_REDUC_HESS;

    nlp_solver_plan->globalization = FIXED_STEP;
}


static ocp_nlp_dims* PathPlanning_acados_create_setup_dimensions(PathPlanning_solver_capsule* capsule)
{
    ocp_nlp_plan_t* nlp_solver_plan = capsule->nlp_solver_plan;
    const int N = nlp_solver_plan->N;
    ocp_nlp_config* nlp_config = capsule->nlp_config;

    /************************************************
    *  dimensions
    ************************************************/
    #define NINTNP1MEMS 18
    int* intNp1mem = (int*)malloc( (N+1)*sizeof(int)*NINTNP1MEMS );

    int* nx    = intNp1mem + (N+1)*0;
    int* nu    = intNp1mem + (N+1)*1;
    int* nbx   = intNp1mem + (N+1)*2;
    int* nbu   = intNp1mem + (N+1)*3;
    int* nsbx  = intNp1mem + (N+1)*4;
    int* nsbu  = intNp1mem + (N+1)*5;
    int* nsg   = intNp1mem + (N+1)*6;
    int* nsh   = intNp1mem + (N+1)*7;
    int* nsphi = intNp1mem + (N+1)*8;
    int* ns    = intNp1mem + (N+1)*9;
    int* ng    = intNp1mem + (N+1)*10;
    int* nh    = intNp1mem + (N+1)*11;
    int* nphi  = intNp1mem + (N+1)*12;
    int* nz    = intNp1mem + (N+1)*13;
    int* ny    = intNp1mem + (N+1)*14;
    int* nr    = intNp1mem + (N+1)*15;
    int* nbxe  = intNp1mem + (N+1)*16;
    int* np  = intNp1mem + (N+1)*17;

    for (int i = 0; i < N+1; i++)
    {
        // common
        nx[i]     = NX;
        nu[i]     = NU;
        nz[i]     = NZ;
        ns[i]     = NS;
        // cost
        ny[i]     = NY;
        // constraints
        nbx[i]    = NBX;
        nbu[i]    = NBU;
        nsbx[i]   = NSBX;
        nsbu[i]   = NSBU;
        nsg[i]    = NSG;
        nsh[i]    = NSH;
        nsphi[i]  = NSPHI;
        ng[i]     = NG;
        nh[i]     = NH;
        nphi[i]   = NPHI;
        nr[i]     = NR;
        nbxe[i]   = 0;
        np[i]     = NP;
    }

    // for initial state
    nbx[0] = NBX0;
    nsbx[0] = 0;
    ns[0] = NS0;
    nbxe[0] = 0;
    ny[0] = NY0;
    nh[0] = NH0;
    nsh[0] = NSH0;
    nsphi[0] = NSPHI0;
    nphi[0] = NPHI0;


    // terminal - common
    nu[N]   = 0;
    nz[N]   = 0;
    ns[N]   = NSN;
    // cost
    ny[N]   = NYN;
    // constraint
    nbx[N]   = NBXN;
    nbu[N]   = 0;
    ng[N]    = NGN;
    nh[N]    = NHN;
    nphi[N]  = NPHIN;
    nr[N]    = 0;

    nsbx[N]  = NSBXN;
    nsbu[N]  = 0;
    nsg[N]   = NSGN;
    nsh[N]   = NSHN;
    nsphi[N] = NSPHIN;

    /* create and set ocp_nlp_dims */
    ocp_nlp_dims * nlp_dims = ocp_nlp_dims_create(nlp_config);

    ocp_nlp_dims_set_opt_vars(nlp_config, nlp_dims, "nx", nx);
    ocp_nlp_dims_set_opt_vars(nlp_config, nlp_dims, "nu", nu);
    ocp_nlp_dims_set_opt_vars(nlp_config, nlp_dims, "nz", nz);
    ocp_nlp_dims_set_opt_vars(nlp_config, nlp_dims, "ns", ns);
    ocp_nlp_dims_set_opt_vars(nlp_config, nlp_dims, "np", np);

    ocp_nlp_dims_set_global(nlp_config, nlp_dims, "np_global", 0);
    ocp_nlp_dims_set_global(nlp_config, nlp_dims, "n_global_data", 0);

    for (int i = 0; i <= N; i++)
    {
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nbx", &nbx[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nbu", &nbu[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nsbx", &nsbx[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nsbu", &nsbu[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "ng", &ng[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nsg", &nsg[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nbxe", &nbxe[i]);
    }
    ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, 0, "nh", &nh[0]);
    ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, 0, "nsh", &nsh[0]);

    for (int i = 1; i < N; i++)
    {
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nh", &nh[i]);
        ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, i, "nsh", &nsh[i]);
    }
    ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, N, "nh", &nh[N]);
    ocp_nlp_dims_set_constraints(nlp_config, nlp_dims, N, "nsh", &nsh[N]);

    free(intNp1mem);

    return nlp_dims;
}


/**
 * Internal function for PathPlanning_acados_create: step 3
 */
void PathPlanning_acados_create_setup_functions(PathPlanning_solver_capsule* capsule)
{
    const int N = capsule->nlp_solver_plan->N;

    /************************************************
    *  external functions
    ************************************************/

#define MAP_CASADI_FNC(__CAPSULE_FNC__, __MODEL_BASE_FNC__) do{ \
        capsule->__CAPSULE_FNC__.casadi_fun = & __MODEL_BASE_FNC__ ;\
        capsule->__CAPSULE_FNC__.casadi_n_in = & __MODEL_BASE_FNC__ ## _n_in; \
        capsule->__CAPSULE_FNC__.casadi_n_out = & __MODEL_BASE_FNC__ ## _n_out; \
        capsule->__CAPSULE_FNC__.casadi_sparsity_in = & __MODEL_BASE_FNC__ ## _sparsity_in; \
        capsule->__CAPSULE_FNC__.casadi_sparsity_out = & __MODEL_BASE_FNC__ ## _sparsity_out; \
        capsule->__CAPSULE_FNC__.casadi_work = & __MODEL_BASE_FNC__ ## _work; \
        external_function_external_param_casadi_create(&capsule->__CAPSULE_FNC__, &ext_fun_opts); \
    } while(false)

    external_function_opts ext_fun_opts;
    external_function_opts_set_to_default(&ext_fun_opts);


    ext_fun_opts.external_workspace = true;
    // constraints.constr_type == "BGH" and dims.nh > 0
    capsule->nl_constr_h_fun_jac = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*(N-1));
    for (int i = 0; i < N-1; i++) {
        MAP_CASADI_FNC(nl_constr_h_fun_jac[i], PathPlanning_constr_h_fun_jac_uxt_zt);
    }
    capsule->nl_constr_h_fun = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*(N-1));
    for (int i = 0; i < N-1; i++) {
        MAP_CASADI_FNC(nl_constr_h_fun[i], PathPlanning_constr_h_fun);
    }

    // external cost
    MAP_CASADI_FNC(ext_cost_0_fun, PathPlanning_cost_ext_cost_0_fun);
    MAP_CASADI_FNC(ext_cost_0_fun_jac, PathPlanning_cost_ext_cost_0_fun_jac);
    MAP_CASADI_FNC(ext_cost_0_fun_jac_hess, PathPlanning_cost_ext_cost_0_fun_jac_hess);




    // discrete dynamics
    capsule->discr_dyn_phi_fun = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*N);
    for (int i = 0; i < N; i++)
    {
        MAP_CASADI_FNC(discr_dyn_phi_fun[i], PathPlanning_dyn_disc_phi_fun);
    }

    capsule->discr_dyn_phi_fun_jac_ut_xt = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*N);
    for (int i = 0; i < N; i++)
    {
        MAP_CASADI_FNC(discr_dyn_phi_fun_jac_ut_xt[i], PathPlanning_dyn_disc_phi_fun_jac);
    }

  

  
    // external cost
    capsule->ext_cost_fun = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*(N-1));
    for (int i = 0; i < N-1; i++)
    {
        MAP_CASADI_FNC(ext_cost_fun[i], PathPlanning_cost_ext_cost_fun);
    }

    capsule->ext_cost_fun_jac = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*(N-1));
    for (int i = 0; i < N-1; i++)
    {
        MAP_CASADI_FNC(ext_cost_fun_jac[i], PathPlanning_cost_ext_cost_fun_jac);
    }

    capsule->ext_cost_fun_jac_hess = (external_function_external_param_casadi *) malloc(sizeof(external_function_external_param_casadi)*(N-1));
    for (int i = 0; i < N-1; i++)
    {
        MAP_CASADI_FNC(ext_cost_fun_jac_hess[i], PathPlanning_cost_ext_cost_fun_jac_hess);
    }

    

    
    MAP_CASADI_FNC(nl_constr_h_e_fun_jac, PathPlanning_constr_h_e_fun_jac_uxt_zt);
    MAP_CASADI_FNC(nl_constr_h_e_fun, PathPlanning_constr_h_e_fun);
    
    
    // external cost - function
    MAP_CASADI_FNC(ext_cost_e_fun, PathPlanning_cost_ext_cost_e_fun);

    // external cost - jacobian
    MAP_CASADI_FNC(ext_cost_e_fun_jac, PathPlanning_cost_ext_cost_e_fun_jac);

    // external cost - hessian
    MAP_CASADI_FNC(ext_cost_e_fun_jac_hess, PathPlanning_cost_ext_cost_e_fun_jac_hess);

    // external cost - jacobian wrt params
    

    

#undef MAP_CASADI_FNC
}


/**
 * Internal function for PathPlanning_acados_create: step 4
 */
void PathPlanning_acados_create_set_default_parameters(PathPlanning_solver_capsule* capsule)
{

    // no parameters defined


    // no global parameters defined
}


/**
 * Internal function for PathPlanning_acados_create: step 5
 */
void PathPlanning_acados_setup_nlp_in(PathPlanning_solver_capsule* capsule, const int N, double* new_time_steps)
{
    assert(N == capsule->nlp_solver_plan->N);
    ocp_nlp_config* nlp_config = capsule->nlp_config;
    ocp_nlp_dims* nlp_dims = capsule->nlp_dims;

    int tmp_int = 0;

    /************************************************
    *  nlp_in
    ************************************************/
//    ocp_nlp_in * nlp_in = ocp_nlp_in_create(nlp_config, nlp_dims);
//    capsule->nlp_in = nlp_in;
    ocp_nlp_in * nlp_in = capsule->nlp_in;

    // set up time_steps and cost_scaling

    if (new_time_steps)
    {
        // NOTE: this sets scaling and time_steps
        PathPlanning_acados_update_time_steps(capsule, N, new_time_steps);
    }
    else
    {
        // set time_steps
    double time_step = 0.25;
        for (int i = 0; i < N; i++)
        {
            ocp_nlp_in_set(nlp_config, nlp_dims, nlp_in, i, "Ts", &time_step);
        }
        // set cost scaling
        double* cost_scaling = malloc((N+1)*sizeof(double));
        cost_scaling[0] = 0.25;
        cost_scaling[1] = 0.25;
        cost_scaling[2] = 0.25;
        cost_scaling[3] = 0.25;
        cost_scaling[4] = 0.25;
        cost_scaling[5] = 0.25;
        cost_scaling[6] = 0.25;
        cost_scaling[7] = 0.25;
        cost_scaling[8] = 0.25;
        cost_scaling[9] = 0.25;
        cost_scaling[10] = 0.25;
        cost_scaling[11] = 0.25;
        cost_scaling[12] = 0.25;
        cost_scaling[13] = 0.25;
        cost_scaling[14] = 0.25;
        cost_scaling[15] = 0.25;
        cost_scaling[16] = 0.25;
        cost_scaling[17] = 0.25;
        cost_scaling[18] = 0.25;
        cost_scaling[19] = 0.25;
        cost_scaling[20] = 0.25;
        cost_scaling[21] = 0.25;
        cost_scaling[22] = 0.25;
        cost_scaling[23] = 0.25;
        cost_scaling[24] = 0.25;
        cost_scaling[25] = 0.25;
        cost_scaling[26] = 0.25;
        cost_scaling[27] = 0.25;
        cost_scaling[28] = 0.25;
        cost_scaling[29] = 0.25;
        cost_scaling[30] = 0.25;
        cost_scaling[31] = 0.25;
        cost_scaling[32] = 0.25;
        cost_scaling[33] = 0.25;
        cost_scaling[34] = 0.25;
        cost_scaling[35] = 0.25;
        cost_scaling[36] = 0.25;
        cost_scaling[37] = 0.25;
        cost_scaling[38] = 0.25;
        cost_scaling[39] = 0.25;
        cost_scaling[40] = 0.25;
        cost_scaling[41] = 0.25;
        cost_scaling[42] = 0.25;
        cost_scaling[43] = 0.25;
        cost_scaling[44] = 0.25;
        cost_scaling[45] = 0.25;
        cost_scaling[46] = 0.25;
        cost_scaling[47] = 0.25;
        cost_scaling[48] = 0.25;
        cost_scaling[49] = 0.25;
        cost_scaling[50] = 0.25;
        cost_scaling[51] = 0.25;
        cost_scaling[52] = 0.25;
        cost_scaling[53] = 0.25;
        cost_scaling[54] = 0.25;
        cost_scaling[55] = 0.25;
        cost_scaling[56] = 0.25;
        cost_scaling[57] = 0.25;
        cost_scaling[58] = 0.25;
        cost_scaling[59] = 0.25;
        cost_scaling[60] = 0.25;
        cost_scaling[61] = 0.25;
        cost_scaling[62] = 0.25;
        cost_scaling[63] = 0.25;
        cost_scaling[64] = 0.25;
        cost_scaling[65] = 0.25;
        cost_scaling[66] = 0.25;
        cost_scaling[67] = 0.25;
        cost_scaling[68] = 0.25;
        cost_scaling[69] = 0.25;
        cost_scaling[70] = 0.25;
        cost_scaling[71] = 0.25;
        cost_scaling[72] = 0.25;
        cost_scaling[73] = 0.25;
        cost_scaling[74] = 0.25;
        cost_scaling[75] = 0.25;
        cost_scaling[76] = 0.25;
        cost_scaling[77] = 0.25;
        cost_scaling[78] = 0.25;
        cost_scaling[79] = 0.25;
        cost_scaling[80] = 0.25;
        cost_scaling[81] = 0.25;
        cost_scaling[82] = 0.25;
        cost_scaling[83] = 0.25;
        cost_scaling[84] = 0.25;
        cost_scaling[85] = 0.25;
        cost_scaling[86] = 0.25;
        cost_scaling[87] = 0.25;
        cost_scaling[88] = 0.25;
        cost_scaling[89] = 0.25;
        cost_scaling[90] = 0.25;
        cost_scaling[91] = 0.25;
        cost_scaling[92] = 0.25;
        cost_scaling[93] = 0.25;
        cost_scaling[94] = 0.25;
        cost_scaling[95] = 0.25;
        cost_scaling[96] = 0.25;
        cost_scaling[97] = 0.25;
        cost_scaling[98] = 0.25;
        cost_scaling[99] = 0.25;
        cost_scaling[100] = 0.25;
        cost_scaling[101] = 0.25;
        cost_scaling[102] = 0.25;
        cost_scaling[103] = 0.25;
        cost_scaling[104] = 0.25;
        cost_scaling[105] = 0.25;
        cost_scaling[106] = 0.25;
        cost_scaling[107] = 0.25;
        cost_scaling[108] = 0.25;
        cost_scaling[109] = 0.25;
        cost_scaling[110] = 0.25;
        cost_scaling[111] = 0.25;
        cost_scaling[112] = 0.25;
        cost_scaling[113] = 0.25;
        cost_scaling[114] = 0.25;
        cost_scaling[115] = 0.25;
        cost_scaling[116] = 0.25;
        cost_scaling[117] = 0.25;
        cost_scaling[118] = 0.25;
        cost_scaling[119] = 0.25;
        cost_scaling[120] = 0.25;
        cost_scaling[121] = 0.25;
        cost_scaling[122] = 0.25;
        cost_scaling[123] = 0.25;
        cost_scaling[124] = 0.25;
        cost_scaling[125] = 0.25;
        cost_scaling[126] = 0.25;
        cost_scaling[127] = 0.25;
        cost_scaling[128] = 0.25;
        cost_scaling[129] = 0.25;
        cost_scaling[130] = 0.25;
        cost_scaling[131] = 0.25;
        cost_scaling[132] = 0.25;
        cost_scaling[133] = 0.25;
        cost_scaling[134] = 0.25;
        cost_scaling[135] = 0.25;
        cost_scaling[136] = 0.25;
        cost_scaling[137] = 0.25;
        cost_scaling[138] = 0.25;
        cost_scaling[139] = 0.25;
        cost_scaling[140] = 0.25;
        cost_scaling[141] = 0.25;
        cost_scaling[142] = 0.25;
        cost_scaling[143] = 0.25;
        cost_scaling[144] = 0.25;
        cost_scaling[145] = 0.25;
        cost_scaling[146] = 0.25;
        cost_scaling[147] = 0.25;
        cost_scaling[148] = 0.25;
        cost_scaling[149] = 0.25;
        cost_scaling[150] = 0.25;
        cost_scaling[151] = 0.25;
        cost_scaling[152] = 0.25;
        cost_scaling[153] = 0.25;
        cost_scaling[154] = 0.25;
        cost_scaling[155] = 0.25;
        cost_scaling[156] = 0.25;
        cost_scaling[157] = 0.25;
        cost_scaling[158] = 0.25;
        cost_scaling[159] = 0.25;
        cost_scaling[160] = 0.25;
        cost_scaling[161] = 0.25;
        cost_scaling[162] = 0.25;
        cost_scaling[163] = 0.25;
        cost_scaling[164] = 0.25;
        cost_scaling[165] = 0.25;
        cost_scaling[166] = 0.25;
        cost_scaling[167] = 0.25;
        cost_scaling[168] = 0.25;
        cost_scaling[169] = 0.25;
        cost_scaling[170] = 0.25;
        cost_scaling[171] = 0.25;
        cost_scaling[172] = 0.25;
        cost_scaling[173] = 0.25;
        cost_scaling[174] = 0.25;
        cost_scaling[175] = 0.25;
        cost_scaling[176] = 0.25;
        cost_scaling[177] = 0.25;
        cost_scaling[178] = 0.25;
        cost_scaling[179] = 0.25;
        cost_scaling[180] = 0.25;
        cost_scaling[181] = 0.25;
        cost_scaling[182] = 0.25;
        cost_scaling[183] = 0.25;
        cost_scaling[184] = 0.25;
        cost_scaling[185] = 0.25;
        cost_scaling[186] = 0.25;
        cost_scaling[187] = 0.25;
        cost_scaling[188] = 0.25;
        cost_scaling[189] = 0.25;
        cost_scaling[190] = 0.25;
        cost_scaling[191] = 0.25;
        cost_scaling[192] = 0.25;
        cost_scaling[193] = 0.25;
        cost_scaling[194] = 0.25;
        cost_scaling[195] = 0.25;
        cost_scaling[196] = 0.25;
        cost_scaling[197] = 0.25;
        cost_scaling[198] = 0.25;
        cost_scaling[199] = 0.25;
        cost_scaling[200] = 0.25;
        cost_scaling[201] = 0.25;
        cost_scaling[202] = 0.25;
        cost_scaling[203] = 0.25;
        cost_scaling[204] = 0.25;
        cost_scaling[205] = 0.25;
        cost_scaling[206] = 0.25;
        cost_scaling[207] = 0.25;
        cost_scaling[208] = 0.25;
        cost_scaling[209] = 0.25;
        cost_scaling[210] = 0.25;
        cost_scaling[211] = 0.25;
        cost_scaling[212] = 0.25;
        cost_scaling[213] = 0.25;
        cost_scaling[214] = 0.25;
        cost_scaling[215] = 0.25;
        cost_scaling[216] = 0.25;
        cost_scaling[217] = 0.25;
        cost_scaling[218] = 0.25;
        cost_scaling[219] = 0.25;
        cost_scaling[220] = 0.25;
        cost_scaling[221] = 0.25;
        cost_scaling[222] = 0.25;
        cost_scaling[223] = 0.25;
        cost_scaling[224] = 0.25;
        cost_scaling[225] = 0.25;
        cost_scaling[226] = 0.25;
        cost_scaling[227] = 0.25;
        cost_scaling[228] = 0.25;
        cost_scaling[229] = 0.25;
        cost_scaling[230] = 0.25;
        cost_scaling[231] = 0.25;
        cost_scaling[232] = 0.25;
        cost_scaling[233] = 0.25;
        cost_scaling[234] = 0.25;
        cost_scaling[235] = 0.25;
        cost_scaling[236] = 0.25;
        cost_scaling[237] = 0.25;
        cost_scaling[238] = 0.25;
        cost_scaling[239] = 0.25;
        cost_scaling[240] = 0.25;
        cost_scaling[241] = 0.25;
        cost_scaling[242] = 0.25;
        cost_scaling[243] = 0.25;
        cost_scaling[244] = 0.25;
        cost_scaling[245] = 0.25;
        cost_scaling[246] = 0.25;
        cost_scaling[247] = 0.25;
        cost_scaling[248] = 0.25;
        cost_scaling[249] = 0.25;
        cost_scaling[250] = 0.25;
        cost_scaling[251] = 0.25;
        cost_scaling[252] = 0.25;
        cost_scaling[253] = 0.25;
        cost_scaling[254] = 0.25;
        cost_scaling[255] = 0.25;
        cost_scaling[256] = 0.25;
        cost_scaling[257] = 0.25;
        cost_scaling[258] = 0.25;
        cost_scaling[259] = 0.25;
        cost_scaling[260] = 0.25;
        cost_scaling[261] = 0.25;
        cost_scaling[262] = 0.25;
        cost_scaling[263] = 0.25;
        cost_scaling[264] = 0.25;
        cost_scaling[265] = 0.25;
        cost_scaling[266] = 0.25;
        cost_scaling[267] = 0.25;
        cost_scaling[268] = 0.25;
        cost_scaling[269] = 0.25;
        cost_scaling[270] = 0.25;
        cost_scaling[271] = 0.25;
        cost_scaling[272] = 0.25;
        cost_scaling[273] = 0.25;
        cost_scaling[274] = 0.25;
        cost_scaling[275] = 0.25;
        cost_scaling[276] = 0.25;
        cost_scaling[277] = 0.25;
        cost_scaling[278] = 0.25;
        cost_scaling[279] = 0.25;
        cost_scaling[280] = 0.25;
        cost_scaling[281] = 0.25;
        cost_scaling[282] = 0.25;
        cost_scaling[283] = 0.25;
        cost_scaling[284] = 0.25;
        cost_scaling[285] = 0.25;
        cost_scaling[286] = 0.25;
        cost_scaling[287] = 0.25;
        cost_scaling[288] = 0.25;
        cost_scaling[289] = 0.25;
        cost_scaling[290] = 0.25;
        cost_scaling[291] = 0.25;
        cost_scaling[292] = 0.25;
        cost_scaling[293] = 0.25;
        cost_scaling[294] = 0.25;
        cost_scaling[295] = 0.25;
        cost_scaling[296] = 0.25;
        cost_scaling[297] = 0.25;
        cost_scaling[298] = 0.25;
        cost_scaling[299] = 0.25;
        cost_scaling[300] = 0.25;
        cost_scaling[301] = 0.25;
        cost_scaling[302] = 0.25;
        cost_scaling[303] = 0.25;
        cost_scaling[304] = 0.25;
        cost_scaling[305] = 0.25;
        cost_scaling[306] = 0.25;
        cost_scaling[307] = 0.25;
        cost_scaling[308] = 0.25;
        cost_scaling[309] = 0.25;
        cost_scaling[310] = 0.25;
        cost_scaling[311] = 0.25;
        cost_scaling[312] = 0.25;
        cost_scaling[313] = 0.25;
        cost_scaling[314] = 0.25;
        cost_scaling[315] = 0.25;
        cost_scaling[316] = 0.25;
        cost_scaling[317] = 0.25;
        cost_scaling[318] = 0.25;
        cost_scaling[319] = 0.25;
        cost_scaling[320] = 0.25;
        cost_scaling[321] = 0.25;
        cost_scaling[322] = 0.25;
        cost_scaling[323] = 0.25;
        cost_scaling[324] = 0.25;
        cost_scaling[325] = 0.25;
        cost_scaling[326] = 0.25;
        cost_scaling[327] = 0.25;
        cost_scaling[328] = 0.25;
        cost_scaling[329] = 0.25;
        cost_scaling[330] = 0.25;
        cost_scaling[331] = 0.25;
        cost_scaling[332] = 0.25;
        cost_scaling[333] = 0.25;
        cost_scaling[334] = 0.25;
        cost_scaling[335] = 0.25;
        cost_scaling[336] = 0.25;
        cost_scaling[337] = 0.25;
        cost_scaling[338] = 0.25;
        cost_scaling[339] = 0.25;
        cost_scaling[340] = 0.25;
        cost_scaling[341] = 0.25;
        cost_scaling[342] = 0.25;
        cost_scaling[343] = 0.25;
        cost_scaling[344] = 0.25;
        cost_scaling[345] = 0.25;
        cost_scaling[346] = 0.25;
        cost_scaling[347] = 0.25;
        cost_scaling[348] = 0.25;
        cost_scaling[349] = 0.25;
        cost_scaling[350] = 0.25;
        cost_scaling[351] = 0.25;
        cost_scaling[352] = 0.25;
        cost_scaling[353] = 0.25;
        cost_scaling[354] = 0.25;
        cost_scaling[355] = 0.25;
        cost_scaling[356] = 0.25;
        cost_scaling[357] = 0.25;
        cost_scaling[358] = 0.25;
        cost_scaling[359] = 0.25;
        cost_scaling[360] = 0.25;
        cost_scaling[361] = 0.25;
        cost_scaling[362] = 0.25;
        cost_scaling[363] = 0.25;
        cost_scaling[364] = 0.25;
        cost_scaling[365] = 0.25;
        cost_scaling[366] = 0.25;
        cost_scaling[367] = 0.25;
        cost_scaling[368] = 0.25;
        cost_scaling[369] = 0.25;
        cost_scaling[370] = 0.25;
        cost_scaling[371] = 0.25;
        cost_scaling[372] = 0.25;
        cost_scaling[373] = 0.25;
        cost_scaling[374] = 0.25;
        cost_scaling[375] = 0.25;
        cost_scaling[376] = 0.25;
        cost_scaling[377] = 0.25;
        cost_scaling[378] = 0.25;
        cost_scaling[379] = 0.25;
        cost_scaling[380] = 0.25;
        cost_scaling[381] = 0.25;
        cost_scaling[382] = 0.25;
        cost_scaling[383] = 0.25;
        cost_scaling[384] = 0.25;
        cost_scaling[385] = 0.25;
        cost_scaling[386] = 0.25;
        cost_scaling[387] = 0.25;
        cost_scaling[388] = 0.25;
        cost_scaling[389] = 0.25;
        cost_scaling[390] = 0.25;
        cost_scaling[391] = 0.25;
        cost_scaling[392] = 0.25;
        cost_scaling[393] = 0.25;
        cost_scaling[394] = 0.25;
        cost_scaling[395] = 0.25;
        cost_scaling[396] = 0.25;
        cost_scaling[397] = 0.25;
        cost_scaling[398] = 0.25;
        cost_scaling[399] = 0.25;
        cost_scaling[400] = 0.25;
        cost_scaling[401] = 0.25;
        cost_scaling[402] = 0.25;
        cost_scaling[403] = 0.25;
        cost_scaling[404] = 0.25;
        cost_scaling[405] = 0.25;
        cost_scaling[406] = 0.25;
        cost_scaling[407] = 0.25;
        cost_scaling[408] = 0.25;
        cost_scaling[409] = 0.25;
        cost_scaling[410] = 0.25;
        cost_scaling[411] = 0.25;
        cost_scaling[412] = 0.25;
        cost_scaling[413] = 0.25;
        cost_scaling[414] = 0.25;
        cost_scaling[415] = 0.25;
        cost_scaling[416] = 0.25;
        cost_scaling[417] = 0.25;
        cost_scaling[418] = 0.25;
        cost_scaling[419] = 0.25;
        cost_scaling[420] = 0.25;
        cost_scaling[421] = 0.25;
        cost_scaling[422] = 0.25;
        cost_scaling[423] = 0.25;
        cost_scaling[424] = 0.25;
        cost_scaling[425] = 0.25;
        cost_scaling[426] = 0.25;
        cost_scaling[427] = 0.25;
        cost_scaling[428] = 0.25;
        cost_scaling[429] = 0.25;
        cost_scaling[430] = 0.25;
        cost_scaling[431] = 0.25;
        cost_scaling[432] = 0.25;
        cost_scaling[433] = 0.25;
        cost_scaling[434] = 0.25;
        cost_scaling[435] = 0.25;
        cost_scaling[436] = 0.25;
        cost_scaling[437] = 0.25;
        cost_scaling[438] = 0.25;
        cost_scaling[439] = 0.25;
        cost_scaling[440] = 0.25;
        cost_scaling[441] = 0.25;
        cost_scaling[442] = 0.25;
        cost_scaling[443] = 0.25;
        cost_scaling[444] = 0.25;
        cost_scaling[445] = 0.25;
        cost_scaling[446] = 0.25;
        cost_scaling[447] = 0.25;
        cost_scaling[448] = 0.25;
        cost_scaling[449] = 0.25;
        cost_scaling[450] = 0.25;
        cost_scaling[451] = 0.25;
        cost_scaling[452] = 0.25;
        cost_scaling[453] = 0.25;
        cost_scaling[454] = 0.25;
        cost_scaling[455] = 0.25;
        cost_scaling[456] = 0.25;
        cost_scaling[457] = 0.25;
        cost_scaling[458] = 0.25;
        cost_scaling[459] = 0.25;
        cost_scaling[460] = 0.25;
        cost_scaling[461] = 0.25;
        cost_scaling[462] = 0.25;
        cost_scaling[463] = 0.25;
        cost_scaling[464] = 0.25;
        cost_scaling[465] = 0.25;
        cost_scaling[466] = 0.25;
        cost_scaling[467] = 0.25;
        cost_scaling[468] = 0.25;
        cost_scaling[469] = 0.25;
        cost_scaling[470] = 0.25;
        cost_scaling[471] = 0.25;
        cost_scaling[472] = 0.25;
        cost_scaling[473] = 0.25;
        cost_scaling[474] = 0.25;
        cost_scaling[475] = 0.25;
        cost_scaling[476] = 0.25;
        cost_scaling[477] = 0.25;
        cost_scaling[478] = 0.25;
        cost_scaling[479] = 0.25;
        cost_scaling[480] = 0.25;
        cost_scaling[481] = 0.25;
        cost_scaling[482] = 0.25;
        cost_scaling[483] = 0.25;
        cost_scaling[484] = 0.25;
        cost_scaling[485] = 0.25;
        cost_scaling[486] = 0.25;
        cost_scaling[487] = 0.25;
        cost_scaling[488] = 0.25;
        cost_scaling[489] = 0.25;
        cost_scaling[490] = 0.25;
        cost_scaling[491] = 0.25;
        cost_scaling[492] = 0.25;
        cost_scaling[493] = 0.25;
        cost_scaling[494] = 0.25;
        cost_scaling[495] = 0.25;
        cost_scaling[496] = 0.25;
        cost_scaling[497] = 0.25;
        cost_scaling[498] = 0.25;
        cost_scaling[499] = 0.25;
        cost_scaling[500] = 1;
        for (int i = 0; i <= N; i++)
        {
            ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, i, "scaling", &cost_scaling[i]);
        }
        free(cost_scaling);
    }


    /**** Dynamics ****/
    for (int i = 0; i < N; i++)
    {
        ocp_nlp_dynamics_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "disc_dyn_fun", &capsule->discr_dyn_phi_fun[i]);
        ocp_nlp_dynamics_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "disc_dyn_fun_jac",
                                   &capsule->discr_dyn_phi_fun_jac_ut_xt[i]);
        
        
    }

    /**** Cost ****/
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, 0, "ext_cost_fun", &capsule->ext_cost_0_fun);
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, 0, "ext_cost_fun_jac", &capsule->ext_cost_0_fun_jac);
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, 0, "ext_cost_fun_jac_hess", &capsule->ext_cost_0_fun_jac_hess);
    
    
    for (int i = 1; i < N; i++)
    {
        ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "ext_cost_fun", &capsule->ext_cost_fun[i-1]);
        ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "ext_cost_fun_jac", &capsule->ext_cost_fun_jac[i-1]);
        ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "ext_cost_fun_jac_hess", &capsule->ext_cost_fun_jac_hess[i-1]);
        
        
    }
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, N, "ext_cost_fun", &capsule->ext_cost_e_fun);
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, N, "ext_cost_fun_jac", &capsule->ext_cost_e_fun_jac);
    ocp_nlp_cost_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, N, "ext_cost_fun_jac_hess", &capsule->ext_cost_e_fun_jac_hess);
    
    






    /**** Constraints ****/

    // bounds for initial stage
    // x0
    int* idxbx0 = malloc(NBX0 * sizeof(int));
    idxbx0[0] = 0;
    idxbx0[1] = 1;
    idxbx0[2] = 2;
    idxbx0[3] = 3;
    idxbx0[4] = 4;

    double* lubx0 = calloc(2*NBX0, sizeof(double));
    double* lbx0 = lubx0;
    double* ubx0 = lubx0 + NBX0;
    // change only the non-zero elements:
    lbx0[0] = 10;
    ubx0[0] = 10;
    lbx0[1] = 50;
    ubx0[1] = 50;

    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "idxbx", idxbx0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lbx", lbx0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ubx", ubx0);
    free(idxbx0);
    free(lubx0);








    /* constraints that are the same for initial and intermediate */
    // u
    int* idxbu = malloc(NBU * sizeof(int));
    idxbu[0] = 0;
    idxbu[1] = 1;
    double* lubu = calloc(2*NBU, sizeof(double));
    double* lbu = lubu;
    double* ubu = lubu + NBU;
    lbu[0] = -1;
    ubu[0] = 1;
    lbu[1] = -0.5235987755982988;
    ubu[1] = 0.5235987755982988;

    for (int i = 0; i < N; i++)
    {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "idxbu", idxbu);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "lbu", lbu);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "ubu", ubu);
    }
    free(idxbu);
    free(lubu);








    // x
    int* idxbx = malloc(NBX * sizeof(int));
    idxbx[0] = 0;
    idxbx[1] = 1;
    idxbx[2] = 3;
    idxbx[3] = 4;
    double* lubx = calloc(2*NBX, sizeof(double));
    double* lbx = lubx;
    double* ubx = lubx + NBX;
    ubx[0] = 150;
    ubx[1] = 100;
    lbx[2] = -4.166666666666667;
    ubx[2] = 4.166666666666667;
    lbx[3] = -0.5235987755982988;
    ubx[3] = 0.5235987755982988;

    for (int i = 1; i < N; i++)
    {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "idxbx", idxbx);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "lbx", lbx);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "ubx", ubx);
    }
    free(idxbx);
    free(lubx);




    // set up nonlinear constraints for stage 1 to N-1
    double* luh = calloc(2*NH, sizeof(double));
    double* lh = luh;
    double* uh = luh + NH;
    uh[0] = 10000;

    for (int i = 1; i < N; i++)
    {
        ocp_nlp_constraints_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "nl_constr_h_fun_jac",
                                      &capsule->nl_constr_h_fun_jac[i-1]);
        ocp_nlp_constraints_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, i, "nl_constr_h_fun",
                                      &capsule->nl_constr_h_fun[i-1]);
        
        
        
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "lh", lh);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, i, "uh", uh);
    }
    free(luh);



    /* terminal constraints */

    // set up bounds for last stage
    // x
    int* idxbx_e = malloc(NBXN * sizeof(int));
    idxbx_e[0] = 3;
    idxbx_e[1] = 4;
    double* lubx_e = calloc(2*NBXN, sizeof(double));
    double* lbx_e = lubx_e;
    double* ubx_e = lubx_e + NBXN;
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, N, "idxbx", idxbx_e);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, N, "lbx", lbx_e);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, N, "ubx", ubx_e);
    free(idxbx_e);
    free(lubx_e);












    // set up nonlinear constraints for last stage
    double* luh_e = calloc(2*NHN, sizeof(double));
    double* lh_e = luh_e;
    double* uh_e = luh_e + NHN;
    uh_e[0] = 10000;

    ocp_nlp_constraints_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, N, "nl_constr_h_fun_jac", &capsule->nl_constr_h_e_fun_jac);
    ocp_nlp_constraints_model_set_external_param_fun(nlp_config, nlp_dims, nlp_in, N, "nl_constr_h_fun", &capsule->nl_constr_h_e_fun);
    
    
    
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, N, "lh", lh_e);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, N, "uh", uh_e);
    free(luh_e);
}


static void PathPlanning_acados_create_set_opts(PathPlanning_solver_capsule* capsule)
{
    const int N = capsule->nlp_solver_plan->N;
    ocp_nlp_config* nlp_config = capsule->nlp_config;
    void *nlp_opts = capsule->nlp_opts;

    /************************************************
    *  opts
    ************************************************/



    int fixed_hess = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "fixed_hess", &fixed_hess);

    double globalization_fixed_step_length = 1;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "globalization_fixed_step_length", &globalization_fixed_step_length);




    int with_solution_sens_wrt_params = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "with_solution_sens_wrt_params", &with_solution_sens_wrt_params);

    int with_value_sens_wrt_params = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "with_value_sens_wrt_params", &with_value_sens_wrt_params);

    int globalization_full_step_dual = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "globalization_full_step_dual", &globalization_full_step_dual);

    double levenberg_marquardt = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "levenberg_marquardt", &levenberg_marquardt);

    /* options QP solver */
    int qp_solver_cond_N;const int qp_solver_cond_N_ori = 5;
    qp_solver_cond_N = N < qp_solver_cond_N_ori ? N : qp_solver_cond_N_ori; // use the minimum value here
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "qp_cond_N", &qp_solver_cond_N);

    int nlp_solver_ext_qp_res = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "ext_qp_res", &nlp_solver_ext_qp_res);

    bool store_iterates = false;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "store_iterates", &store_iterates);
    int log_primal_step_norm = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "log_primal_step_norm", &log_primal_step_norm);

    double nlp_solver_tol_min_step_norm = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "tol_min_step_norm", &nlp_solver_tol_min_step_norm);
    // set HPIPM mode: should be done before setting other QP solver options
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "qp_hpipm_mode", "BALANCE");




    // set SQP specific options
    double nlp_solver_tol_stat = 0.01;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "tol_stat", &nlp_solver_tol_stat);

    double nlp_solver_tol_eq = 0.01;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "tol_eq", &nlp_solver_tol_eq);

    double nlp_solver_tol_ineq = 0.01;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "tol_ineq", &nlp_solver_tol_ineq);

    double nlp_solver_tol_comp = 0.01;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "tol_comp", &nlp_solver_tol_comp);

    int nlp_solver_max_iter = 500;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "max_iter", &nlp_solver_max_iter);

    // set options for adaptive Levenberg-Marquardt Update
    bool with_adaptive_levenberg_marquardt = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "with_adaptive_levenberg_marquardt", &with_adaptive_levenberg_marquardt);

    double adaptive_levenberg_marquardt_lam = 5;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "adaptive_levenberg_marquardt_lam", &adaptive_levenberg_marquardt_lam);

    double adaptive_levenberg_marquardt_mu_min = 0.0000000000000001;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "adaptive_levenberg_marquardt_mu_min", &adaptive_levenberg_marquardt_mu_min);

    double adaptive_levenberg_marquardt_mu0 = 0.001;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "adaptive_levenberg_marquardt_mu0", &adaptive_levenberg_marquardt_mu0);

    bool eval_residual_at_max_iter = false;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "eval_residual_at_max_iter", &eval_residual_at_max_iter);

    int qp_solver_iter_max = 50;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "qp_iter_max", &qp_solver_iter_max);



    int print_level = 0;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "print_level", &print_level);
    int qp_solver_cond_ric_alg = 1;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "qp_cond_ric_alg", &qp_solver_cond_ric_alg);

    int qp_solver_ric_alg = 1;
    ocp_nlp_solver_opts_set(nlp_config, nlp_opts, "qp_ric_alg", &qp_solver_ric_alg);


    int ext_cost_num_hess = 0;
    for (int i = 0; i < N; i++)
    {
        ocp_nlp_solver_opts_set_at_stage(nlp_config, nlp_opts, i, "cost_numerical_hessian", &ext_cost_num_hess);
    }
    ocp_nlp_solver_opts_set_at_stage(nlp_config, nlp_opts, N, "cost_numerical_hessian", &ext_cost_num_hess);
}


/**
 * Internal function for PathPlanning_acados_create: step 7
 */
void PathPlanning_acados_set_nlp_out(PathPlanning_solver_capsule* capsule)
{
    const int N = capsule->nlp_solver_plan->N;
    ocp_nlp_config* nlp_config = capsule->nlp_config;
    ocp_nlp_dims* nlp_dims = capsule->nlp_dims;
    ocp_nlp_out* nlp_out = capsule->nlp_out;

    // initialize primal solution
    double* xu0 = calloc(NX+NU, sizeof(double));
    double* x0 = xu0;

    // initialize with x0
    x0[0] = 10;
    x0[1] = 50;


    double* u0 = xu0 + NX;

    for (int i = 0; i < N; i++)
    {
        // x0
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "x", x0);
        // u0
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "u", u0);
    }
    ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, N, "x", x0);
    free(xu0);
}


/**
 * Internal function for PathPlanning_acados_create: step 9
 */
int PathPlanning_acados_create_precompute(PathPlanning_solver_capsule* capsule) {
    int status = ocp_nlp_precompute(capsule->nlp_solver, capsule->nlp_in, capsule->nlp_out);

    if (status != ACADOS_SUCCESS) {
        printf("\nocp_nlp_precompute failed!\n\n");
        exit(1);
    }

    return status;
}


int PathPlanning_acados_create_with_discretization(PathPlanning_solver_capsule* capsule, int N, double* new_time_steps)
{
    // If N does not match the number of shooting intervals used for code generation, new_time_steps must be given.
    if (N != PATHPLANNING_N && !new_time_steps) {
        fprintf(stderr, "PathPlanning_acados_create_with_discretization: new_time_steps is NULL " \
            "but the number of shooting intervals (= %d) differs from the number of " \
            "shooting intervals (= %d) during code generation! Please provide a new vector of time_stamps!\n", \
             N, PATHPLANNING_N);
        return 1;
    }

    // number of expected runtime parameters
    capsule->nlp_np = NP;

    // 1) create and set nlp_solver_plan; create nlp_config
    capsule->nlp_solver_plan = ocp_nlp_plan_create(N);
    PathPlanning_acados_create_set_plan(capsule->nlp_solver_plan, N);
    capsule->nlp_config = ocp_nlp_config_create(*capsule->nlp_solver_plan);

    // 2) create and set dimensions
    capsule->nlp_dims = PathPlanning_acados_create_setup_dimensions(capsule);

    // 3) create and set nlp_opts
    capsule->nlp_opts = ocp_nlp_solver_opts_create(capsule->nlp_config, capsule->nlp_dims);
    PathPlanning_acados_create_set_opts(capsule);

    // 4) create nlp_in
    capsule->nlp_in = ocp_nlp_in_create(capsule->nlp_config, capsule->nlp_dims);

    // 5) setup functions, nlp_in and default parameters
    PathPlanning_acados_create_setup_functions(capsule);
    PathPlanning_acados_setup_nlp_in(capsule, N, new_time_steps);
    PathPlanning_acados_create_set_default_parameters(capsule);

    // 6) create solver
    capsule->nlp_solver = ocp_nlp_solver_create(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_opts, capsule->nlp_in);

    // 7) create and set nlp_out
    // 7.1) nlp_out
    capsule->nlp_out = ocp_nlp_out_create(capsule->nlp_config, capsule->nlp_dims);
    // 7.2) sens_out
    capsule->sens_out = ocp_nlp_out_create(capsule->nlp_config, capsule->nlp_dims);
    PathPlanning_acados_set_nlp_out(capsule);

    // 8) do precomputations
    int status = PathPlanning_acados_create_precompute(capsule);

    return status;
}

/**
 * This function is for updating an already initialized solver with a different number of qp_cond_N. It is useful for code reuse after code export.
 */
int PathPlanning_acados_update_qp_solver_cond_N(PathPlanning_solver_capsule* capsule, int qp_solver_cond_N)
{
    // 1) destroy solver
    ocp_nlp_solver_destroy(capsule->nlp_solver);

    // 2) set new value for "qp_cond_N"
    const int N = capsule->nlp_solver_plan->N;
    if(qp_solver_cond_N > N)
        printf("Warning: qp_solver_cond_N = %d > N = %d\n", qp_solver_cond_N, N);
    ocp_nlp_solver_opts_set(capsule->nlp_config, capsule->nlp_opts, "qp_cond_N", &qp_solver_cond_N);

    // 3) continue with the remaining steps from PathPlanning_acados_create_with_discretization(...):
    // -> 8) create solver
    capsule->nlp_solver = ocp_nlp_solver_create(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_opts, capsule->nlp_in);

    // -> 9) do precomputations
    int status = PathPlanning_acados_create_precompute(capsule);
    return status;
}


int PathPlanning_acados_reset(PathPlanning_solver_capsule* capsule, int reset_qp_solver_mem)
{

    // set initialization to all zeros

    const int N = capsule->nlp_solver_plan->N;
    ocp_nlp_config* nlp_config = capsule->nlp_config;
    ocp_nlp_dims* nlp_dims = capsule->nlp_dims;
    ocp_nlp_out* nlp_out = capsule->nlp_out;
    ocp_nlp_in* nlp_in = capsule->nlp_in;
    ocp_nlp_solver* nlp_solver = capsule->nlp_solver;

    double* buffer = calloc(NX+NU+NZ+2*NS+2*NSN+2*NS0+NBX+NBU+NG+NH+NPHI+NBX0+NBXN+NHN+NH0+NPHIN+NGN, sizeof(double));

    for(int i=0; i<N+1; i++)
    {
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "x", buffer);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "u", buffer);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "sl", buffer);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "su", buffer);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "lam", buffer);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "z", buffer);
        if (i<N)
        {
            ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "pi", buffer);
        }
    }
    // get qp_status: if NaN -> reset memory
    int qp_status;
    ocp_nlp_get(capsule->nlp_solver, "qp_status", &qp_status);
    if (reset_qp_solver_mem || (qp_status == 3))
    {
        // printf("\nin reset qp_status %d -> resetting QP memory\n", qp_status);
        ocp_nlp_solver_reset_qp_memory(nlp_solver, nlp_in, nlp_out);
    }

    free(buffer);
    return 0;
}




int PathPlanning_acados_update_params(PathPlanning_solver_capsule* capsule, int stage, double *p, int np)
{
    int solver_status = 0;

    int casadi_np = 0;
    if (casadi_np != np) {
        printf("acados_update_params: trying to set %i parameters for external functions."
            " External function has %i parameters. Exiting.\n", np, casadi_np);
        exit(1);
    }
    ocp_nlp_in_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, stage, "parameter_values", p);

    return solver_status;
}


int PathPlanning_acados_update_params_sparse(PathPlanning_solver_capsule * capsule, int stage, int *idx, double *p, int n_update)
{
    ocp_nlp_in_set_params_sparse(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, stage, idx, p, n_update);

    return 0;
}


int PathPlanning_acados_set_p_global_and_precompute_dependencies(PathPlanning_solver_capsule* capsule, double* data, int data_len)
{

    printf("p_global is not defined, PathPlanning_acados_set_p_global_and_precompute_dependencies does nothing.\n");
}




int PathPlanning_acados_solve(PathPlanning_solver_capsule* capsule)
{
    // solve NLP
    int solver_status = ocp_nlp_solve(capsule->nlp_solver, capsule->nlp_in, capsule->nlp_out);

    return solver_status;
}


void PathPlanning_acados_batch_solve(PathPlanning_solver_capsule ** capsules, int N_batch)
{

    for (int i = 0; i < N_batch; i++)
    {
        ocp_nlp_solve(capsules[i]->nlp_solver, capsules[i]->nlp_in, capsules[i]->nlp_out);
    }


    return;
}


void PathPlanning_acados_batch_eval_params_jac(PathPlanning_solver_capsule ** capsules, int N_batch)
{

    for (int i = 0; i < N_batch; i++)
    {
        ocp_nlp_eval_params_jac(capsules[i]->nlp_solver, capsules[i]->nlp_in, capsules[i]->nlp_out);
    }


    return;
}



void PathPlanning_acados_batch_eval_solution_sens_adj_p(PathPlanning_solver_capsule ** capsules, const char *field, int stage, double *out, int offset, int N_batch)
{


    for (int i = 0; i < N_batch; i++)
    {
        ocp_nlp_eval_solution_sens_adj_p(capsules[i]->nlp_solver, capsules[i]->nlp_in, capsules[i]->sens_out, field, stage, out + i*offset);
    }


    return;
}


void PathPlanning_acados_batch_set_flat(PathPlanning_solver_capsule ** capsules, const char *field, double *data, int N_data, int N_batch)
{
    int offset = ocp_nlp_dims_get_total_from_attr(capsules[0]->nlp_solver->config, capsules[0]->nlp_solver->dims, field);

    if (N_batch*offset != N_data)
    {
        printf("batch_set_flat: wrong input dimension, expected %d, got %d\n", N_batch*offset, N_data);
        exit(1);
    }


    for (int i = 0; i < N_batch; i++)
    {
        ocp_nlp_set_all(capsules[i]->nlp_solver, capsules[i]->nlp_in, capsules[i]->nlp_out, field, data + i * offset);
    }


    return;
}



void PathPlanning_acados_batch_get_flat(PathPlanning_solver_capsule ** capsules, const char *field, double *data, int N_data, int N_batch)
{
    int offset = ocp_nlp_dims_get_total_from_attr(capsules[0]->nlp_solver->config, capsules[0]->nlp_solver->dims, field);

    if (N_batch*offset != N_data)
    {
        printf("batch_get_flat: wrong input dimension, expected %d, got %d\n", N_batch*offset, N_data);
        exit(1);
    }


    for (int i = 0; i < N_batch; i++)
    {
        ocp_nlp_get_all(capsules[i]->nlp_solver, capsules[i]->nlp_in, capsules[i]->nlp_out, field, data + i * offset);
    }


    return;
}


int PathPlanning_acados_free(PathPlanning_solver_capsule* capsule)
{
    // before destroying, keep some info
    const int N = capsule->nlp_solver_plan->N;
    // free memory
    ocp_nlp_solver_opts_destroy(capsule->nlp_opts);
    ocp_nlp_in_destroy(capsule->nlp_in);
    ocp_nlp_out_destroy(capsule->nlp_out);
    ocp_nlp_out_destroy(capsule->sens_out);
    ocp_nlp_solver_destroy(capsule->nlp_solver);
    ocp_nlp_dims_destroy(capsule->nlp_dims);
    ocp_nlp_config_destroy(capsule->nlp_config);
    ocp_nlp_plan_destroy(capsule->nlp_solver_plan);

    /* free external function */
    // dynamics
    for (int i = 0; i < N; i++)
    {
        external_function_external_param_casadi_free(&capsule->discr_dyn_phi_fun[i]);
        external_function_external_param_casadi_free(&capsule->discr_dyn_phi_fun_jac_ut_xt[i]);
        
        
    }
    free(capsule->discr_dyn_phi_fun);
    free(capsule->discr_dyn_phi_fun_jac_ut_xt);
  
  

    // cost
    external_function_external_param_casadi_free(&capsule->ext_cost_0_fun);
    external_function_external_param_casadi_free(&capsule->ext_cost_0_fun_jac);
    external_function_external_param_casadi_free(&capsule->ext_cost_0_fun_jac_hess);
    
    
    for (int i = 0; i < N - 1; i++)
    {
        external_function_external_param_casadi_free(&capsule->ext_cost_fun[i]);
        external_function_external_param_casadi_free(&capsule->ext_cost_fun_jac[i]);
        external_function_external_param_casadi_free(&capsule->ext_cost_fun_jac_hess[i]);
        
        
    }
    free(capsule->ext_cost_fun);
    free(capsule->ext_cost_fun_jac);
    free(capsule->ext_cost_fun_jac_hess);
    external_function_external_param_casadi_free(&capsule->ext_cost_e_fun);
    external_function_external_param_casadi_free(&capsule->ext_cost_e_fun_jac);
    external_function_external_param_casadi_free(&capsule->ext_cost_e_fun_jac_hess);
    
    

    // constraints
    for (int i = 0; i < N-1; i++)
    {
        external_function_external_param_casadi_free(&capsule->nl_constr_h_fun_jac[i]);
        external_function_external_param_casadi_free(&capsule->nl_constr_h_fun[i]);
    }
    free(capsule->nl_constr_h_fun_jac);
    free(capsule->nl_constr_h_fun);
    external_function_external_param_casadi_free(&capsule->nl_constr_h_e_fun_jac);
    external_function_external_param_casadi_free(&capsule->nl_constr_h_e_fun);



    return 0;
}


void PathPlanning_acados_print_stats(PathPlanning_solver_capsule* capsule)
{
    int nlp_iter, stat_m, stat_n, tmp_int;
    ocp_nlp_get(capsule->nlp_solver, "nlp_iter", &nlp_iter);
    ocp_nlp_get(capsule->nlp_solver, "stat_n", &stat_n);
    ocp_nlp_get(capsule->nlp_solver, "stat_m", &stat_m);


    double stat[6000];
    ocp_nlp_get(capsule->nlp_solver, "statistics", stat);

    int nrow = nlp_iter+1 < stat_m ? nlp_iter+1 : stat_m;


    printf("iter\tres_stat\tres_eq\t\tres_ineq\tres_comp\tqp_stat\tqp_iter\talpha");
    if (stat_n > 8)
        printf("\t\tqp_res_stat\tqp_res_eq\tqp_res_ineq\tqp_res_comp");
    printf("\n");
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < stat_n + 1; j++)
        {
            if (j == 0 || j == 5 || j == 6)
            {
                tmp_int = (int) stat[i + j * nrow];
                printf("%d\t", tmp_int);
            }
            else
            {
                printf("%e\t", stat[i + j * nrow]);
            }
        }
        printf("\n");
    }
}

int PathPlanning_acados_custom_update(PathPlanning_solver_capsule* capsule, double* data, int data_len)
{
    (void)capsule;
    (void)data;
    (void)data_len;
    printf("\ndummy function that can be called in between solver calls to update parameters or numerical data efficiently in C.\n");
    printf("nothing set yet..\n");
    return 1;

}



ocp_nlp_in *PathPlanning_acados_get_nlp_in(PathPlanning_solver_capsule* capsule) { return capsule->nlp_in; }
ocp_nlp_out *PathPlanning_acados_get_nlp_out(PathPlanning_solver_capsule* capsule) { return capsule->nlp_out; }
ocp_nlp_out *PathPlanning_acados_get_sens_out(PathPlanning_solver_capsule* capsule) { return capsule->sens_out; }
ocp_nlp_solver *PathPlanning_acados_get_nlp_solver(PathPlanning_solver_capsule* capsule) { return capsule->nlp_solver; }
ocp_nlp_config *PathPlanning_acados_get_nlp_config(PathPlanning_solver_capsule* capsule) { return capsule->nlp_config; }
void *PathPlanning_acados_get_nlp_opts(PathPlanning_solver_capsule* capsule) { return capsule->nlp_opts; }
ocp_nlp_dims *PathPlanning_acados_get_nlp_dims(PathPlanning_solver_capsule* capsule) { return capsule->nlp_dims; }
ocp_nlp_plan_t *PathPlanning_acados_get_nlp_plan(PathPlanning_solver_capsule* capsule) { return capsule->nlp_solver_plan; }
