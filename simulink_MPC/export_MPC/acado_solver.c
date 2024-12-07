/*
 *    This file was auto-generated using the ACADO Toolkit.
 *    
 *    While ACADO Toolkit is free software released under the terms of
 *    the GNU Lesser General Public License (LGPL), the generated code
 *    as such remains the property of the user who used ACADO Toolkit
 *    to generate this code. In particular, user dependent data of the code
 *    do not inherit the GNU LGPL license. On the other hand, parts of the
 *    generated code that are a direct copy of source code from the
 *    ACADO Toolkit or the software tools it is based on, remain, as derived
 *    work, automatically covered by the LGPL license.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    
 */


#include "acado_common.h"




/******************************************************************************/
/*                                                                            */
/* ACADO code generation                                                      */
/*                                                                            */
/******************************************************************************/


int acado_modelSimulation(  )
{
int ret;

int lRun1;
ret = 0;
for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
acadoWorkspace.state[0] = acadoVariables.x[lRun1 * 6];
acadoWorkspace.state[1] = acadoVariables.x[lRun1 * 6 + 1];
acadoWorkspace.state[2] = acadoVariables.x[lRun1 * 6 + 2];
acadoWorkspace.state[3] = acadoVariables.x[lRun1 * 6 + 3];
acadoWorkspace.state[4] = acadoVariables.x[lRun1 * 6 + 4];
acadoWorkspace.state[5] = acadoVariables.x[lRun1 * 6 + 5];

acadoWorkspace.state[54] = acadoVariables.u[lRun1 * 2];
acadoWorkspace.state[55] = acadoVariables.u[lRun1 * 2 + 1];
acadoWorkspace.state[56] = acadoVariables.od[lRun1 * 3];
acadoWorkspace.state[57] = acadoVariables.od[lRun1 * 3 + 1];
acadoWorkspace.state[58] = acadoVariables.od[lRun1 * 3 + 2];

ret = acado_integrate(acadoWorkspace.state, 1);

acadoWorkspace.d[lRun1 * 6] = acadoWorkspace.state[0] - acadoVariables.x[lRun1 * 6 + 6];
acadoWorkspace.d[lRun1 * 6 + 1] = acadoWorkspace.state[1] - acadoVariables.x[lRun1 * 6 + 7];
acadoWorkspace.d[lRun1 * 6 + 2] = acadoWorkspace.state[2] - acadoVariables.x[lRun1 * 6 + 8];
acadoWorkspace.d[lRun1 * 6 + 3] = acadoWorkspace.state[3] - acadoVariables.x[lRun1 * 6 + 9];
acadoWorkspace.d[lRun1 * 6 + 4] = acadoWorkspace.state[4] - acadoVariables.x[lRun1 * 6 + 10];
acadoWorkspace.d[lRun1 * 6 + 5] = acadoWorkspace.state[5] - acadoVariables.x[lRun1 * 6 + 11];

acadoWorkspace.evGx[lRun1 * 36] = acadoWorkspace.state[6];
acadoWorkspace.evGx[lRun1 * 36 + 1] = acadoWorkspace.state[7];
acadoWorkspace.evGx[lRun1 * 36 + 2] = acadoWorkspace.state[8];
acadoWorkspace.evGx[lRun1 * 36 + 3] = acadoWorkspace.state[9];
acadoWorkspace.evGx[lRun1 * 36 + 4] = acadoWorkspace.state[10];
acadoWorkspace.evGx[lRun1 * 36 + 5] = acadoWorkspace.state[11];
acadoWorkspace.evGx[lRun1 * 36 + 6] = acadoWorkspace.state[12];
acadoWorkspace.evGx[lRun1 * 36 + 7] = acadoWorkspace.state[13];
acadoWorkspace.evGx[lRun1 * 36 + 8] = acadoWorkspace.state[14];
acadoWorkspace.evGx[lRun1 * 36 + 9] = acadoWorkspace.state[15];
acadoWorkspace.evGx[lRun1 * 36 + 10] = acadoWorkspace.state[16];
acadoWorkspace.evGx[lRun1 * 36 + 11] = acadoWorkspace.state[17];
acadoWorkspace.evGx[lRun1 * 36 + 12] = acadoWorkspace.state[18];
acadoWorkspace.evGx[lRun1 * 36 + 13] = acadoWorkspace.state[19];
acadoWorkspace.evGx[lRun1 * 36 + 14] = acadoWorkspace.state[20];
acadoWorkspace.evGx[lRun1 * 36 + 15] = acadoWorkspace.state[21];
acadoWorkspace.evGx[lRun1 * 36 + 16] = acadoWorkspace.state[22];
acadoWorkspace.evGx[lRun1 * 36 + 17] = acadoWorkspace.state[23];
acadoWorkspace.evGx[lRun1 * 36 + 18] = acadoWorkspace.state[24];
acadoWorkspace.evGx[lRun1 * 36 + 19] = acadoWorkspace.state[25];
acadoWorkspace.evGx[lRun1 * 36 + 20] = acadoWorkspace.state[26];
acadoWorkspace.evGx[lRun1 * 36 + 21] = acadoWorkspace.state[27];
acadoWorkspace.evGx[lRun1 * 36 + 22] = acadoWorkspace.state[28];
acadoWorkspace.evGx[lRun1 * 36 + 23] = acadoWorkspace.state[29];
acadoWorkspace.evGx[lRun1 * 36 + 24] = acadoWorkspace.state[30];
acadoWorkspace.evGx[lRun1 * 36 + 25] = acadoWorkspace.state[31];
acadoWorkspace.evGx[lRun1 * 36 + 26] = acadoWorkspace.state[32];
acadoWorkspace.evGx[lRun1 * 36 + 27] = acadoWorkspace.state[33];
acadoWorkspace.evGx[lRun1 * 36 + 28] = acadoWorkspace.state[34];
acadoWorkspace.evGx[lRun1 * 36 + 29] = acadoWorkspace.state[35];
acadoWorkspace.evGx[lRun1 * 36 + 30] = acadoWorkspace.state[36];
acadoWorkspace.evGx[lRun1 * 36 + 31] = acadoWorkspace.state[37];
acadoWorkspace.evGx[lRun1 * 36 + 32] = acadoWorkspace.state[38];
acadoWorkspace.evGx[lRun1 * 36 + 33] = acadoWorkspace.state[39];
acadoWorkspace.evGx[lRun1 * 36 + 34] = acadoWorkspace.state[40];
acadoWorkspace.evGx[lRun1 * 36 + 35] = acadoWorkspace.state[41];

acadoWorkspace.evGu[lRun1 * 12] = acadoWorkspace.state[42];
acadoWorkspace.evGu[lRun1 * 12 + 1] = acadoWorkspace.state[43];
acadoWorkspace.evGu[lRun1 * 12 + 2] = acadoWorkspace.state[44];
acadoWorkspace.evGu[lRun1 * 12 + 3] = acadoWorkspace.state[45];
acadoWorkspace.evGu[lRun1 * 12 + 4] = acadoWorkspace.state[46];
acadoWorkspace.evGu[lRun1 * 12 + 5] = acadoWorkspace.state[47];
acadoWorkspace.evGu[lRun1 * 12 + 6] = acadoWorkspace.state[48];
acadoWorkspace.evGu[lRun1 * 12 + 7] = acadoWorkspace.state[49];
acadoWorkspace.evGu[lRun1 * 12 + 8] = acadoWorkspace.state[50];
acadoWorkspace.evGu[lRun1 * 12 + 9] = acadoWorkspace.state[51];
acadoWorkspace.evGu[lRun1 * 12 + 10] = acadoWorkspace.state[52];
acadoWorkspace.evGu[lRun1 * 12 + 11] = acadoWorkspace.state[53];
}
return ret;
}

void acado_evaluateLSQ(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 6;

/* Compute outputs: */
out[0] = xd[0];
out[1] = xd[1];
out[2] = xd[2];
out[3] = xd[3];
out[4] = xd[4];
out[5] = xd[5];
out[6] = u[0];
out[7] = u[1];
}

void acado_evaluateLSQEndTerm(const real_t* in, real_t* out)
{
const real_t* xd = in;

/* Compute outputs: */
out[0] = xd[0];
out[1] = xd[1];
out[2] = xd[2];
out[3] = xd[3];
out[4] = xd[4];
out[5] = xd[5];
}

void acado_evaluatePathConstraints(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* od = in + 8;
const real_t* dx = in + 11;
/* Vector of auxiliary variables; number of elements: 43. */
real_t* a = acadoWorkspace.conAuxVar;

/* Compute intermediate quantities: */
a[0] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[1] = (a[0]*a[0]);
a[2] = ((real_t)(-1.0000000000000000e+00)*a[1]);
a[3] = (a[2]*(real_t)(1.0000000000000000e+00));
a[4] = (a[3]*xd[3]);
a[5] = (real_t)(0.0000000000000000e+00);
a[6] = (real_t)(0.0000000000000000e+00);
a[7] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[8] = (real_t)(0.0000000000000000e+00);
a[9] = (real_t)(0.0000000000000000e+00);
a[10] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[11] = (a[10]*a[10]);
a[12] = ((real_t)(-1.0000000000000000e+00)*a[11]);
a[13] = (a[12]*dx[3]);
a[14] = (real_t)(0.0000000000000000e+00);
a[15] = (real_t)(0.0000000000000000e+00);
a[16] = (real_t)(0.0000000000000000e+00);
a[17] = (real_t)(0.0000000000000000e+00);
a[18] = (real_t)(0.0000000000000000e+00);
a[19] = xd[5];
a[20] = (real_t)(0.0000000000000000e+00);
a[21] = (real_t)(0.0000000000000000e+00);
a[22] = (real_t)(0.0000000000000000e+00);
a[23] = (real_t)(0.0000000000000000e+00);
a[24] = xd[0];
a[25] = (real_t)(0.0000000000000000e+00);
a[26] = (((real_t)(0.0000000000000000e+00)-od[0])+xd[1]);
a[27] = (((real_t)(0.0000000000000000e+00)-od[0])+xd[1]);
a[28] = (a[26]+a[27]);
a[29] = (((real_t)(0.0000000000000000e+00)-od[1])+xd[2]);
a[30] = (((real_t)(0.0000000000000000e+00)-od[1])+xd[2]);
a[31] = (a[29]+a[30]);
a[32] = (real_t)(0.0000000000000000e+00);
a[33] = (real_t)(0.0000000000000000e+00);
a[34] = (real_t)(0.0000000000000000e+00);
a[35] = (real_t)(0.0000000000000000e+00);
a[36] = (real_t)(0.0000000000000000e+00);
a[37] = (real_t)(0.0000000000000000e+00);
a[38] = (real_t)(0.0000000000000000e+00);
a[39] = (real_t)(0.0000000000000000e+00);
a[40] = (real_t)(0.0000000000000000e+00);
a[41] = (real_t)(0.0000000000000000e+00);
a[42] = (real_t)(0.0000000000000000e+00);

/* Compute outputs: */
out[0] = (((real_t)(1.0000000000000000e+00)/xd[0])*xd[3]);
out[1] = (dx[3]/xd[0]);
out[2] = (dx[3]+(xd[5]*xd[0]));
out[3] = ((((((real_t)(0.0000000000000000e+00)-od[0])+xd[1])*(((real_t)(0.0000000000000000e+00)-od[0])+xd[1]))+((((real_t)(0.0000000000000000e+00)-od[1])+xd[2])*(((real_t)(0.0000000000000000e+00)-od[1])+xd[2])))-(od[2]*od[2]));
out[4] = a[4];
out[5] = a[5];
out[6] = a[6];
out[7] = a[7];
out[8] = a[8];
out[9] = a[9];
out[10] = a[13];
out[11] = a[14];
out[12] = a[15];
out[13] = a[16];
out[14] = a[17];
out[15] = a[18];
out[16] = a[19];
out[17] = a[20];
out[18] = a[21];
out[19] = a[22];
out[20] = a[23];
out[21] = a[24];
out[22] = a[25];
out[23] = a[28];
out[24] = a[31];
out[25] = a[32];
out[26] = a[33];
out[27] = a[34];
out[28] = a[35];
out[29] = a[36];
out[30] = a[37];
out[31] = a[38];
out[32] = a[39];
out[33] = a[40];
out[34] = a[41];
out[35] = a[42];
}

void acado_setObjQ1Q2( real_t* const tmpObjS, real_t* const tmpQ1, real_t* const tmpQ2 )
{
tmpQ2[0] = +tmpObjS[0];
tmpQ2[1] = +tmpObjS[1];
tmpQ2[2] = +tmpObjS[2];
tmpQ2[3] = +tmpObjS[3];
tmpQ2[4] = +tmpObjS[4];
tmpQ2[5] = +tmpObjS[5];
tmpQ2[6] = +tmpObjS[6];
tmpQ2[7] = +tmpObjS[7];
tmpQ2[8] = +tmpObjS[8];
tmpQ2[9] = +tmpObjS[9];
tmpQ2[10] = +tmpObjS[10];
tmpQ2[11] = +tmpObjS[11];
tmpQ2[12] = +tmpObjS[12];
tmpQ2[13] = +tmpObjS[13];
tmpQ2[14] = +tmpObjS[14];
tmpQ2[15] = +tmpObjS[15];
tmpQ2[16] = +tmpObjS[16];
tmpQ2[17] = +tmpObjS[17];
tmpQ2[18] = +tmpObjS[18];
tmpQ2[19] = +tmpObjS[19];
tmpQ2[20] = +tmpObjS[20];
tmpQ2[21] = +tmpObjS[21];
tmpQ2[22] = +tmpObjS[22];
tmpQ2[23] = +tmpObjS[23];
tmpQ2[24] = +tmpObjS[24];
tmpQ2[25] = +tmpObjS[25];
tmpQ2[26] = +tmpObjS[26];
tmpQ2[27] = +tmpObjS[27];
tmpQ2[28] = +tmpObjS[28];
tmpQ2[29] = +tmpObjS[29];
tmpQ2[30] = +tmpObjS[30];
tmpQ2[31] = +tmpObjS[31];
tmpQ2[32] = +tmpObjS[32];
tmpQ2[33] = +tmpObjS[33];
tmpQ2[34] = +tmpObjS[34];
tmpQ2[35] = +tmpObjS[35];
tmpQ2[36] = +tmpObjS[36];
tmpQ2[37] = +tmpObjS[37];
tmpQ2[38] = +tmpObjS[38];
tmpQ2[39] = +tmpObjS[39];
tmpQ2[40] = +tmpObjS[40];
tmpQ2[41] = +tmpObjS[41];
tmpQ2[42] = +tmpObjS[42];
tmpQ2[43] = +tmpObjS[43];
tmpQ2[44] = +tmpObjS[44];
tmpQ2[45] = +tmpObjS[45];
tmpQ2[46] = +tmpObjS[46];
tmpQ2[47] = +tmpObjS[47];
tmpQ1[0] = + tmpQ2[0];
tmpQ1[1] = + tmpQ2[1];
tmpQ1[2] = + tmpQ2[2];
tmpQ1[3] = + tmpQ2[3];
tmpQ1[4] = + tmpQ2[4];
tmpQ1[5] = + tmpQ2[5];
tmpQ1[6] = + tmpQ2[8];
tmpQ1[7] = + tmpQ2[9];
tmpQ1[8] = + tmpQ2[10];
tmpQ1[9] = + tmpQ2[11];
tmpQ1[10] = + tmpQ2[12];
tmpQ1[11] = + tmpQ2[13];
tmpQ1[12] = + tmpQ2[16];
tmpQ1[13] = + tmpQ2[17];
tmpQ1[14] = + tmpQ2[18];
tmpQ1[15] = + tmpQ2[19];
tmpQ1[16] = + tmpQ2[20];
tmpQ1[17] = + tmpQ2[21];
tmpQ1[18] = + tmpQ2[24];
tmpQ1[19] = + tmpQ2[25];
tmpQ1[20] = + tmpQ2[26];
tmpQ1[21] = + tmpQ2[27];
tmpQ1[22] = + tmpQ2[28];
tmpQ1[23] = + tmpQ2[29];
tmpQ1[24] = + tmpQ2[32];
tmpQ1[25] = + tmpQ2[33];
tmpQ1[26] = + tmpQ2[34];
tmpQ1[27] = + tmpQ2[35];
tmpQ1[28] = + tmpQ2[36];
tmpQ1[29] = + tmpQ2[37];
tmpQ1[30] = + tmpQ2[40];
tmpQ1[31] = + tmpQ2[41];
tmpQ1[32] = + tmpQ2[42];
tmpQ1[33] = + tmpQ2[43];
tmpQ1[34] = + tmpQ2[44];
tmpQ1[35] = + tmpQ2[45];
}

void acado_setObjR1R2( real_t* const tmpObjS, real_t* const tmpR1, real_t* const tmpR2 )
{
tmpR2[0] = +tmpObjS[48];
tmpR2[1] = +tmpObjS[49];
tmpR2[2] = +tmpObjS[50];
tmpR2[3] = +tmpObjS[51];
tmpR2[4] = +tmpObjS[52];
tmpR2[5] = +tmpObjS[53];
tmpR2[6] = +tmpObjS[54];
tmpR2[7] = +tmpObjS[55];
tmpR2[8] = +tmpObjS[56];
tmpR2[9] = +tmpObjS[57];
tmpR2[10] = +tmpObjS[58];
tmpR2[11] = +tmpObjS[59];
tmpR2[12] = +tmpObjS[60];
tmpR2[13] = +tmpObjS[61];
tmpR2[14] = +tmpObjS[62];
tmpR2[15] = +tmpObjS[63];
tmpR1[0] = + tmpR2[6];
tmpR1[1] = + tmpR2[7];
tmpR1[2] = + tmpR2[14];
tmpR1[3] = + tmpR2[15];
}

void acado_setObjQN1QN2( real_t* const tmpObjSEndTerm, real_t* const tmpQN1, real_t* const tmpQN2 )
{
tmpQN2[0] = +tmpObjSEndTerm[0];
tmpQN2[1] = +tmpObjSEndTerm[1];
tmpQN2[2] = +tmpObjSEndTerm[2];
tmpQN2[3] = +tmpObjSEndTerm[3];
tmpQN2[4] = +tmpObjSEndTerm[4];
tmpQN2[5] = +tmpObjSEndTerm[5];
tmpQN2[6] = +tmpObjSEndTerm[6];
tmpQN2[7] = +tmpObjSEndTerm[7];
tmpQN2[8] = +tmpObjSEndTerm[8];
tmpQN2[9] = +tmpObjSEndTerm[9];
tmpQN2[10] = +tmpObjSEndTerm[10];
tmpQN2[11] = +tmpObjSEndTerm[11];
tmpQN2[12] = +tmpObjSEndTerm[12];
tmpQN2[13] = +tmpObjSEndTerm[13];
tmpQN2[14] = +tmpObjSEndTerm[14];
tmpQN2[15] = +tmpObjSEndTerm[15];
tmpQN2[16] = +tmpObjSEndTerm[16];
tmpQN2[17] = +tmpObjSEndTerm[17];
tmpQN2[18] = +tmpObjSEndTerm[18];
tmpQN2[19] = +tmpObjSEndTerm[19];
tmpQN2[20] = +tmpObjSEndTerm[20];
tmpQN2[21] = +tmpObjSEndTerm[21];
tmpQN2[22] = +tmpObjSEndTerm[22];
tmpQN2[23] = +tmpObjSEndTerm[23];
tmpQN2[24] = +tmpObjSEndTerm[24];
tmpQN2[25] = +tmpObjSEndTerm[25];
tmpQN2[26] = +tmpObjSEndTerm[26];
tmpQN2[27] = +tmpObjSEndTerm[27];
tmpQN2[28] = +tmpObjSEndTerm[28];
tmpQN2[29] = +tmpObjSEndTerm[29];
tmpQN2[30] = +tmpObjSEndTerm[30];
tmpQN2[31] = +tmpObjSEndTerm[31];
tmpQN2[32] = +tmpObjSEndTerm[32];
tmpQN2[33] = +tmpObjSEndTerm[33];
tmpQN2[34] = +tmpObjSEndTerm[34];
tmpQN2[35] = +tmpObjSEndTerm[35];
tmpQN1[0] = + tmpQN2[0];
tmpQN1[1] = + tmpQN2[1];
tmpQN1[2] = + tmpQN2[2];
tmpQN1[3] = + tmpQN2[3];
tmpQN1[4] = + tmpQN2[4];
tmpQN1[5] = + tmpQN2[5];
tmpQN1[6] = + tmpQN2[6];
tmpQN1[7] = + tmpQN2[7];
tmpQN1[8] = + tmpQN2[8];
tmpQN1[9] = + tmpQN2[9];
tmpQN1[10] = + tmpQN2[10];
tmpQN1[11] = + tmpQN2[11];
tmpQN1[12] = + tmpQN2[12];
tmpQN1[13] = + tmpQN2[13];
tmpQN1[14] = + tmpQN2[14];
tmpQN1[15] = + tmpQN2[15];
tmpQN1[16] = + tmpQN2[16];
tmpQN1[17] = + tmpQN2[17];
tmpQN1[18] = + tmpQN2[18];
tmpQN1[19] = + tmpQN2[19];
tmpQN1[20] = + tmpQN2[20];
tmpQN1[21] = + tmpQN2[21];
tmpQN1[22] = + tmpQN2[22];
tmpQN1[23] = + tmpQN2[23];
tmpQN1[24] = + tmpQN2[24];
tmpQN1[25] = + tmpQN2[25];
tmpQN1[26] = + tmpQN2[26];
tmpQN1[27] = + tmpQN2[27];
tmpQN1[28] = + tmpQN2[28];
tmpQN1[29] = + tmpQN2[29];
tmpQN1[30] = + tmpQN2[30];
tmpQN1[31] = + tmpQN2[31];
tmpQN1[32] = + tmpQN2[32];
tmpQN1[33] = + tmpQN2[33];
tmpQN1[34] = + tmpQN2[34];
tmpQN1[35] = + tmpQN2[35];
}

void acado_evaluateObjective(  )
{
int runObj;
for (runObj = 0; runObj < 40; ++runObj)
{
acadoWorkspace.objValueIn[0] = acadoVariables.x[runObj * 6];
acadoWorkspace.objValueIn[1] = acadoVariables.x[runObj * 6 + 1];
acadoWorkspace.objValueIn[2] = acadoVariables.x[runObj * 6 + 2];
acadoWorkspace.objValueIn[3] = acadoVariables.x[runObj * 6 + 3];
acadoWorkspace.objValueIn[4] = acadoVariables.x[runObj * 6 + 4];
acadoWorkspace.objValueIn[5] = acadoVariables.x[runObj * 6 + 5];
acadoWorkspace.objValueIn[6] = acadoVariables.u[runObj * 2];
acadoWorkspace.objValueIn[7] = acadoVariables.u[runObj * 2 + 1];
acadoWorkspace.objValueIn[8] = acadoVariables.od[runObj * 3];
acadoWorkspace.objValueIn[9] = acadoVariables.od[runObj * 3 + 1];
acadoWorkspace.objValueIn[10] = acadoVariables.od[runObj * 3 + 2];

acado_evaluateLSQ( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.Dy[runObj * 8] = acadoWorkspace.objValueOut[0];
acadoWorkspace.Dy[runObj * 8 + 1] = acadoWorkspace.objValueOut[1];
acadoWorkspace.Dy[runObj * 8 + 2] = acadoWorkspace.objValueOut[2];
acadoWorkspace.Dy[runObj * 8 + 3] = acadoWorkspace.objValueOut[3];
acadoWorkspace.Dy[runObj * 8 + 4] = acadoWorkspace.objValueOut[4];
acadoWorkspace.Dy[runObj * 8 + 5] = acadoWorkspace.objValueOut[5];
acadoWorkspace.Dy[runObj * 8 + 6] = acadoWorkspace.objValueOut[6];
acadoWorkspace.Dy[runObj * 8 + 7] = acadoWorkspace.objValueOut[7];

acado_setObjQ1Q2( acadoVariables.W, &(acadoWorkspace.Q1[ runObj * 36 ]), &(acadoWorkspace.Q2[ runObj * 48 ]) );

acado_setObjR1R2( acadoVariables.W, &(acadoWorkspace.R1[ runObj * 4 ]), &(acadoWorkspace.R2[ runObj * 16 ]) );

}
acadoWorkspace.objValueIn[0] = acadoVariables.x[240];
acadoWorkspace.objValueIn[1] = acadoVariables.x[241];
acadoWorkspace.objValueIn[2] = acadoVariables.x[242];
acadoWorkspace.objValueIn[3] = acadoVariables.x[243];
acadoWorkspace.objValueIn[4] = acadoVariables.x[244];
acadoWorkspace.objValueIn[5] = acadoVariables.x[245];
acadoWorkspace.objValueIn[6] = acadoVariables.od[120];
acadoWorkspace.objValueIn[7] = acadoVariables.od[121];
acadoWorkspace.objValueIn[8] = acadoVariables.od[122];
acado_evaluateLSQEndTerm( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );

acadoWorkspace.DyN[0] = acadoWorkspace.objValueOut[0];
acadoWorkspace.DyN[1] = acadoWorkspace.objValueOut[1];
acadoWorkspace.DyN[2] = acadoWorkspace.objValueOut[2];
acadoWorkspace.DyN[3] = acadoWorkspace.objValueOut[3];
acadoWorkspace.DyN[4] = acadoWorkspace.objValueOut[4];
acadoWorkspace.DyN[5] = acadoWorkspace.objValueOut[5];

acado_setObjQN1QN2( acadoVariables.WN, acadoWorkspace.QN1, acadoWorkspace.QN2 );

}

void acado_moveGxT( real_t* const Gx1, real_t* const Gx2 )
{
Gx2[0] = Gx1[0];
Gx2[1] = Gx1[1];
Gx2[2] = Gx1[2];
Gx2[3] = Gx1[3];
Gx2[4] = Gx1[4];
Gx2[5] = Gx1[5];
Gx2[6] = Gx1[6];
Gx2[7] = Gx1[7];
Gx2[8] = Gx1[8];
Gx2[9] = Gx1[9];
Gx2[10] = Gx1[10];
Gx2[11] = Gx1[11];
Gx2[12] = Gx1[12];
Gx2[13] = Gx1[13];
Gx2[14] = Gx1[14];
Gx2[15] = Gx1[15];
Gx2[16] = Gx1[16];
Gx2[17] = Gx1[17];
Gx2[18] = Gx1[18];
Gx2[19] = Gx1[19];
Gx2[20] = Gx1[20];
Gx2[21] = Gx1[21];
Gx2[22] = Gx1[22];
Gx2[23] = Gx1[23];
Gx2[24] = Gx1[24];
Gx2[25] = Gx1[25];
Gx2[26] = Gx1[26];
Gx2[27] = Gx1[27];
Gx2[28] = Gx1[28];
Gx2[29] = Gx1[29];
Gx2[30] = Gx1[30];
Gx2[31] = Gx1[31];
Gx2[32] = Gx1[32];
Gx2[33] = Gx1[33];
Gx2[34] = Gx1[34];
Gx2[35] = Gx1[35];
}

void acado_multGxGx( real_t* const Gx1, real_t* const Gx2, real_t* const Gx3 )
{
Gx3[0] = + Gx1[0]*Gx2[0] + Gx1[1]*Gx2[6] + Gx1[2]*Gx2[12] + Gx1[3]*Gx2[18] + Gx1[4]*Gx2[24] + Gx1[5]*Gx2[30];
Gx3[1] = + Gx1[0]*Gx2[1] + Gx1[1]*Gx2[7] + Gx1[2]*Gx2[13] + Gx1[3]*Gx2[19] + Gx1[4]*Gx2[25] + Gx1[5]*Gx2[31];
Gx3[2] = + Gx1[0]*Gx2[2] + Gx1[1]*Gx2[8] + Gx1[2]*Gx2[14] + Gx1[3]*Gx2[20] + Gx1[4]*Gx2[26] + Gx1[5]*Gx2[32];
Gx3[3] = + Gx1[0]*Gx2[3] + Gx1[1]*Gx2[9] + Gx1[2]*Gx2[15] + Gx1[3]*Gx2[21] + Gx1[4]*Gx2[27] + Gx1[5]*Gx2[33];
Gx3[4] = + Gx1[0]*Gx2[4] + Gx1[1]*Gx2[10] + Gx1[2]*Gx2[16] + Gx1[3]*Gx2[22] + Gx1[4]*Gx2[28] + Gx1[5]*Gx2[34];
Gx3[5] = + Gx1[0]*Gx2[5] + Gx1[1]*Gx2[11] + Gx1[2]*Gx2[17] + Gx1[3]*Gx2[23] + Gx1[4]*Gx2[29] + Gx1[5]*Gx2[35];
Gx3[6] = + Gx1[6]*Gx2[0] + Gx1[7]*Gx2[6] + Gx1[8]*Gx2[12] + Gx1[9]*Gx2[18] + Gx1[10]*Gx2[24] + Gx1[11]*Gx2[30];
Gx3[7] = + Gx1[6]*Gx2[1] + Gx1[7]*Gx2[7] + Gx1[8]*Gx2[13] + Gx1[9]*Gx2[19] + Gx1[10]*Gx2[25] + Gx1[11]*Gx2[31];
Gx3[8] = + Gx1[6]*Gx2[2] + Gx1[7]*Gx2[8] + Gx1[8]*Gx2[14] + Gx1[9]*Gx2[20] + Gx1[10]*Gx2[26] + Gx1[11]*Gx2[32];
Gx3[9] = + Gx1[6]*Gx2[3] + Gx1[7]*Gx2[9] + Gx1[8]*Gx2[15] + Gx1[9]*Gx2[21] + Gx1[10]*Gx2[27] + Gx1[11]*Gx2[33];
Gx3[10] = + Gx1[6]*Gx2[4] + Gx1[7]*Gx2[10] + Gx1[8]*Gx2[16] + Gx1[9]*Gx2[22] + Gx1[10]*Gx2[28] + Gx1[11]*Gx2[34];
Gx3[11] = + Gx1[6]*Gx2[5] + Gx1[7]*Gx2[11] + Gx1[8]*Gx2[17] + Gx1[9]*Gx2[23] + Gx1[10]*Gx2[29] + Gx1[11]*Gx2[35];
Gx3[12] = + Gx1[12]*Gx2[0] + Gx1[13]*Gx2[6] + Gx1[14]*Gx2[12] + Gx1[15]*Gx2[18] + Gx1[16]*Gx2[24] + Gx1[17]*Gx2[30];
Gx3[13] = + Gx1[12]*Gx2[1] + Gx1[13]*Gx2[7] + Gx1[14]*Gx2[13] + Gx1[15]*Gx2[19] + Gx1[16]*Gx2[25] + Gx1[17]*Gx2[31];
Gx3[14] = + Gx1[12]*Gx2[2] + Gx1[13]*Gx2[8] + Gx1[14]*Gx2[14] + Gx1[15]*Gx2[20] + Gx1[16]*Gx2[26] + Gx1[17]*Gx2[32];
Gx3[15] = + Gx1[12]*Gx2[3] + Gx1[13]*Gx2[9] + Gx1[14]*Gx2[15] + Gx1[15]*Gx2[21] + Gx1[16]*Gx2[27] + Gx1[17]*Gx2[33];
Gx3[16] = + Gx1[12]*Gx2[4] + Gx1[13]*Gx2[10] + Gx1[14]*Gx2[16] + Gx1[15]*Gx2[22] + Gx1[16]*Gx2[28] + Gx1[17]*Gx2[34];
Gx3[17] = + Gx1[12]*Gx2[5] + Gx1[13]*Gx2[11] + Gx1[14]*Gx2[17] + Gx1[15]*Gx2[23] + Gx1[16]*Gx2[29] + Gx1[17]*Gx2[35];
Gx3[18] = + Gx1[18]*Gx2[0] + Gx1[19]*Gx2[6] + Gx1[20]*Gx2[12] + Gx1[21]*Gx2[18] + Gx1[22]*Gx2[24] + Gx1[23]*Gx2[30];
Gx3[19] = + Gx1[18]*Gx2[1] + Gx1[19]*Gx2[7] + Gx1[20]*Gx2[13] + Gx1[21]*Gx2[19] + Gx1[22]*Gx2[25] + Gx1[23]*Gx2[31];
Gx3[20] = + Gx1[18]*Gx2[2] + Gx1[19]*Gx2[8] + Gx1[20]*Gx2[14] + Gx1[21]*Gx2[20] + Gx1[22]*Gx2[26] + Gx1[23]*Gx2[32];
Gx3[21] = + Gx1[18]*Gx2[3] + Gx1[19]*Gx2[9] + Gx1[20]*Gx2[15] + Gx1[21]*Gx2[21] + Gx1[22]*Gx2[27] + Gx1[23]*Gx2[33];
Gx3[22] = + Gx1[18]*Gx2[4] + Gx1[19]*Gx2[10] + Gx1[20]*Gx2[16] + Gx1[21]*Gx2[22] + Gx1[22]*Gx2[28] + Gx1[23]*Gx2[34];
Gx3[23] = + Gx1[18]*Gx2[5] + Gx1[19]*Gx2[11] + Gx1[20]*Gx2[17] + Gx1[21]*Gx2[23] + Gx1[22]*Gx2[29] + Gx1[23]*Gx2[35];
Gx3[24] = + Gx1[24]*Gx2[0] + Gx1[25]*Gx2[6] + Gx1[26]*Gx2[12] + Gx1[27]*Gx2[18] + Gx1[28]*Gx2[24] + Gx1[29]*Gx2[30];
Gx3[25] = + Gx1[24]*Gx2[1] + Gx1[25]*Gx2[7] + Gx1[26]*Gx2[13] + Gx1[27]*Gx2[19] + Gx1[28]*Gx2[25] + Gx1[29]*Gx2[31];
Gx3[26] = + Gx1[24]*Gx2[2] + Gx1[25]*Gx2[8] + Gx1[26]*Gx2[14] + Gx1[27]*Gx2[20] + Gx1[28]*Gx2[26] + Gx1[29]*Gx2[32];
Gx3[27] = + Gx1[24]*Gx2[3] + Gx1[25]*Gx2[9] + Gx1[26]*Gx2[15] + Gx1[27]*Gx2[21] + Gx1[28]*Gx2[27] + Gx1[29]*Gx2[33];
Gx3[28] = + Gx1[24]*Gx2[4] + Gx1[25]*Gx2[10] + Gx1[26]*Gx2[16] + Gx1[27]*Gx2[22] + Gx1[28]*Gx2[28] + Gx1[29]*Gx2[34];
Gx3[29] = + Gx1[24]*Gx2[5] + Gx1[25]*Gx2[11] + Gx1[26]*Gx2[17] + Gx1[27]*Gx2[23] + Gx1[28]*Gx2[29] + Gx1[29]*Gx2[35];
Gx3[30] = + Gx1[30]*Gx2[0] + Gx1[31]*Gx2[6] + Gx1[32]*Gx2[12] + Gx1[33]*Gx2[18] + Gx1[34]*Gx2[24] + Gx1[35]*Gx2[30];
Gx3[31] = + Gx1[30]*Gx2[1] + Gx1[31]*Gx2[7] + Gx1[32]*Gx2[13] + Gx1[33]*Gx2[19] + Gx1[34]*Gx2[25] + Gx1[35]*Gx2[31];
Gx3[32] = + Gx1[30]*Gx2[2] + Gx1[31]*Gx2[8] + Gx1[32]*Gx2[14] + Gx1[33]*Gx2[20] + Gx1[34]*Gx2[26] + Gx1[35]*Gx2[32];
Gx3[33] = + Gx1[30]*Gx2[3] + Gx1[31]*Gx2[9] + Gx1[32]*Gx2[15] + Gx1[33]*Gx2[21] + Gx1[34]*Gx2[27] + Gx1[35]*Gx2[33];
Gx3[34] = + Gx1[30]*Gx2[4] + Gx1[31]*Gx2[10] + Gx1[32]*Gx2[16] + Gx1[33]*Gx2[22] + Gx1[34]*Gx2[28] + Gx1[35]*Gx2[34];
Gx3[35] = + Gx1[30]*Gx2[5] + Gx1[31]*Gx2[11] + Gx1[32]*Gx2[17] + Gx1[33]*Gx2[23] + Gx1[34]*Gx2[29] + Gx1[35]*Gx2[35];
}

void acado_multGxGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[1]*Gu1[2] + Gx1[2]*Gu1[4] + Gx1[3]*Gu1[6] + Gx1[4]*Gu1[8] + Gx1[5]*Gu1[10];
Gu2[1] = + Gx1[0]*Gu1[1] + Gx1[1]*Gu1[3] + Gx1[2]*Gu1[5] + Gx1[3]*Gu1[7] + Gx1[4]*Gu1[9] + Gx1[5]*Gu1[11];
Gu2[2] = + Gx1[6]*Gu1[0] + Gx1[7]*Gu1[2] + Gx1[8]*Gu1[4] + Gx1[9]*Gu1[6] + Gx1[10]*Gu1[8] + Gx1[11]*Gu1[10];
Gu2[3] = + Gx1[6]*Gu1[1] + Gx1[7]*Gu1[3] + Gx1[8]*Gu1[5] + Gx1[9]*Gu1[7] + Gx1[10]*Gu1[9] + Gx1[11]*Gu1[11];
Gu2[4] = + Gx1[12]*Gu1[0] + Gx1[13]*Gu1[2] + Gx1[14]*Gu1[4] + Gx1[15]*Gu1[6] + Gx1[16]*Gu1[8] + Gx1[17]*Gu1[10];
Gu2[5] = + Gx1[12]*Gu1[1] + Gx1[13]*Gu1[3] + Gx1[14]*Gu1[5] + Gx1[15]*Gu1[7] + Gx1[16]*Gu1[9] + Gx1[17]*Gu1[11];
Gu2[6] = + Gx1[18]*Gu1[0] + Gx1[19]*Gu1[2] + Gx1[20]*Gu1[4] + Gx1[21]*Gu1[6] + Gx1[22]*Gu1[8] + Gx1[23]*Gu1[10];
Gu2[7] = + Gx1[18]*Gu1[1] + Gx1[19]*Gu1[3] + Gx1[20]*Gu1[5] + Gx1[21]*Gu1[7] + Gx1[22]*Gu1[9] + Gx1[23]*Gu1[11];
Gu2[8] = + Gx1[24]*Gu1[0] + Gx1[25]*Gu1[2] + Gx1[26]*Gu1[4] + Gx1[27]*Gu1[6] + Gx1[28]*Gu1[8] + Gx1[29]*Gu1[10];
Gu2[9] = + Gx1[24]*Gu1[1] + Gx1[25]*Gu1[3] + Gx1[26]*Gu1[5] + Gx1[27]*Gu1[7] + Gx1[28]*Gu1[9] + Gx1[29]*Gu1[11];
Gu2[10] = + Gx1[30]*Gu1[0] + Gx1[31]*Gu1[2] + Gx1[32]*Gu1[4] + Gx1[33]*Gu1[6] + Gx1[34]*Gu1[8] + Gx1[35]*Gu1[10];
Gu2[11] = + Gx1[30]*Gu1[1] + Gx1[31]*Gu1[3] + Gx1[32]*Gu1[5] + Gx1[33]*Gu1[7] + Gx1[34]*Gu1[9] + Gx1[35]*Gu1[11];
}

void acado_moveGuE( real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = Gu1[0];
Gu2[1] = Gu1[1];
Gu2[2] = Gu1[2];
Gu2[3] = Gu1[3];
Gu2[4] = Gu1[4];
Gu2[5] = Gu1[5];
Gu2[6] = Gu1[6];
Gu2[7] = Gu1[7];
Gu2[8] = Gu1[8];
Gu2[9] = Gu1[9];
Gu2[10] = Gu1[10];
Gu2[11] = Gu1[11];
}

void acado_multBTW1( real_t* const Gu1, real_t* const Gu2, int iRow, int iCol )
{
acadoWorkspace.H[(iRow * 160) + (iCol * 2)] = + Gu1[0]*Gu2[0] + Gu1[2]*Gu2[2] + Gu1[4]*Gu2[4] + Gu1[6]*Gu2[6] + Gu1[8]*Gu2[8] + Gu1[10]*Gu2[10];
acadoWorkspace.H[(iRow * 160) + (iCol * 2 + 1)] = + Gu1[0]*Gu2[1] + Gu1[2]*Gu2[3] + Gu1[4]*Gu2[5] + Gu1[6]*Gu2[7] + Gu1[8]*Gu2[9] + Gu1[10]*Gu2[11];
acadoWorkspace.H[(iRow * 160 + 80) + (iCol * 2)] = + Gu1[1]*Gu2[0] + Gu1[3]*Gu2[2] + Gu1[5]*Gu2[4] + Gu1[7]*Gu2[6] + Gu1[9]*Gu2[8] + Gu1[11]*Gu2[10];
acadoWorkspace.H[(iRow * 160 + 80) + (iCol * 2 + 1)] = + Gu1[1]*Gu2[1] + Gu1[3]*Gu2[3] + Gu1[5]*Gu2[5] + Gu1[7]*Gu2[7] + Gu1[9]*Gu2[9] + Gu1[11]*Gu2[11];
}

void acado_multBTW1_R1( real_t* const R11, real_t* const Gu1, real_t* const Gu2, int iRow )
{
acadoWorkspace.H[iRow * 162] = + Gu1[0]*Gu2[0] + Gu1[2]*Gu2[2] + Gu1[4]*Gu2[4] + Gu1[6]*Gu2[6] + Gu1[8]*Gu2[8] + Gu1[10]*Gu2[10] + R11[0];
acadoWorkspace.H[iRow * 162 + 1] = + Gu1[0]*Gu2[1] + Gu1[2]*Gu2[3] + Gu1[4]*Gu2[5] + Gu1[6]*Gu2[7] + Gu1[8]*Gu2[9] + Gu1[10]*Gu2[11] + R11[1];
acadoWorkspace.H[iRow * 162 + 80] = + Gu1[1]*Gu2[0] + Gu1[3]*Gu2[2] + Gu1[5]*Gu2[4] + Gu1[7]*Gu2[6] + Gu1[9]*Gu2[8] + Gu1[11]*Gu2[10] + R11[2];
acadoWorkspace.H[iRow * 162 + 81] = + Gu1[1]*Gu2[1] + Gu1[3]*Gu2[3] + Gu1[5]*Gu2[5] + Gu1[7]*Gu2[7] + Gu1[9]*Gu2[9] + Gu1[11]*Gu2[11] + R11[3];
acadoWorkspace.H[iRow * 162] += 1.0000000000000000e-04;
acadoWorkspace.H[iRow * 162 + 81] += 1.0000000000000000e-04;
}

void acado_multGxTGu( real_t* const Gx1, real_t* const Gu1, real_t* const Gu2 )
{
Gu2[0] = + Gx1[0]*Gu1[0] + Gx1[6]*Gu1[2] + Gx1[12]*Gu1[4] + Gx1[18]*Gu1[6] + Gx1[24]*Gu1[8] + Gx1[30]*Gu1[10];
Gu2[1] = + Gx1[0]*Gu1[1] + Gx1[6]*Gu1[3] + Gx1[12]*Gu1[5] + Gx1[18]*Gu1[7] + Gx1[24]*Gu1[9] + Gx1[30]*Gu1[11];
Gu2[2] = + Gx1[1]*Gu1[0] + Gx1[7]*Gu1[2] + Gx1[13]*Gu1[4] + Gx1[19]*Gu1[6] + Gx1[25]*Gu1[8] + Gx1[31]*Gu1[10];
Gu2[3] = + Gx1[1]*Gu1[1] + Gx1[7]*Gu1[3] + Gx1[13]*Gu1[5] + Gx1[19]*Gu1[7] + Gx1[25]*Gu1[9] + Gx1[31]*Gu1[11];
Gu2[4] = + Gx1[2]*Gu1[0] + Gx1[8]*Gu1[2] + Gx1[14]*Gu1[4] + Gx1[20]*Gu1[6] + Gx1[26]*Gu1[8] + Gx1[32]*Gu1[10];
Gu2[5] = + Gx1[2]*Gu1[1] + Gx1[8]*Gu1[3] + Gx1[14]*Gu1[5] + Gx1[20]*Gu1[7] + Gx1[26]*Gu1[9] + Gx1[32]*Gu1[11];
Gu2[6] = + Gx1[3]*Gu1[0] + Gx1[9]*Gu1[2] + Gx1[15]*Gu1[4] + Gx1[21]*Gu1[6] + Gx1[27]*Gu1[8] + Gx1[33]*Gu1[10];
Gu2[7] = + Gx1[3]*Gu1[1] + Gx1[9]*Gu1[3] + Gx1[15]*Gu1[5] + Gx1[21]*Gu1[7] + Gx1[27]*Gu1[9] + Gx1[33]*Gu1[11];
Gu2[8] = + Gx1[4]*Gu1[0] + Gx1[10]*Gu1[2] + Gx1[16]*Gu1[4] + Gx1[22]*Gu1[6] + Gx1[28]*Gu1[8] + Gx1[34]*Gu1[10];
Gu2[9] = + Gx1[4]*Gu1[1] + Gx1[10]*Gu1[3] + Gx1[16]*Gu1[5] + Gx1[22]*Gu1[7] + Gx1[28]*Gu1[9] + Gx1[34]*Gu1[11];
Gu2[10] = + Gx1[5]*Gu1[0] + Gx1[11]*Gu1[2] + Gx1[17]*Gu1[4] + Gx1[23]*Gu1[6] + Gx1[29]*Gu1[8] + Gx1[35]*Gu1[10];
Gu2[11] = + Gx1[5]*Gu1[1] + Gx1[11]*Gu1[3] + Gx1[17]*Gu1[5] + Gx1[23]*Gu1[7] + Gx1[29]*Gu1[9] + Gx1[35]*Gu1[11];
}

void acado_multQEW2( real_t* const Q11, real_t* const Gu1, real_t* const Gu2, real_t* const Gu3 )
{
Gu3[0] = + Q11[0]*Gu1[0] + Q11[1]*Gu1[2] + Q11[2]*Gu1[4] + Q11[3]*Gu1[6] + Q11[4]*Gu1[8] + Q11[5]*Gu1[10] + Gu2[0];
Gu3[1] = + Q11[0]*Gu1[1] + Q11[1]*Gu1[3] + Q11[2]*Gu1[5] + Q11[3]*Gu1[7] + Q11[4]*Gu1[9] + Q11[5]*Gu1[11] + Gu2[1];
Gu3[2] = + Q11[6]*Gu1[0] + Q11[7]*Gu1[2] + Q11[8]*Gu1[4] + Q11[9]*Gu1[6] + Q11[10]*Gu1[8] + Q11[11]*Gu1[10] + Gu2[2];
Gu3[3] = + Q11[6]*Gu1[1] + Q11[7]*Gu1[3] + Q11[8]*Gu1[5] + Q11[9]*Gu1[7] + Q11[10]*Gu1[9] + Q11[11]*Gu1[11] + Gu2[3];
Gu3[4] = + Q11[12]*Gu1[0] + Q11[13]*Gu1[2] + Q11[14]*Gu1[4] + Q11[15]*Gu1[6] + Q11[16]*Gu1[8] + Q11[17]*Gu1[10] + Gu2[4];
Gu3[5] = + Q11[12]*Gu1[1] + Q11[13]*Gu1[3] + Q11[14]*Gu1[5] + Q11[15]*Gu1[7] + Q11[16]*Gu1[9] + Q11[17]*Gu1[11] + Gu2[5];
Gu3[6] = + Q11[18]*Gu1[0] + Q11[19]*Gu1[2] + Q11[20]*Gu1[4] + Q11[21]*Gu1[6] + Q11[22]*Gu1[8] + Q11[23]*Gu1[10] + Gu2[6];
Gu3[7] = + Q11[18]*Gu1[1] + Q11[19]*Gu1[3] + Q11[20]*Gu1[5] + Q11[21]*Gu1[7] + Q11[22]*Gu1[9] + Q11[23]*Gu1[11] + Gu2[7];
Gu3[8] = + Q11[24]*Gu1[0] + Q11[25]*Gu1[2] + Q11[26]*Gu1[4] + Q11[27]*Gu1[6] + Q11[28]*Gu1[8] + Q11[29]*Gu1[10] + Gu2[8];
Gu3[9] = + Q11[24]*Gu1[1] + Q11[25]*Gu1[3] + Q11[26]*Gu1[5] + Q11[27]*Gu1[7] + Q11[28]*Gu1[9] + Q11[29]*Gu1[11] + Gu2[9];
Gu3[10] = + Q11[30]*Gu1[0] + Q11[31]*Gu1[2] + Q11[32]*Gu1[4] + Q11[33]*Gu1[6] + Q11[34]*Gu1[8] + Q11[35]*Gu1[10] + Gu2[10];
Gu3[11] = + Q11[30]*Gu1[1] + Q11[31]*Gu1[3] + Q11[32]*Gu1[5] + Q11[33]*Gu1[7] + Q11[34]*Gu1[9] + Q11[35]*Gu1[11] + Gu2[11];
}

void acado_macATw1QDy( real_t* const Gx1, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Gx1[0]*w11[0] + Gx1[6]*w11[1] + Gx1[12]*w11[2] + Gx1[18]*w11[3] + Gx1[24]*w11[4] + Gx1[30]*w11[5] + w12[0];
w13[1] = + Gx1[1]*w11[0] + Gx1[7]*w11[1] + Gx1[13]*w11[2] + Gx1[19]*w11[3] + Gx1[25]*w11[4] + Gx1[31]*w11[5] + w12[1];
w13[2] = + Gx1[2]*w11[0] + Gx1[8]*w11[1] + Gx1[14]*w11[2] + Gx1[20]*w11[3] + Gx1[26]*w11[4] + Gx1[32]*w11[5] + w12[2];
w13[3] = + Gx1[3]*w11[0] + Gx1[9]*w11[1] + Gx1[15]*w11[2] + Gx1[21]*w11[3] + Gx1[27]*w11[4] + Gx1[33]*w11[5] + w12[3];
w13[4] = + Gx1[4]*w11[0] + Gx1[10]*w11[1] + Gx1[16]*w11[2] + Gx1[22]*w11[3] + Gx1[28]*w11[4] + Gx1[34]*w11[5] + w12[4];
w13[5] = + Gx1[5]*w11[0] + Gx1[11]*w11[1] + Gx1[17]*w11[2] + Gx1[23]*w11[3] + Gx1[29]*w11[4] + Gx1[35]*w11[5] + w12[5];
}

void acado_macBTw1( real_t* const Gu1, real_t* const w11, real_t* const U1 )
{
U1[0] += + Gu1[0]*w11[0] + Gu1[2]*w11[1] + Gu1[4]*w11[2] + Gu1[6]*w11[3] + Gu1[8]*w11[4] + Gu1[10]*w11[5];
U1[1] += + Gu1[1]*w11[0] + Gu1[3]*w11[1] + Gu1[5]*w11[2] + Gu1[7]*w11[3] + Gu1[9]*w11[4] + Gu1[11]*w11[5];
}

void acado_macQSbarW2( real_t* const Q11, real_t* const w11, real_t* const w12, real_t* const w13 )
{
w13[0] = + Q11[0]*w11[0] + Q11[1]*w11[1] + Q11[2]*w11[2] + Q11[3]*w11[3] + Q11[4]*w11[4] + Q11[5]*w11[5] + w12[0];
w13[1] = + Q11[6]*w11[0] + Q11[7]*w11[1] + Q11[8]*w11[2] + Q11[9]*w11[3] + Q11[10]*w11[4] + Q11[11]*w11[5] + w12[1];
w13[2] = + Q11[12]*w11[0] + Q11[13]*w11[1] + Q11[14]*w11[2] + Q11[15]*w11[3] + Q11[16]*w11[4] + Q11[17]*w11[5] + w12[2];
w13[3] = + Q11[18]*w11[0] + Q11[19]*w11[1] + Q11[20]*w11[2] + Q11[21]*w11[3] + Q11[22]*w11[4] + Q11[23]*w11[5] + w12[3];
w13[4] = + Q11[24]*w11[0] + Q11[25]*w11[1] + Q11[26]*w11[2] + Q11[27]*w11[3] + Q11[28]*w11[4] + Q11[29]*w11[5] + w12[4];
w13[5] = + Q11[30]*w11[0] + Q11[31]*w11[1] + Q11[32]*w11[2] + Q11[33]*w11[3] + Q11[34]*w11[4] + Q11[35]*w11[5] + w12[5];
}

void acado_macASbar( real_t* const Gx1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4] + Gx1[5]*w11[5];
w12[1] += + Gx1[6]*w11[0] + Gx1[7]*w11[1] + Gx1[8]*w11[2] + Gx1[9]*w11[3] + Gx1[10]*w11[4] + Gx1[11]*w11[5];
w12[2] += + Gx1[12]*w11[0] + Gx1[13]*w11[1] + Gx1[14]*w11[2] + Gx1[15]*w11[3] + Gx1[16]*w11[4] + Gx1[17]*w11[5];
w12[3] += + Gx1[18]*w11[0] + Gx1[19]*w11[1] + Gx1[20]*w11[2] + Gx1[21]*w11[3] + Gx1[22]*w11[4] + Gx1[23]*w11[5];
w12[4] += + Gx1[24]*w11[0] + Gx1[25]*w11[1] + Gx1[26]*w11[2] + Gx1[27]*w11[3] + Gx1[28]*w11[4] + Gx1[29]*w11[5];
w12[5] += + Gx1[30]*w11[0] + Gx1[31]*w11[1] + Gx1[32]*w11[2] + Gx1[33]*w11[3] + Gx1[34]*w11[4] + Gx1[35]*w11[5];
}

void acado_expansionStep( real_t* const Gx1, real_t* const Gu1, real_t* const U1, real_t* const w11, real_t* const w12 )
{
w12[0] += + Gx1[0]*w11[0] + Gx1[1]*w11[1] + Gx1[2]*w11[2] + Gx1[3]*w11[3] + Gx1[4]*w11[4] + Gx1[5]*w11[5];
w12[1] += + Gx1[6]*w11[0] + Gx1[7]*w11[1] + Gx1[8]*w11[2] + Gx1[9]*w11[3] + Gx1[10]*w11[4] + Gx1[11]*w11[5];
w12[2] += + Gx1[12]*w11[0] + Gx1[13]*w11[1] + Gx1[14]*w11[2] + Gx1[15]*w11[3] + Gx1[16]*w11[4] + Gx1[17]*w11[5];
w12[3] += + Gx1[18]*w11[0] + Gx1[19]*w11[1] + Gx1[20]*w11[2] + Gx1[21]*w11[3] + Gx1[22]*w11[4] + Gx1[23]*w11[5];
w12[4] += + Gx1[24]*w11[0] + Gx1[25]*w11[1] + Gx1[26]*w11[2] + Gx1[27]*w11[3] + Gx1[28]*w11[4] + Gx1[29]*w11[5];
w12[5] += + Gx1[30]*w11[0] + Gx1[31]*w11[1] + Gx1[32]*w11[2] + Gx1[33]*w11[3] + Gx1[34]*w11[4] + Gx1[35]*w11[5];
w12[0] += + Gu1[0]*U1[0] + Gu1[1]*U1[1];
w12[1] += + Gu1[2]*U1[0] + Gu1[3]*U1[1];
w12[2] += + Gu1[4]*U1[0] + Gu1[5]*U1[1];
w12[3] += + Gu1[6]*U1[0] + Gu1[7]*U1[1];
w12[4] += + Gu1[8]*U1[0] + Gu1[9]*U1[1];
w12[5] += + Gu1[10]*U1[0] + Gu1[11]*U1[1];
}

void acado_copyHTH( int iRow, int iCol )
{
acadoWorkspace.H[(iRow * 160) + (iCol * 2)] = acadoWorkspace.H[(iCol * 160) + (iRow * 2)];
acadoWorkspace.H[(iRow * 160) + (iCol * 2 + 1)] = acadoWorkspace.H[(iCol * 160 + 80) + (iRow * 2)];
acadoWorkspace.H[(iRow * 160 + 80) + (iCol * 2)] = acadoWorkspace.H[(iCol * 160) + (iRow * 2 + 1)];
acadoWorkspace.H[(iRow * 160 + 80) + (iCol * 2 + 1)] = acadoWorkspace.H[(iCol * 160 + 80) + (iRow * 2 + 1)];
}

void acado_multRDy( real_t* const R2, real_t* const Dy1, real_t* const RDy1 )
{
RDy1[0] = + R2[0]*Dy1[0] + R2[1]*Dy1[1] + R2[2]*Dy1[2] + R2[3]*Dy1[3] + R2[4]*Dy1[4] + R2[5]*Dy1[5] + R2[6]*Dy1[6] + R2[7]*Dy1[7];
RDy1[1] = + R2[8]*Dy1[0] + R2[9]*Dy1[1] + R2[10]*Dy1[2] + R2[11]*Dy1[3] + R2[12]*Dy1[4] + R2[13]*Dy1[5] + R2[14]*Dy1[6] + R2[15]*Dy1[7];
}

void acado_multQDy( real_t* const Q2, real_t* const Dy1, real_t* const QDy1 )
{
QDy1[0] = + Q2[0]*Dy1[0] + Q2[1]*Dy1[1] + Q2[2]*Dy1[2] + Q2[3]*Dy1[3] + Q2[4]*Dy1[4] + Q2[5]*Dy1[5] + Q2[6]*Dy1[6] + Q2[7]*Dy1[7];
QDy1[1] = + Q2[8]*Dy1[0] + Q2[9]*Dy1[1] + Q2[10]*Dy1[2] + Q2[11]*Dy1[3] + Q2[12]*Dy1[4] + Q2[13]*Dy1[5] + Q2[14]*Dy1[6] + Q2[15]*Dy1[7];
QDy1[2] = + Q2[16]*Dy1[0] + Q2[17]*Dy1[1] + Q2[18]*Dy1[2] + Q2[19]*Dy1[3] + Q2[20]*Dy1[4] + Q2[21]*Dy1[5] + Q2[22]*Dy1[6] + Q2[23]*Dy1[7];
QDy1[3] = + Q2[24]*Dy1[0] + Q2[25]*Dy1[1] + Q2[26]*Dy1[2] + Q2[27]*Dy1[3] + Q2[28]*Dy1[4] + Q2[29]*Dy1[5] + Q2[30]*Dy1[6] + Q2[31]*Dy1[7];
QDy1[4] = + Q2[32]*Dy1[0] + Q2[33]*Dy1[1] + Q2[34]*Dy1[2] + Q2[35]*Dy1[3] + Q2[36]*Dy1[4] + Q2[37]*Dy1[5] + Q2[38]*Dy1[6] + Q2[39]*Dy1[7];
QDy1[5] = + Q2[40]*Dy1[0] + Q2[41]*Dy1[1] + Q2[42]*Dy1[2] + Q2[43]*Dy1[3] + Q2[44]*Dy1[4] + Q2[45]*Dy1[5] + Q2[46]*Dy1[6] + Q2[47]*Dy1[7];
}

void acado_multHxE( real_t* const Hx, real_t* const E, int row, int col )
{
acadoWorkspace.A[(row * 320 + 3200) + (col * 2)] = + Hx[0]*E[0] + Hx[1]*E[2] + Hx[2]*E[4] + Hx[3]*E[6] + Hx[4]*E[8] + Hx[5]*E[10];
acadoWorkspace.A[(row * 320 + 3200) + (col * 2 + 1)] = + Hx[0]*E[1] + Hx[1]*E[3] + Hx[2]*E[5] + Hx[3]*E[7] + Hx[4]*E[9] + Hx[5]*E[11];
acadoWorkspace.A[(row * 320 + 3280) + (col * 2)] = + Hx[6]*E[0] + Hx[7]*E[2] + Hx[8]*E[4] + Hx[9]*E[6] + Hx[10]*E[8] + Hx[11]*E[10];
acadoWorkspace.A[(row * 320 + 3280) + (col * 2 + 1)] = + Hx[6]*E[1] + Hx[7]*E[3] + Hx[8]*E[5] + Hx[9]*E[7] + Hx[10]*E[9] + Hx[11]*E[11];
acadoWorkspace.A[(row * 320 + 3360) + (col * 2)] = + Hx[12]*E[0] + Hx[13]*E[2] + Hx[14]*E[4] + Hx[15]*E[6] + Hx[16]*E[8] + Hx[17]*E[10];
acadoWorkspace.A[(row * 320 + 3360) + (col * 2 + 1)] = + Hx[12]*E[1] + Hx[13]*E[3] + Hx[14]*E[5] + Hx[15]*E[7] + Hx[16]*E[9] + Hx[17]*E[11];
acadoWorkspace.A[(row * 320 + 3440) + (col * 2)] = + Hx[18]*E[0] + Hx[19]*E[2] + Hx[20]*E[4] + Hx[21]*E[6] + Hx[22]*E[8] + Hx[23]*E[10];
acadoWorkspace.A[(row * 320 + 3440) + (col * 2 + 1)] = + Hx[18]*E[1] + Hx[19]*E[3] + Hx[20]*E[5] + Hx[21]*E[7] + Hx[22]*E[9] + Hx[23]*E[11];
}

void acado_macHxd( real_t* const Hx, real_t* const tmpd, real_t* const lbA, real_t* const ubA )
{
acadoWorkspace.evHxd[0] = + Hx[0]*tmpd[0] + Hx[1]*tmpd[1] + Hx[2]*tmpd[2] + Hx[3]*tmpd[3] + Hx[4]*tmpd[4] + Hx[5]*tmpd[5];
acadoWorkspace.evHxd[1] = + Hx[6]*tmpd[0] + Hx[7]*tmpd[1] + Hx[8]*tmpd[2] + Hx[9]*tmpd[3] + Hx[10]*tmpd[4] + Hx[11]*tmpd[5];
acadoWorkspace.evHxd[2] = + Hx[12]*tmpd[0] + Hx[13]*tmpd[1] + Hx[14]*tmpd[2] + Hx[15]*tmpd[3] + Hx[16]*tmpd[4] + Hx[17]*tmpd[5];
acadoWorkspace.evHxd[3] = + Hx[18]*tmpd[0] + Hx[19]*tmpd[1] + Hx[20]*tmpd[2] + Hx[21]*tmpd[3] + Hx[22]*tmpd[4] + Hx[23]*tmpd[5];
lbA[0] -= acadoWorkspace.evHxd[0];
lbA[1] -= acadoWorkspace.evHxd[1];
lbA[2] -= acadoWorkspace.evHxd[2];
lbA[3] -= acadoWorkspace.evHxd[3];
ubA[0] -= acadoWorkspace.evHxd[0];
ubA[1] -= acadoWorkspace.evHxd[1];
ubA[2] -= acadoWorkspace.evHxd[2];
ubA[3] -= acadoWorkspace.evHxd[3];
}

void acado_condensePrep(  )
{
int lRun1;
int lRun2;
int lRun3;
int lRun4;
int lRun5;
/** Row vector of size: 40 */
static const int xBoundIndices[ 40 ] = 
{ 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 96, 102, 108, 114, 120, 126, 132, 138, 144, 150, 156, 162, 168, 174, 180, 186, 192, 198, 204, 210, 216, 222, 228, 234, 240 };
acado_moveGxT( acadoWorkspace.evGx, acadoWorkspace.C );
acado_multGxGx( &(acadoWorkspace.evGx[ 36 ]), acadoWorkspace.C, &(acadoWorkspace.C[ 36 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 72 ]), &(acadoWorkspace.C[ 36 ]), &(acadoWorkspace.C[ 72 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 108 ]), &(acadoWorkspace.C[ 72 ]), &(acadoWorkspace.C[ 108 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 144 ]), &(acadoWorkspace.C[ 108 ]), &(acadoWorkspace.C[ 144 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 180 ]), &(acadoWorkspace.C[ 144 ]), &(acadoWorkspace.C[ 180 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 216 ]), &(acadoWorkspace.C[ 180 ]), &(acadoWorkspace.C[ 216 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 252 ]), &(acadoWorkspace.C[ 216 ]), &(acadoWorkspace.C[ 252 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 288 ]), &(acadoWorkspace.C[ 252 ]), &(acadoWorkspace.C[ 288 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 324 ]), &(acadoWorkspace.C[ 288 ]), &(acadoWorkspace.C[ 324 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 360 ]), &(acadoWorkspace.C[ 324 ]), &(acadoWorkspace.C[ 360 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 396 ]), &(acadoWorkspace.C[ 360 ]), &(acadoWorkspace.C[ 396 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 432 ]), &(acadoWorkspace.C[ 396 ]), &(acadoWorkspace.C[ 432 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 468 ]), &(acadoWorkspace.C[ 432 ]), &(acadoWorkspace.C[ 468 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 504 ]), &(acadoWorkspace.C[ 468 ]), &(acadoWorkspace.C[ 504 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 540 ]), &(acadoWorkspace.C[ 504 ]), &(acadoWorkspace.C[ 540 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 576 ]), &(acadoWorkspace.C[ 540 ]), &(acadoWorkspace.C[ 576 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 612 ]), &(acadoWorkspace.C[ 576 ]), &(acadoWorkspace.C[ 612 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 648 ]), &(acadoWorkspace.C[ 612 ]), &(acadoWorkspace.C[ 648 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 684 ]), &(acadoWorkspace.C[ 648 ]), &(acadoWorkspace.C[ 684 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 720 ]), &(acadoWorkspace.C[ 684 ]), &(acadoWorkspace.C[ 720 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 756 ]), &(acadoWorkspace.C[ 720 ]), &(acadoWorkspace.C[ 756 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 792 ]), &(acadoWorkspace.C[ 756 ]), &(acadoWorkspace.C[ 792 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 828 ]), &(acadoWorkspace.C[ 792 ]), &(acadoWorkspace.C[ 828 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 864 ]), &(acadoWorkspace.C[ 828 ]), &(acadoWorkspace.C[ 864 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 900 ]), &(acadoWorkspace.C[ 864 ]), &(acadoWorkspace.C[ 900 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 936 ]), &(acadoWorkspace.C[ 900 ]), &(acadoWorkspace.C[ 936 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 972 ]), &(acadoWorkspace.C[ 936 ]), &(acadoWorkspace.C[ 972 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1008 ]), &(acadoWorkspace.C[ 972 ]), &(acadoWorkspace.C[ 1008 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1044 ]), &(acadoWorkspace.C[ 1008 ]), &(acadoWorkspace.C[ 1044 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1080 ]), &(acadoWorkspace.C[ 1044 ]), &(acadoWorkspace.C[ 1080 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1116 ]), &(acadoWorkspace.C[ 1080 ]), &(acadoWorkspace.C[ 1116 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1152 ]), &(acadoWorkspace.C[ 1116 ]), &(acadoWorkspace.C[ 1152 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1188 ]), &(acadoWorkspace.C[ 1152 ]), &(acadoWorkspace.C[ 1188 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1224 ]), &(acadoWorkspace.C[ 1188 ]), &(acadoWorkspace.C[ 1224 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1260 ]), &(acadoWorkspace.C[ 1224 ]), &(acadoWorkspace.C[ 1260 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1296 ]), &(acadoWorkspace.C[ 1260 ]), &(acadoWorkspace.C[ 1296 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1332 ]), &(acadoWorkspace.C[ 1296 ]), &(acadoWorkspace.C[ 1332 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1368 ]), &(acadoWorkspace.C[ 1332 ]), &(acadoWorkspace.C[ 1368 ]) );
acado_multGxGx( &(acadoWorkspace.evGx[ 1404 ]), &(acadoWorkspace.C[ 1368 ]), &(acadoWorkspace.C[ 1404 ]) );
for (lRun2 = 0; lRun2 < 40; ++lRun2)
{
lRun3 = ((lRun2) * (lRun2 * -1 + 81)) / (2);
acado_moveGuE( &(acadoWorkspace.evGu[ lRun2 * 12 ]), &(acadoWorkspace.E[ lRun3 * 12 ]) );
for (lRun1 = 1; lRun1 < lRun2 * -1 + 40; ++lRun1)
{
acado_multGxGu( &(acadoWorkspace.evGx[ ((((lRun2) + (lRun1)) * (6)) * (6)) + (0) ]), &(acadoWorkspace.E[ (((((lRun3) + (lRun1)) - (1)) * (6)) * (2)) + (0) ]), &(acadoWorkspace.E[ ((((lRun3) + (lRun1)) * (6)) * (2)) + (0) ]) );
}

acado_multGxGu( acadoWorkspace.QN1, &(acadoWorkspace.E[ ((((((lRun3) - (lRun2)) + (40)) - (1)) * (6)) * (2)) + (0) ]), acadoWorkspace.W1 );
for (lRun1 = 39; lRun2 < lRun1; --lRun1)
{
acado_multBTW1( &(acadoWorkspace.evGu[ lRun1 * 12 ]), acadoWorkspace.W1, lRun1, lRun2 );
acado_multGxTGu( &(acadoWorkspace.evGx[ lRun1 * 36 ]), acadoWorkspace.W1, acadoWorkspace.W2 );
acado_multQEW2( &(acadoWorkspace.Q1[ lRun1 * 36 ]), &(acadoWorkspace.E[ ((((((lRun3) + (lRun1)) - (lRun2)) - (1)) * (6)) * (2)) + (0) ]), acadoWorkspace.W2, acadoWorkspace.W1 );
}
acado_multBTW1_R1( &(acadoWorkspace.R1[ lRun2 * 4 ]), &(acadoWorkspace.evGu[ lRun2 * 12 ]), acadoWorkspace.W1, lRun2 );
}

for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
for (lRun2 = 0; lRun2 < lRun1; ++lRun2)
{
acado_copyHTH( lRun2, lRun1 );
}
}

for (lRun2 = 0; lRun2 < 240; ++lRun2)
acadoWorkspace.sbar[lRun2 + 6] = acadoWorkspace.d[lRun2];

acadoWorkspace.lb[0] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[0];
acadoWorkspace.lb[1] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[1];
acadoWorkspace.lb[2] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[2];
acadoWorkspace.lb[3] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[3];
acadoWorkspace.lb[4] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[4];
acadoWorkspace.lb[5] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[5];
acadoWorkspace.lb[6] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[6];
acadoWorkspace.lb[7] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[7];
acadoWorkspace.lb[8] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[8];
acadoWorkspace.lb[9] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[9];
acadoWorkspace.lb[10] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[10];
acadoWorkspace.lb[11] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[11];
acadoWorkspace.lb[12] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[12];
acadoWorkspace.lb[13] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[13];
acadoWorkspace.lb[14] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[14];
acadoWorkspace.lb[15] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[15];
acadoWorkspace.lb[16] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[16];
acadoWorkspace.lb[17] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[17];
acadoWorkspace.lb[18] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[18];
acadoWorkspace.lb[19] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[19];
acadoWorkspace.lb[20] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[20];
acadoWorkspace.lb[21] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[21];
acadoWorkspace.lb[22] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[22];
acadoWorkspace.lb[23] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[23];
acadoWorkspace.lb[24] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[24];
acadoWorkspace.lb[25] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[25];
acadoWorkspace.lb[26] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[26];
acadoWorkspace.lb[27] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[27];
acadoWorkspace.lb[28] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[28];
acadoWorkspace.lb[29] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[29];
acadoWorkspace.lb[30] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[30];
acadoWorkspace.lb[31] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[31];
acadoWorkspace.lb[32] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[32];
acadoWorkspace.lb[33] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[33];
acadoWorkspace.lb[34] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[34];
acadoWorkspace.lb[35] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[35];
acadoWorkspace.lb[36] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[36];
acadoWorkspace.lb[37] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[37];
acadoWorkspace.lb[38] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[38];
acadoWorkspace.lb[39] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[39];
acadoWorkspace.lb[40] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[40];
acadoWorkspace.lb[41] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[41];
acadoWorkspace.lb[42] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[42];
acadoWorkspace.lb[43] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[43];
acadoWorkspace.lb[44] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[44];
acadoWorkspace.lb[45] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[45];
acadoWorkspace.lb[46] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[46];
acadoWorkspace.lb[47] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[47];
acadoWorkspace.lb[48] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[48];
acadoWorkspace.lb[49] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[49];
acadoWorkspace.lb[50] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[50];
acadoWorkspace.lb[51] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[51];
acadoWorkspace.lb[52] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[52];
acadoWorkspace.lb[53] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[53];
acadoWorkspace.lb[54] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[54];
acadoWorkspace.lb[55] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[55];
acadoWorkspace.lb[56] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[56];
acadoWorkspace.lb[57] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[57];
acadoWorkspace.lb[58] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[58];
acadoWorkspace.lb[59] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[59];
acadoWorkspace.lb[60] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[60];
acadoWorkspace.lb[61] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[61];
acadoWorkspace.lb[62] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[62];
acadoWorkspace.lb[63] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[63];
acadoWorkspace.lb[64] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[64];
acadoWorkspace.lb[65] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[65];
acadoWorkspace.lb[66] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[66];
acadoWorkspace.lb[67] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[67];
acadoWorkspace.lb[68] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[68];
acadoWorkspace.lb[69] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[69];
acadoWorkspace.lb[70] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[70];
acadoWorkspace.lb[71] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[71];
acadoWorkspace.lb[72] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[72];
acadoWorkspace.lb[73] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[73];
acadoWorkspace.lb[74] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[74];
acadoWorkspace.lb[75] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[75];
acadoWorkspace.lb[76] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[76];
acadoWorkspace.lb[77] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[77];
acadoWorkspace.lb[78] = (real_t)-1.0893574526084089e+00 - acadoVariables.u[78];
acadoWorkspace.lb[79] = (real_t)-1.0000000000000000e+12 - acadoVariables.u[79];
acadoWorkspace.ub[0] = (real_t)1.0893574526084089e+00 - acadoVariables.u[0];
acadoWorkspace.ub[1] = (real_t)1.0000000000000000e+12 - acadoVariables.u[1];
acadoWorkspace.ub[2] = (real_t)1.0893574526084089e+00 - acadoVariables.u[2];
acadoWorkspace.ub[3] = (real_t)1.0000000000000000e+12 - acadoVariables.u[3];
acadoWorkspace.ub[4] = (real_t)1.0893574526084089e+00 - acadoVariables.u[4];
acadoWorkspace.ub[5] = (real_t)1.0000000000000000e+12 - acadoVariables.u[5];
acadoWorkspace.ub[6] = (real_t)1.0893574526084089e+00 - acadoVariables.u[6];
acadoWorkspace.ub[7] = (real_t)1.0000000000000000e+12 - acadoVariables.u[7];
acadoWorkspace.ub[8] = (real_t)1.0893574526084089e+00 - acadoVariables.u[8];
acadoWorkspace.ub[9] = (real_t)1.0000000000000000e+12 - acadoVariables.u[9];
acadoWorkspace.ub[10] = (real_t)1.0893574526084089e+00 - acadoVariables.u[10];
acadoWorkspace.ub[11] = (real_t)1.0000000000000000e+12 - acadoVariables.u[11];
acadoWorkspace.ub[12] = (real_t)1.0893574526084089e+00 - acadoVariables.u[12];
acadoWorkspace.ub[13] = (real_t)1.0000000000000000e+12 - acadoVariables.u[13];
acadoWorkspace.ub[14] = (real_t)1.0893574526084089e+00 - acadoVariables.u[14];
acadoWorkspace.ub[15] = (real_t)1.0000000000000000e+12 - acadoVariables.u[15];
acadoWorkspace.ub[16] = (real_t)1.0893574526084089e+00 - acadoVariables.u[16];
acadoWorkspace.ub[17] = (real_t)1.0000000000000000e+12 - acadoVariables.u[17];
acadoWorkspace.ub[18] = (real_t)1.0893574526084089e+00 - acadoVariables.u[18];
acadoWorkspace.ub[19] = (real_t)1.0000000000000000e+12 - acadoVariables.u[19];
acadoWorkspace.ub[20] = (real_t)1.0893574526084089e+00 - acadoVariables.u[20];
acadoWorkspace.ub[21] = (real_t)1.0000000000000000e+12 - acadoVariables.u[21];
acadoWorkspace.ub[22] = (real_t)1.0893574526084089e+00 - acadoVariables.u[22];
acadoWorkspace.ub[23] = (real_t)1.0000000000000000e+12 - acadoVariables.u[23];
acadoWorkspace.ub[24] = (real_t)1.0893574526084089e+00 - acadoVariables.u[24];
acadoWorkspace.ub[25] = (real_t)1.0000000000000000e+12 - acadoVariables.u[25];
acadoWorkspace.ub[26] = (real_t)1.0893574526084089e+00 - acadoVariables.u[26];
acadoWorkspace.ub[27] = (real_t)1.0000000000000000e+12 - acadoVariables.u[27];
acadoWorkspace.ub[28] = (real_t)1.0893574526084089e+00 - acadoVariables.u[28];
acadoWorkspace.ub[29] = (real_t)1.0000000000000000e+12 - acadoVariables.u[29];
acadoWorkspace.ub[30] = (real_t)1.0893574526084089e+00 - acadoVariables.u[30];
acadoWorkspace.ub[31] = (real_t)1.0000000000000000e+12 - acadoVariables.u[31];
acadoWorkspace.ub[32] = (real_t)1.0893574526084089e+00 - acadoVariables.u[32];
acadoWorkspace.ub[33] = (real_t)1.0000000000000000e+12 - acadoVariables.u[33];
acadoWorkspace.ub[34] = (real_t)1.0893574526084089e+00 - acadoVariables.u[34];
acadoWorkspace.ub[35] = (real_t)1.0000000000000000e+12 - acadoVariables.u[35];
acadoWorkspace.ub[36] = (real_t)1.0893574526084089e+00 - acadoVariables.u[36];
acadoWorkspace.ub[37] = (real_t)1.0000000000000000e+12 - acadoVariables.u[37];
acadoWorkspace.ub[38] = (real_t)1.0893574526084089e+00 - acadoVariables.u[38];
acadoWorkspace.ub[39] = (real_t)1.0000000000000000e+12 - acadoVariables.u[39];
acadoWorkspace.ub[40] = (real_t)1.0893574526084089e+00 - acadoVariables.u[40];
acadoWorkspace.ub[41] = (real_t)1.0000000000000000e+12 - acadoVariables.u[41];
acadoWorkspace.ub[42] = (real_t)1.0893574526084089e+00 - acadoVariables.u[42];
acadoWorkspace.ub[43] = (real_t)1.0000000000000000e+12 - acadoVariables.u[43];
acadoWorkspace.ub[44] = (real_t)1.0893574526084089e+00 - acadoVariables.u[44];
acadoWorkspace.ub[45] = (real_t)1.0000000000000000e+12 - acadoVariables.u[45];
acadoWorkspace.ub[46] = (real_t)1.0893574526084089e+00 - acadoVariables.u[46];
acadoWorkspace.ub[47] = (real_t)1.0000000000000000e+12 - acadoVariables.u[47];
acadoWorkspace.ub[48] = (real_t)1.0893574526084089e+00 - acadoVariables.u[48];
acadoWorkspace.ub[49] = (real_t)1.0000000000000000e+12 - acadoVariables.u[49];
acadoWorkspace.ub[50] = (real_t)1.0893574526084089e+00 - acadoVariables.u[50];
acadoWorkspace.ub[51] = (real_t)1.0000000000000000e+12 - acadoVariables.u[51];
acadoWorkspace.ub[52] = (real_t)1.0893574526084089e+00 - acadoVariables.u[52];
acadoWorkspace.ub[53] = (real_t)1.0000000000000000e+12 - acadoVariables.u[53];
acadoWorkspace.ub[54] = (real_t)1.0893574526084089e+00 - acadoVariables.u[54];
acadoWorkspace.ub[55] = (real_t)1.0000000000000000e+12 - acadoVariables.u[55];
acadoWorkspace.ub[56] = (real_t)1.0893574526084089e+00 - acadoVariables.u[56];
acadoWorkspace.ub[57] = (real_t)1.0000000000000000e+12 - acadoVariables.u[57];
acadoWorkspace.ub[58] = (real_t)1.0893574526084089e+00 - acadoVariables.u[58];
acadoWorkspace.ub[59] = (real_t)1.0000000000000000e+12 - acadoVariables.u[59];
acadoWorkspace.ub[60] = (real_t)1.0893574526084089e+00 - acadoVariables.u[60];
acadoWorkspace.ub[61] = (real_t)1.0000000000000000e+12 - acadoVariables.u[61];
acadoWorkspace.ub[62] = (real_t)1.0893574526084089e+00 - acadoVariables.u[62];
acadoWorkspace.ub[63] = (real_t)1.0000000000000000e+12 - acadoVariables.u[63];
acadoWorkspace.ub[64] = (real_t)1.0893574526084089e+00 - acadoVariables.u[64];
acadoWorkspace.ub[65] = (real_t)1.0000000000000000e+12 - acadoVariables.u[65];
acadoWorkspace.ub[66] = (real_t)1.0893574526084089e+00 - acadoVariables.u[66];
acadoWorkspace.ub[67] = (real_t)1.0000000000000000e+12 - acadoVariables.u[67];
acadoWorkspace.ub[68] = (real_t)1.0893574526084089e+00 - acadoVariables.u[68];
acadoWorkspace.ub[69] = (real_t)1.0000000000000000e+12 - acadoVariables.u[69];
acadoWorkspace.ub[70] = (real_t)1.0893574526084089e+00 - acadoVariables.u[70];
acadoWorkspace.ub[71] = (real_t)1.0000000000000000e+12 - acadoVariables.u[71];
acadoWorkspace.ub[72] = (real_t)1.0893574526084089e+00 - acadoVariables.u[72];
acadoWorkspace.ub[73] = (real_t)1.0000000000000000e+12 - acadoVariables.u[73];
acadoWorkspace.ub[74] = (real_t)1.0893574526084089e+00 - acadoVariables.u[74];
acadoWorkspace.ub[75] = (real_t)1.0000000000000000e+12 - acadoVariables.u[75];
acadoWorkspace.ub[76] = (real_t)1.0893574526084089e+00 - acadoVariables.u[76];
acadoWorkspace.ub[77] = (real_t)1.0000000000000000e+12 - acadoVariables.u[77];
acadoWorkspace.ub[78] = (real_t)1.0893574526084089e+00 - acadoVariables.u[78];
acadoWorkspace.ub[79] = (real_t)1.0000000000000000e+12 - acadoVariables.u[79];

for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
lRun3 = xBoundIndices[ lRun1 ] - 6;
lRun4 = ((lRun3) / (6)) + (1);
for (lRun2 = 0; lRun2 < lRun4; ++lRun2)
{
lRun5 = ((((((lRun2) * (lRun2 * -1 + 79)) / (2)) + (lRun4)) - (1)) * (6)) + ((lRun3) % (6));
acadoWorkspace.A[(lRun1 * 80) + (lRun2 * 2)] = acadoWorkspace.E[lRun5 * 2];
acadoWorkspace.A[(lRun1 * 80) + (lRun2 * 2 + 1)] = acadoWorkspace.E[lRun5 * 2 + 1];
}
}

for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
acadoWorkspace.conValueIn[0] = acadoVariables.x[lRun1 * 6];
acadoWorkspace.conValueIn[1] = acadoVariables.x[lRun1 * 6 + 1];
acadoWorkspace.conValueIn[2] = acadoVariables.x[lRun1 * 6 + 2];
acadoWorkspace.conValueIn[3] = acadoVariables.x[lRun1 * 6 + 3];
acadoWorkspace.conValueIn[4] = acadoVariables.x[lRun1 * 6 + 4];
acadoWorkspace.conValueIn[5] = acadoVariables.x[lRun1 * 6 + 5];
acadoWorkspace.conValueIn[6] = acadoVariables.u[lRun1 * 2];
acadoWorkspace.conValueIn[7] = acadoVariables.u[lRun1 * 2 + 1];
acadoWorkspace.conValueIn[8] = acadoVariables.od[lRun1 * 3];
acadoWorkspace.conValueIn[9] = acadoVariables.od[lRun1 * 3 + 1];
acadoWorkspace.conValueIn[10] = acadoVariables.od[lRun1 * 3 + 2];
acado_evaluatePathConstraints( acadoWorkspace.conValueIn, acadoWorkspace.conValueOut );
acadoWorkspace.evH[lRun1 * 4] = acadoWorkspace.conValueOut[0];
acadoWorkspace.evH[lRun1 * 4 + 1] = acadoWorkspace.conValueOut[1];
acadoWorkspace.evH[lRun1 * 4 + 2] = acadoWorkspace.conValueOut[2];
acadoWorkspace.evH[lRun1 * 4 + 3] = acadoWorkspace.conValueOut[3];

acadoWorkspace.evHx[lRun1 * 24] = acadoWorkspace.conValueOut[4];
acadoWorkspace.evHx[lRun1 * 24 + 1] = acadoWorkspace.conValueOut[5];
acadoWorkspace.evHx[lRun1 * 24 + 2] = acadoWorkspace.conValueOut[6];
acadoWorkspace.evHx[lRun1 * 24 + 3] = acadoWorkspace.conValueOut[7];
acadoWorkspace.evHx[lRun1 * 24 + 4] = acadoWorkspace.conValueOut[8];
acadoWorkspace.evHx[lRun1 * 24 + 5] = acadoWorkspace.conValueOut[9];
acadoWorkspace.evHx[lRun1 * 24 + 6] = acadoWorkspace.conValueOut[10];
acadoWorkspace.evHx[lRun1 * 24 + 7] = acadoWorkspace.conValueOut[11];
acadoWorkspace.evHx[lRun1 * 24 + 8] = acadoWorkspace.conValueOut[12];
acadoWorkspace.evHx[lRun1 * 24 + 9] = acadoWorkspace.conValueOut[13];
acadoWorkspace.evHx[lRun1 * 24 + 10] = acadoWorkspace.conValueOut[14];
acadoWorkspace.evHx[lRun1 * 24 + 11] = acadoWorkspace.conValueOut[15];
acadoWorkspace.evHx[lRun1 * 24 + 12] = acadoWorkspace.conValueOut[16];
acadoWorkspace.evHx[lRun1 * 24 + 13] = acadoWorkspace.conValueOut[17];
acadoWorkspace.evHx[lRun1 * 24 + 14] = acadoWorkspace.conValueOut[18];
acadoWorkspace.evHx[lRun1 * 24 + 15] = acadoWorkspace.conValueOut[19];
acadoWorkspace.evHx[lRun1 * 24 + 16] = acadoWorkspace.conValueOut[20];
acadoWorkspace.evHx[lRun1 * 24 + 17] = acadoWorkspace.conValueOut[21];
acadoWorkspace.evHx[lRun1 * 24 + 18] = acadoWorkspace.conValueOut[22];
acadoWorkspace.evHx[lRun1 * 24 + 19] = acadoWorkspace.conValueOut[23];
acadoWorkspace.evHx[lRun1 * 24 + 20] = acadoWorkspace.conValueOut[24];
acadoWorkspace.evHx[lRun1 * 24 + 21] = acadoWorkspace.conValueOut[25];
acadoWorkspace.evHx[lRun1 * 24 + 22] = acadoWorkspace.conValueOut[26];
acadoWorkspace.evHx[lRun1 * 24 + 23] = acadoWorkspace.conValueOut[27];
acadoWorkspace.evHu[lRun1 * 8] = acadoWorkspace.conValueOut[28];
acadoWorkspace.evHu[lRun1 * 8 + 1] = acadoWorkspace.conValueOut[29];
acadoWorkspace.evHu[lRun1 * 8 + 2] = acadoWorkspace.conValueOut[30];
acadoWorkspace.evHu[lRun1 * 8 + 3] = acadoWorkspace.conValueOut[31];
acadoWorkspace.evHu[lRun1 * 8 + 4] = acadoWorkspace.conValueOut[32];
acadoWorkspace.evHu[lRun1 * 8 + 5] = acadoWorkspace.conValueOut[33];
acadoWorkspace.evHu[lRun1 * 8 + 6] = acadoWorkspace.conValueOut[34];
acadoWorkspace.evHu[lRun1 * 8 + 7] = acadoWorkspace.conValueOut[35];
}



for (lRun2 = 0; lRun2 < 39; ++lRun2)
{
for (lRun3 = 0; lRun3 < lRun2 + 1; ++lRun3)
{
lRun4 = (((lRun3) * (lRun3 * -1 + 79)) / (2)) + (lRun2);
lRun5 = lRun2 + 1;
acado_multHxE( &(acadoWorkspace.evHx[ lRun2 * 24 + 24 ]), &(acadoWorkspace.E[ lRun4 * 12 ]), lRun5, lRun3 );
}
}

acadoWorkspace.A[3200] = acadoWorkspace.evHu[0];
acadoWorkspace.A[3201] = acadoWorkspace.evHu[1];
acadoWorkspace.A[3280] = acadoWorkspace.evHu[2];
acadoWorkspace.A[3281] = acadoWorkspace.evHu[3];
acadoWorkspace.A[3360] = acadoWorkspace.evHu[4];
acadoWorkspace.A[3361] = acadoWorkspace.evHu[5];
acadoWorkspace.A[3440] = acadoWorkspace.evHu[6];
acadoWorkspace.A[3441] = acadoWorkspace.evHu[7];
acadoWorkspace.A[3522] = acadoWorkspace.evHu[8];
acadoWorkspace.A[3523] = acadoWorkspace.evHu[9];
acadoWorkspace.A[3602] = acadoWorkspace.evHu[10];
acadoWorkspace.A[3603] = acadoWorkspace.evHu[11];
acadoWorkspace.A[3682] = acadoWorkspace.evHu[12];
acadoWorkspace.A[3683] = acadoWorkspace.evHu[13];
acadoWorkspace.A[3762] = acadoWorkspace.evHu[14];
acadoWorkspace.A[3763] = acadoWorkspace.evHu[15];
acadoWorkspace.A[3844] = acadoWorkspace.evHu[16];
acadoWorkspace.A[3845] = acadoWorkspace.evHu[17];
acadoWorkspace.A[3924] = acadoWorkspace.evHu[18];
acadoWorkspace.A[3925] = acadoWorkspace.evHu[19];
acadoWorkspace.A[4004] = acadoWorkspace.evHu[20];
acadoWorkspace.A[4005] = acadoWorkspace.evHu[21];
acadoWorkspace.A[4084] = acadoWorkspace.evHu[22];
acadoWorkspace.A[4085] = acadoWorkspace.evHu[23];
acadoWorkspace.A[4166] = acadoWorkspace.evHu[24];
acadoWorkspace.A[4167] = acadoWorkspace.evHu[25];
acadoWorkspace.A[4246] = acadoWorkspace.evHu[26];
acadoWorkspace.A[4247] = acadoWorkspace.evHu[27];
acadoWorkspace.A[4326] = acadoWorkspace.evHu[28];
acadoWorkspace.A[4327] = acadoWorkspace.evHu[29];
acadoWorkspace.A[4406] = acadoWorkspace.evHu[30];
acadoWorkspace.A[4407] = acadoWorkspace.evHu[31];
acadoWorkspace.A[4488] = acadoWorkspace.evHu[32];
acadoWorkspace.A[4489] = acadoWorkspace.evHu[33];
acadoWorkspace.A[4568] = acadoWorkspace.evHu[34];
acadoWorkspace.A[4569] = acadoWorkspace.evHu[35];
acadoWorkspace.A[4648] = acadoWorkspace.evHu[36];
acadoWorkspace.A[4649] = acadoWorkspace.evHu[37];
acadoWorkspace.A[4728] = acadoWorkspace.evHu[38];
acadoWorkspace.A[4729] = acadoWorkspace.evHu[39];
acadoWorkspace.A[4810] = acadoWorkspace.evHu[40];
acadoWorkspace.A[4811] = acadoWorkspace.evHu[41];
acadoWorkspace.A[4890] = acadoWorkspace.evHu[42];
acadoWorkspace.A[4891] = acadoWorkspace.evHu[43];
acadoWorkspace.A[4970] = acadoWorkspace.evHu[44];
acadoWorkspace.A[4971] = acadoWorkspace.evHu[45];
acadoWorkspace.A[5050] = acadoWorkspace.evHu[46];
acadoWorkspace.A[5051] = acadoWorkspace.evHu[47];
acadoWorkspace.A[5132] = acadoWorkspace.evHu[48];
acadoWorkspace.A[5133] = acadoWorkspace.evHu[49];
acadoWorkspace.A[5212] = acadoWorkspace.evHu[50];
acadoWorkspace.A[5213] = acadoWorkspace.evHu[51];
acadoWorkspace.A[5292] = acadoWorkspace.evHu[52];
acadoWorkspace.A[5293] = acadoWorkspace.evHu[53];
acadoWorkspace.A[5372] = acadoWorkspace.evHu[54];
acadoWorkspace.A[5373] = acadoWorkspace.evHu[55];
acadoWorkspace.A[5454] = acadoWorkspace.evHu[56];
acadoWorkspace.A[5455] = acadoWorkspace.evHu[57];
acadoWorkspace.A[5534] = acadoWorkspace.evHu[58];
acadoWorkspace.A[5535] = acadoWorkspace.evHu[59];
acadoWorkspace.A[5614] = acadoWorkspace.evHu[60];
acadoWorkspace.A[5615] = acadoWorkspace.evHu[61];
acadoWorkspace.A[5694] = acadoWorkspace.evHu[62];
acadoWorkspace.A[5695] = acadoWorkspace.evHu[63];
acadoWorkspace.A[5776] = acadoWorkspace.evHu[64];
acadoWorkspace.A[5777] = acadoWorkspace.evHu[65];
acadoWorkspace.A[5856] = acadoWorkspace.evHu[66];
acadoWorkspace.A[5857] = acadoWorkspace.evHu[67];
acadoWorkspace.A[5936] = acadoWorkspace.evHu[68];
acadoWorkspace.A[5937] = acadoWorkspace.evHu[69];
acadoWorkspace.A[6016] = acadoWorkspace.evHu[70];
acadoWorkspace.A[6017] = acadoWorkspace.evHu[71];
acadoWorkspace.A[6098] = acadoWorkspace.evHu[72];
acadoWorkspace.A[6099] = acadoWorkspace.evHu[73];
acadoWorkspace.A[6178] = acadoWorkspace.evHu[74];
acadoWorkspace.A[6179] = acadoWorkspace.evHu[75];
acadoWorkspace.A[6258] = acadoWorkspace.evHu[76];
acadoWorkspace.A[6259] = acadoWorkspace.evHu[77];
acadoWorkspace.A[6338] = acadoWorkspace.evHu[78];
acadoWorkspace.A[6339] = acadoWorkspace.evHu[79];
acadoWorkspace.A[6420] = acadoWorkspace.evHu[80];
acadoWorkspace.A[6421] = acadoWorkspace.evHu[81];
acadoWorkspace.A[6500] = acadoWorkspace.evHu[82];
acadoWorkspace.A[6501] = acadoWorkspace.evHu[83];
acadoWorkspace.A[6580] = acadoWorkspace.evHu[84];
acadoWorkspace.A[6581] = acadoWorkspace.evHu[85];
acadoWorkspace.A[6660] = acadoWorkspace.evHu[86];
acadoWorkspace.A[6661] = acadoWorkspace.evHu[87];
acadoWorkspace.A[6742] = acadoWorkspace.evHu[88];
acadoWorkspace.A[6743] = acadoWorkspace.evHu[89];
acadoWorkspace.A[6822] = acadoWorkspace.evHu[90];
acadoWorkspace.A[6823] = acadoWorkspace.evHu[91];
acadoWorkspace.A[6902] = acadoWorkspace.evHu[92];
acadoWorkspace.A[6903] = acadoWorkspace.evHu[93];
acadoWorkspace.A[6982] = acadoWorkspace.evHu[94];
acadoWorkspace.A[6983] = acadoWorkspace.evHu[95];
acadoWorkspace.A[7064] = acadoWorkspace.evHu[96];
acadoWorkspace.A[7065] = acadoWorkspace.evHu[97];
acadoWorkspace.A[7144] = acadoWorkspace.evHu[98];
acadoWorkspace.A[7145] = acadoWorkspace.evHu[99];
acadoWorkspace.A[7224] = acadoWorkspace.evHu[100];
acadoWorkspace.A[7225] = acadoWorkspace.evHu[101];
acadoWorkspace.A[7304] = acadoWorkspace.evHu[102];
acadoWorkspace.A[7305] = acadoWorkspace.evHu[103];
acadoWorkspace.A[7386] = acadoWorkspace.evHu[104];
acadoWorkspace.A[7387] = acadoWorkspace.evHu[105];
acadoWorkspace.A[7466] = acadoWorkspace.evHu[106];
acadoWorkspace.A[7467] = acadoWorkspace.evHu[107];
acadoWorkspace.A[7546] = acadoWorkspace.evHu[108];
acadoWorkspace.A[7547] = acadoWorkspace.evHu[109];
acadoWorkspace.A[7626] = acadoWorkspace.evHu[110];
acadoWorkspace.A[7627] = acadoWorkspace.evHu[111];
acadoWorkspace.A[7708] = acadoWorkspace.evHu[112];
acadoWorkspace.A[7709] = acadoWorkspace.evHu[113];
acadoWorkspace.A[7788] = acadoWorkspace.evHu[114];
acadoWorkspace.A[7789] = acadoWorkspace.evHu[115];
acadoWorkspace.A[7868] = acadoWorkspace.evHu[116];
acadoWorkspace.A[7869] = acadoWorkspace.evHu[117];
acadoWorkspace.A[7948] = acadoWorkspace.evHu[118];
acadoWorkspace.A[7949] = acadoWorkspace.evHu[119];
acadoWorkspace.A[8030] = acadoWorkspace.evHu[120];
acadoWorkspace.A[8031] = acadoWorkspace.evHu[121];
acadoWorkspace.A[8110] = acadoWorkspace.evHu[122];
acadoWorkspace.A[8111] = acadoWorkspace.evHu[123];
acadoWorkspace.A[8190] = acadoWorkspace.evHu[124];
acadoWorkspace.A[8191] = acadoWorkspace.evHu[125];
acadoWorkspace.A[8270] = acadoWorkspace.evHu[126];
acadoWorkspace.A[8271] = acadoWorkspace.evHu[127];
acadoWorkspace.A[8352] = acadoWorkspace.evHu[128];
acadoWorkspace.A[8353] = acadoWorkspace.evHu[129];
acadoWorkspace.A[8432] = acadoWorkspace.evHu[130];
acadoWorkspace.A[8433] = acadoWorkspace.evHu[131];
acadoWorkspace.A[8512] = acadoWorkspace.evHu[132];
acadoWorkspace.A[8513] = acadoWorkspace.evHu[133];
acadoWorkspace.A[8592] = acadoWorkspace.evHu[134];
acadoWorkspace.A[8593] = acadoWorkspace.evHu[135];
acadoWorkspace.A[8674] = acadoWorkspace.evHu[136];
acadoWorkspace.A[8675] = acadoWorkspace.evHu[137];
acadoWorkspace.A[8754] = acadoWorkspace.evHu[138];
acadoWorkspace.A[8755] = acadoWorkspace.evHu[139];
acadoWorkspace.A[8834] = acadoWorkspace.evHu[140];
acadoWorkspace.A[8835] = acadoWorkspace.evHu[141];
acadoWorkspace.A[8914] = acadoWorkspace.evHu[142];
acadoWorkspace.A[8915] = acadoWorkspace.evHu[143];
acadoWorkspace.A[8996] = acadoWorkspace.evHu[144];
acadoWorkspace.A[8997] = acadoWorkspace.evHu[145];
acadoWorkspace.A[9076] = acadoWorkspace.evHu[146];
acadoWorkspace.A[9077] = acadoWorkspace.evHu[147];
acadoWorkspace.A[9156] = acadoWorkspace.evHu[148];
acadoWorkspace.A[9157] = acadoWorkspace.evHu[149];
acadoWorkspace.A[9236] = acadoWorkspace.evHu[150];
acadoWorkspace.A[9237] = acadoWorkspace.evHu[151];
acadoWorkspace.A[9318] = acadoWorkspace.evHu[152];
acadoWorkspace.A[9319] = acadoWorkspace.evHu[153];
acadoWorkspace.A[9398] = acadoWorkspace.evHu[154];
acadoWorkspace.A[9399] = acadoWorkspace.evHu[155];
acadoWorkspace.A[9478] = acadoWorkspace.evHu[156];
acadoWorkspace.A[9479] = acadoWorkspace.evHu[157];
acadoWorkspace.A[9558] = acadoWorkspace.evHu[158];
acadoWorkspace.A[9559] = acadoWorkspace.evHu[159];
acadoWorkspace.A[9640] = acadoWorkspace.evHu[160];
acadoWorkspace.A[9641] = acadoWorkspace.evHu[161];
acadoWorkspace.A[9720] = acadoWorkspace.evHu[162];
acadoWorkspace.A[9721] = acadoWorkspace.evHu[163];
acadoWorkspace.A[9800] = acadoWorkspace.evHu[164];
acadoWorkspace.A[9801] = acadoWorkspace.evHu[165];
acadoWorkspace.A[9880] = acadoWorkspace.evHu[166];
acadoWorkspace.A[9881] = acadoWorkspace.evHu[167];
acadoWorkspace.A[9962] = acadoWorkspace.evHu[168];
acadoWorkspace.A[9963] = acadoWorkspace.evHu[169];
acadoWorkspace.A[10042] = acadoWorkspace.evHu[170];
acadoWorkspace.A[10043] = acadoWorkspace.evHu[171];
acadoWorkspace.A[10122] = acadoWorkspace.evHu[172];
acadoWorkspace.A[10123] = acadoWorkspace.evHu[173];
acadoWorkspace.A[10202] = acadoWorkspace.evHu[174];
acadoWorkspace.A[10203] = acadoWorkspace.evHu[175];
acadoWorkspace.A[10284] = acadoWorkspace.evHu[176];
acadoWorkspace.A[10285] = acadoWorkspace.evHu[177];
acadoWorkspace.A[10364] = acadoWorkspace.evHu[178];
acadoWorkspace.A[10365] = acadoWorkspace.evHu[179];
acadoWorkspace.A[10444] = acadoWorkspace.evHu[180];
acadoWorkspace.A[10445] = acadoWorkspace.evHu[181];
acadoWorkspace.A[10524] = acadoWorkspace.evHu[182];
acadoWorkspace.A[10525] = acadoWorkspace.evHu[183];
acadoWorkspace.A[10606] = acadoWorkspace.evHu[184];
acadoWorkspace.A[10607] = acadoWorkspace.evHu[185];
acadoWorkspace.A[10686] = acadoWorkspace.evHu[186];
acadoWorkspace.A[10687] = acadoWorkspace.evHu[187];
acadoWorkspace.A[10766] = acadoWorkspace.evHu[188];
acadoWorkspace.A[10767] = acadoWorkspace.evHu[189];
acadoWorkspace.A[10846] = acadoWorkspace.evHu[190];
acadoWorkspace.A[10847] = acadoWorkspace.evHu[191];
acadoWorkspace.A[10928] = acadoWorkspace.evHu[192];
acadoWorkspace.A[10929] = acadoWorkspace.evHu[193];
acadoWorkspace.A[11008] = acadoWorkspace.evHu[194];
acadoWorkspace.A[11009] = acadoWorkspace.evHu[195];
acadoWorkspace.A[11088] = acadoWorkspace.evHu[196];
acadoWorkspace.A[11089] = acadoWorkspace.evHu[197];
acadoWorkspace.A[11168] = acadoWorkspace.evHu[198];
acadoWorkspace.A[11169] = acadoWorkspace.evHu[199];
acadoWorkspace.A[11250] = acadoWorkspace.evHu[200];
acadoWorkspace.A[11251] = acadoWorkspace.evHu[201];
acadoWorkspace.A[11330] = acadoWorkspace.evHu[202];
acadoWorkspace.A[11331] = acadoWorkspace.evHu[203];
acadoWorkspace.A[11410] = acadoWorkspace.evHu[204];
acadoWorkspace.A[11411] = acadoWorkspace.evHu[205];
acadoWorkspace.A[11490] = acadoWorkspace.evHu[206];
acadoWorkspace.A[11491] = acadoWorkspace.evHu[207];
acadoWorkspace.A[11572] = acadoWorkspace.evHu[208];
acadoWorkspace.A[11573] = acadoWorkspace.evHu[209];
acadoWorkspace.A[11652] = acadoWorkspace.evHu[210];
acadoWorkspace.A[11653] = acadoWorkspace.evHu[211];
acadoWorkspace.A[11732] = acadoWorkspace.evHu[212];
acadoWorkspace.A[11733] = acadoWorkspace.evHu[213];
acadoWorkspace.A[11812] = acadoWorkspace.evHu[214];
acadoWorkspace.A[11813] = acadoWorkspace.evHu[215];
acadoWorkspace.A[11894] = acadoWorkspace.evHu[216];
acadoWorkspace.A[11895] = acadoWorkspace.evHu[217];
acadoWorkspace.A[11974] = acadoWorkspace.evHu[218];
acadoWorkspace.A[11975] = acadoWorkspace.evHu[219];
acadoWorkspace.A[12054] = acadoWorkspace.evHu[220];
acadoWorkspace.A[12055] = acadoWorkspace.evHu[221];
acadoWorkspace.A[12134] = acadoWorkspace.evHu[222];
acadoWorkspace.A[12135] = acadoWorkspace.evHu[223];
acadoWorkspace.A[12216] = acadoWorkspace.evHu[224];
acadoWorkspace.A[12217] = acadoWorkspace.evHu[225];
acadoWorkspace.A[12296] = acadoWorkspace.evHu[226];
acadoWorkspace.A[12297] = acadoWorkspace.evHu[227];
acadoWorkspace.A[12376] = acadoWorkspace.evHu[228];
acadoWorkspace.A[12377] = acadoWorkspace.evHu[229];
acadoWorkspace.A[12456] = acadoWorkspace.evHu[230];
acadoWorkspace.A[12457] = acadoWorkspace.evHu[231];
acadoWorkspace.A[12538] = acadoWorkspace.evHu[232];
acadoWorkspace.A[12539] = acadoWorkspace.evHu[233];
acadoWorkspace.A[12618] = acadoWorkspace.evHu[234];
acadoWorkspace.A[12619] = acadoWorkspace.evHu[235];
acadoWorkspace.A[12698] = acadoWorkspace.evHu[236];
acadoWorkspace.A[12699] = acadoWorkspace.evHu[237];
acadoWorkspace.A[12778] = acadoWorkspace.evHu[238];
acadoWorkspace.A[12779] = acadoWorkspace.evHu[239];
acadoWorkspace.A[12860] = acadoWorkspace.evHu[240];
acadoWorkspace.A[12861] = acadoWorkspace.evHu[241];
acadoWorkspace.A[12940] = acadoWorkspace.evHu[242];
acadoWorkspace.A[12941] = acadoWorkspace.evHu[243];
acadoWorkspace.A[13020] = acadoWorkspace.evHu[244];
acadoWorkspace.A[13021] = acadoWorkspace.evHu[245];
acadoWorkspace.A[13100] = acadoWorkspace.evHu[246];
acadoWorkspace.A[13101] = acadoWorkspace.evHu[247];
acadoWorkspace.A[13182] = acadoWorkspace.evHu[248];
acadoWorkspace.A[13183] = acadoWorkspace.evHu[249];
acadoWorkspace.A[13262] = acadoWorkspace.evHu[250];
acadoWorkspace.A[13263] = acadoWorkspace.evHu[251];
acadoWorkspace.A[13342] = acadoWorkspace.evHu[252];
acadoWorkspace.A[13343] = acadoWorkspace.evHu[253];
acadoWorkspace.A[13422] = acadoWorkspace.evHu[254];
acadoWorkspace.A[13423] = acadoWorkspace.evHu[255];
acadoWorkspace.A[13504] = acadoWorkspace.evHu[256];
acadoWorkspace.A[13505] = acadoWorkspace.evHu[257];
acadoWorkspace.A[13584] = acadoWorkspace.evHu[258];
acadoWorkspace.A[13585] = acadoWorkspace.evHu[259];
acadoWorkspace.A[13664] = acadoWorkspace.evHu[260];
acadoWorkspace.A[13665] = acadoWorkspace.evHu[261];
acadoWorkspace.A[13744] = acadoWorkspace.evHu[262];
acadoWorkspace.A[13745] = acadoWorkspace.evHu[263];
acadoWorkspace.A[13826] = acadoWorkspace.evHu[264];
acadoWorkspace.A[13827] = acadoWorkspace.evHu[265];
acadoWorkspace.A[13906] = acadoWorkspace.evHu[266];
acadoWorkspace.A[13907] = acadoWorkspace.evHu[267];
acadoWorkspace.A[13986] = acadoWorkspace.evHu[268];
acadoWorkspace.A[13987] = acadoWorkspace.evHu[269];
acadoWorkspace.A[14066] = acadoWorkspace.evHu[270];
acadoWorkspace.A[14067] = acadoWorkspace.evHu[271];
acadoWorkspace.A[14148] = acadoWorkspace.evHu[272];
acadoWorkspace.A[14149] = acadoWorkspace.evHu[273];
acadoWorkspace.A[14228] = acadoWorkspace.evHu[274];
acadoWorkspace.A[14229] = acadoWorkspace.evHu[275];
acadoWorkspace.A[14308] = acadoWorkspace.evHu[276];
acadoWorkspace.A[14309] = acadoWorkspace.evHu[277];
acadoWorkspace.A[14388] = acadoWorkspace.evHu[278];
acadoWorkspace.A[14389] = acadoWorkspace.evHu[279];
acadoWorkspace.A[14470] = acadoWorkspace.evHu[280];
acadoWorkspace.A[14471] = acadoWorkspace.evHu[281];
acadoWorkspace.A[14550] = acadoWorkspace.evHu[282];
acadoWorkspace.A[14551] = acadoWorkspace.evHu[283];
acadoWorkspace.A[14630] = acadoWorkspace.evHu[284];
acadoWorkspace.A[14631] = acadoWorkspace.evHu[285];
acadoWorkspace.A[14710] = acadoWorkspace.evHu[286];
acadoWorkspace.A[14711] = acadoWorkspace.evHu[287];
acadoWorkspace.A[14792] = acadoWorkspace.evHu[288];
acadoWorkspace.A[14793] = acadoWorkspace.evHu[289];
acadoWorkspace.A[14872] = acadoWorkspace.evHu[290];
acadoWorkspace.A[14873] = acadoWorkspace.evHu[291];
acadoWorkspace.A[14952] = acadoWorkspace.evHu[292];
acadoWorkspace.A[14953] = acadoWorkspace.evHu[293];
acadoWorkspace.A[15032] = acadoWorkspace.evHu[294];
acadoWorkspace.A[15033] = acadoWorkspace.evHu[295];
acadoWorkspace.A[15114] = acadoWorkspace.evHu[296];
acadoWorkspace.A[15115] = acadoWorkspace.evHu[297];
acadoWorkspace.A[15194] = acadoWorkspace.evHu[298];
acadoWorkspace.A[15195] = acadoWorkspace.evHu[299];
acadoWorkspace.A[15274] = acadoWorkspace.evHu[300];
acadoWorkspace.A[15275] = acadoWorkspace.evHu[301];
acadoWorkspace.A[15354] = acadoWorkspace.evHu[302];
acadoWorkspace.A[15355] = acadoWorkspace.evHu[303];
acadoWorkspace.A[15436] = acadoWorkspace.evHu[304];
acadoWorkspace.A[15437] = acadoWorkspace.evHu[305];
acadoWorkspace.A[15516] = acadoWorkspace.evHu[306];
acadoWorkspace.A[15517] = acadoWorkspace.evHu[307];
acadoWorkspace.A[15596] = acadoWorkspace.evHu[308];
acadoWorkspace.A[15597] = acadoWorkspace.evHu[309];
acadoWorkspace.A[15676] = acadoWorkspace.evHu[310];
acadoWorkspace.A[15677] = acadoWorkspace.evHu[311];
acadoWorkspace.A[15758] = acadoWorkspace.evHu[312];
acadoWorkspace.A[15759] = acadoWorkspace.evHu[313];
acadoWorkspace.A[15838] = acadoWorkspace.evHu[314];
acadoWorkspace.A[15839] = acadoWorkspace.evHu[315];
acadoWorkspace.A[15918] = acadoWorkspace.evHu[316];
acadoWorkspace.A[15919] = acadoWorkspace.evHu[317];
acadoWorkspace.A[15998] = acadoWorkspace.evHu[318];
acadoWorkspace.A[15999] = acadoWorkspace.evHu[319];
acadoWorkspace.lbA[40] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[0];
acadoWorkspace.lbA[41] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[1];
acadoWorkspace.lbA[42] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[2];
acadoWorkspace.lbA[43] = - acadoWorkspace.evH[3];
acadoWorkspace.lbA[44] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[4];
acadoWorkspace.lbA[45] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[5];
acadoWorkspace.lbA[46] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[6];
acadoWorkspace.lbA[47] = - acadoWorkspace.evH[7];
acadoWorkspace.lbA[48] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[8];
acadoWorkspace.lbA[49] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[9];
acadoWorkspace.lbA[50] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[10];
acadoWorkspace.lbA[51] = - acadoWorkspace.evH[11];
acadoWorkspace.lbA[52] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[12];
acadoWorkspace.lbA[53] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[13];
acadoWorkspace.lbA[54] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[14];
acadoWorkspace.lbA[55] = - acadoWorkspace.evH[15];
acadoWorkspace.lbA[56] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[16];
acadoWorkspace.lbA[57] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[17];
acadoWorkspace.lbA[58] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[18];
acadoWorkspace.lbA[59] = - acadoWorkspace.evH[19];
acadoWorkspace.lbA[60] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[20];
acadoWorkspace.lbA[61] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[21];
acadoWorkspace.lbA[62] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[22];
acadoWorkspace.lbA[63] = - acadoWorkspace.evH[23];
acadoWorkspace.lbA[64] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[24];
acadoWorkspace.lbA[65] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[25];
acadoWorkspace.lbA[66] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[26];
acadoWorkspace.lbA[67] = - acadoWorkspace.evH[27];
acadoWorkspace.lbA[68] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[28];
acadoWorkspace.lbA[69] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[29];
acadoWorkspace.lbA[70] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[30];
acadoWorkspace.lbA[71] = - acadoWorkspace.evH[31];
acadoWorkspace.lbA[72] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[32];
acadoWorkspace.lbA[73] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[33];
acadoWorkspace.lbA[74] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[34];
acadoWorkspace.lbA[75] = - acadoWorkspace.evH[35];
acadoWorkspace.lbA[76] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[36];
acadoWorkspace.lbA[77] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[37];
acadoWorkspace.lbA[78] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[38];
acadoWorkspace.lbA[79] = - acadoWorkspace.evH[39];
acadoWorkspace.lbA[80] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[40];
acadoWorkspace.lbA[81] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[41];
acadoWorkspace.lbA[82] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[42];
acadoWorkspace.lbA[83] = - acadoWorkspace.evH[43];
acadoWorkspace.lbA[84] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[44];
acadoWorkspace.lbA[85] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[45];
acadoWorkspace.lbA[86] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[46];
acadoWorkspace.lbA[87] = - acadoWorkspace.evH[47];
acadoWorkspace.lbA[88] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[48];
acadoWorkspace.lbA[89] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[49];
acadoWorkspace.lbA[90] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[50];
acadoWorkspace.lbA[91] = - acadoWorkspace.evH[51];
acadoWorkspace.lbA[92] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[52];
acadoWorkspace.lbA[93] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[53];
acadoWorkspace.lbA[94] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[54];
acadoWorkspace.lbA[95] = - acadoWorkspace.evH[55];
acadoWorkspace.lbA[96] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[56];
acadoWorkspace.lbA[97] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[57];
acadoWorkspace.lbA[98] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[58];
acadoWorkspace.lbA[99] = - acadoWorkspace.evH[59];
acadoWorkspace.lbA[100] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[60];
acadoWorkspace.lbA[101] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[61];
acadoWorkspace.lbA[102] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[62];
acadoWorkspace.lbA[103] = - acadoWorkspace.evH[63];
acadoWorkspace.lbA[104] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[64];
acadoWorkspace.lbA[105] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[65];
acadoWorkspace.lbA[106] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[66];
acadoWorkspace.lbA[107] = - acadoWorkspace.evH[67];
acadoWorkspace.lbA[108] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[68];
acadoWorkspace.lbA[109] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[69];
acadoWorkspace.lbA[110] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[70];
acadoWorkspace.lbA[111] = - acadoWorkspace.evH[71];
acadoWorkspace.lbA[112] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[72];
acadoWorkspace.lbA[113] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[73];
acadoWorkspace.lbA[114] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[74];
acadoWorkspace.lbA[115] = - acadoWorkspace.evH[75];
acadoWorkspace.lbA[116] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[76];
acadoWorkspace.lbA[117] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[77];
acadoWorkspace.lbA[118] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[78];
acadoWorkspace.lbA[119] = - acadoWorkspace.evH[79];
acadoWorkspace.lbA[120] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[80];
acadoWorkspace.lbA[121] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[81];
acadoWorkspace.lbA[122] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[82];
acadoWorkspace.lbA[123] = - acadoWorkspace.evH[83];
acadoWorkspace.lbA[124] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[84];
acadoWorkspace.lbA[125] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[85];
acadoWorkspace.lbA[126] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[86];
acadoWorkspace.lbA[127] = - acadoWorkspace.evH[87];
acadoWorkspace.lbA[128] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[88];
acadoWorkspace.lbA[129] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[89];
acadoWorkspace.lbA[130] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[90];
acadoWorkspace.lbA[131] = - acadoWorkspace.evH[91];
acadoWorkspace.lbA[132] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[92];
acadoWorkspace.lbA[133] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[93];
acadoWorkspace.lbA[134] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[94];
acadoWorkspace.lbA[135] = - acadoWorkspace.evH[95];
acadoWorkspace.lbA[136] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[96];
acadoWorkspace.lbA[137] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[97];
acadoWorkspace.lbA[138] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[98];
acadoWorkspace.lbA[139] = - acadoWorkspace.evH[99];
acadoWorkspace.lbA[140] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[100];
acadoWorkspace.lbA[141] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[101];
acadoWorkspace.lbA[142] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[102];
acadoWorkspace.lbA[143] = - acadoWorkspace.evH[103];
acadoWorkspace.lbA[144] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[104];
acadoWorkspace.lbA[145] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[105];
acadoWorkspace.lbA[146] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[106];
acadoWorkspace.lbA[147] = - acadoWorkspace.evH[107];
acadoWorkspace.lbA[148] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[108];
acadoWorkspace.lbA[149] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[109];
acadoWorkspace.lbA[150] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[110];
acadoWorkspace.lbA[151] = - acadoWorkspace.evH[111];
acadoWorkspace.lbA[152] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[112];
acadoWorkspace.lbA[153] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[113];
acadoWorkspace.lbA[154] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[114];
acadoWorkspace.lbA[155] = - acadoWorkspace.evH[115];
acadoWorkspace.lbA[156] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[116];
acadoWorkspace.lbA[157] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[117];
acadoWorkspace.lbA[158] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[118];
acadoWorkspace.lbA[159] = - acadoWorkspace.evH[119];
acadoWorkspace.lbA[160] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[120];
acadoWorkspace.lbA[161] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[121];
acadoWorkspace.lbA[162] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[122];
acadoWorkspace.lbA[163] = - acadoWorkspace.evH[123];
acadoWorkspace.lbA[164] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[124];
acadoWorkspace.lbA[165] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[125];
acadoWorkspace.lbA[166] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[126];
acadoWorkspace.lbA[167] = - acadoWorkspace.evH[127];
acadoWorkspace.lbA[168] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[128];
acadoWorkspace.lbA[169] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[129];
acadoWorkspace.lbA[170] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[130];
acadoWorkspace.lbA[171] = - acadoWorkspace.evH[131];
acadoWorkspace.lbA[172] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[132];
acadoWorkspace.lbA[173] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[133];
acadoWorkspace.lbA[174] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[134];
acadoWorkspace.lbA[175] = - acadoWorkspace.evH[135];
acadoWorkspace.lbA[176] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[136];
acadoWorkspace.lbA[177] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[137];
acadoWorkspace.lbA[178] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[138];
acadoWorkspace.lbA[179] = - acadoWorkspace.evH[139];
acadoWorkspace.lbA[180] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[140];
acadoWorkspace.lbA[181] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[141];
acadoWorkspace.lbA[182] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[142];
acadoWorkspace.lbA[183] = - acadoWorkspace.evH[143];
acadoWorkspace.lbA[184] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[144];
acadoWorkspace.lbA[185] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[145];
acadoWorkspace.lbA[186] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[146];
acadoWorkspace.lbA[187] = - acadoWorkspace.evH[147];
acadoWorkspace.lbA[188] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[148];
acadoWorkspace.lbA[189] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[149];
acadoWorkspace.lbA[190] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[150];
acadoWorkspace.lbA[191] = - acadoWorkspace.evH[151];
acadoWorkspace.lbA[192] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[152];
acadoWorkspace.lbA[193] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[153];
acadoWorkspace.lbA[194] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[154];
acadoWorkspace.lbA[195] = - acadoWorkspace.evH[155];
acadoWorkspace.lbA[196] = (real_t)-8.7266462599716474e-02 - acadoWorkspace.evH[156];
acadoWorkspace.lbA[197] = (real_t)-4.3633231299858238e-01 - acadoWorkspace.evH[157];
acadoWorkspace.lbA[198] = (real_t)-8.3384999999999998e+00 - acadoWorkspace.evH[158];
acadoWorkspace.lbA[199] = - acadoWorkspace.evH[159];

acadoWorkspace.ubA[40] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[0];
acadoWorkspace.ubA[41] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[1];
acadoWorkspace.ubA[42] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[2];
acadoWorkspace.ubA[43] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[3];
acadoWorkspace.ubA[44] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[4];
acadoWorkspace.ubA[45] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[5];
acadoWorkspace.ubA[46] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[6];
acadoWorkspace.ubA[47] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[7];
acadoWorkspace.ubA[48] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[8];
acadoWorkspace.ubA[49] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[9];
acadoWorkspace.ubA[50] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[10];
acadoWorkspace.ubA[51] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[11];
acadoWorkspace.ubA[52] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[12];
acadoWorkspace.ubA[53] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[13];
acadoWorkspace.ubA[54] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[14];
acadoWorkspace.ubA[55] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[15];
acadoWorkspace.ubA[56] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[16];
acadoWorkspace.ubA[57] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[17];
acadoWorkspace.ubA[58] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[18];
acadoWorkspace.ubA[59] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[19];
acadoWorkspace.ubA[60] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[20];
acadoWorkspace.ubA[61] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[21];
acadoWorkspace.ubA[62] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[22];
acadoWorkspace.ubA[63] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[23];
acadoWorkspace.ubA[64] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[24];
acadoWorkspace.ubA[65] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[25];
acadoWorkspace.ubA[66] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[26];
acadoWorkspace.ubA[67] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[27];
acadoWorkspace.ubA[68] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[28];
acadoWorkspace.ubA[69] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[29];
acadoWorkspace.ubA[70] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[30];
acadoWorkspace.ubA[71] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[31];
acadoWorkspace.ubA[72] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[32];
acadoWorkspace.ubA[73] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[33];
acadoWorkspace.ubA[74] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[34];
acadoWorkspace.ubA[75] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[35];
acadoWorkspace.ubA[76] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[36];
acadoWorkspace.ubA[77] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[37];
acadoWorkspace.ubA[78] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[38];
acadoWorkspace.ubA[79] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[39];
acadoWorkspace.ubA[80] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[40];
acadoWorkspace.ubA[81] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[41];
acadoWorkspace.ubA[82] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[42];
acadoWorkspace.ubA[83] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[43];
acadoWorkspace.ubA[84] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[44];
acadoWorkspace.ubA[85] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[45];
acadoWorkspace.ubA[86] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[46];
acadoWorkspace.ubA[87] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[47];
acadoWorkspace.ubA[88] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[48];
acadoWorkspace.ubA[89] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[49];
acadoWorkspace.ubA[90] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[50];
acadoWorkspace.ubA[91] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[51];
acadoWorkspace.ubA[92] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[52];
acadoWorkspace.ubA[93] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[53];
acadoWorkspace.ubA[94] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[54];
acadoWorkspace.ubA[95] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[55];
acadoWorkspace.ubA[96] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[56];
acadoWorkspace.ubA[97] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[57];
acadoWorkspace.ubA[98] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[58];
acadoWorkspace.ubA[99] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[59];
acadoWorkspace.ubA[100] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[60];
acadoWorkspace.ubA[101] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[61];
acadoWorkspace.ubA[102] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[62];
acadoWorkspace.ubA[103] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[63];
acadoWorkspace.ubA[104] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[64];
acadoWorkspace.ubA[105] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[65];
acadoWorkspace.ubA[106] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[66];
acadoWorkspace.ubA[107] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[67];
acadoWorkspace.ubA[108] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[68];
acadoWorkspace.ubA[109] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[69];
acadoWorkspace.ubA[110] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[70];
acadoWorkspace.ubA[111] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[71];
acadoWorkspace.ubA[112] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[72];
acadoWorkspace.ubA[113] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[73];
acadoWorkspace.ubA[114] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[74];
acadoWorkspace.ubA[115] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[75];
acadoWorkspace.ubA[116] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[76];
acadoWorkspace.ubA[117] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[77];
acadoWorkspace.ubA[118] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[78];
acadoWorkspace.ubA[119] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[79];
acadoWorkspace.ubA[120] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[80];
acadoWorkspace.ubA[121] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[81];
acadoWorkspace.ubA[122] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[82];
acadoWorkspace.ubA[123] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[83];
acadoWorkspace.ubA[124] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[84];
acadoWorkspace.ubA[125] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[85];
acadoWorkspace.ubA[126] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[86];
acadoWorkspace.ubA[127] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[87];
acadoWorkspace.ubA[128] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[88];
acadoWorkspace.ubA[129] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[89];
acadoWorkspace.ubA[130] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[90];
acadoWorkspace.ubA[131] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[91];
acadoWorkspace.ubA[132] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[92];
acadoWorkspace.ubA[133] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[93];
acadoWorkspace.ubA[134] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[94];
acadoWorkspace.ubA[135] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[95];
acadoWorkspace.ubA[136] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[96];
acadoWorkspace.ubA[137] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[97];
acadoWorkspace.ubA[138] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[98];
acadoWorkspace.ubA[139] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[99];
acadoWorkspace.ubA[140] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[100];
acadoWorkspace.ubA[141] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[101];
acadoWorkspace.ubA[142] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[102];
acadoWorkspace.ubA[143] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[103];
acadoWorkspace.ubA[144] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[104];
acadoWorkspace.ubA[145] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[105];
acadoWorkspace.ubA[146] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[106];
acadoWorkspace.ubA[147] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[107];
acadoWorkspace.ubA[148] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[108];
acadoWorkspace.ubA[149] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[109];
acadoWorkspace.ubA[150] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[110];
acadoWorkspace.ubA[151] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[111];
acadoWorkspace.ubA[152] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[112];
acadoWorkspace.ubA[153] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[113];
acadoWorkspace.ubA[154] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[114];
acadoWorkspace.ubA[155] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[115];
acadoWorkspace.ubA[156] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[116];
acadoWorkspace.ubA[157] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[117];
acadoWorkspace.ubA[158] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[118];
acadoWorkspace.ubA[159] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[119];
acadoWorkspace.ubA[160] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[120];
acadoWorkspace.ubA[161] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[121];
acadoWorkspace.ubA[162] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[122];
acadoWorkspace.ubA[163] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[123];
acadoWorkspace.ubA[164] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[124];
acadoWorkspace.ubA[165] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[125];
acadoWorkspace.ubA[166] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[126];
acadoWorkspace.ubA[167] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[127];
acadoWorkspace.ubA[168] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[128];
acadoWorkspace.ubA[169] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[129];
acadoWorkspace.ubA[170] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[130];
acadoWorkspace.ubA[171] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[131];
acadoWorkspace.ubA[172] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[132];
acadoWorkspace.ubA[173] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[133];
acadoWorkspace.ubA[174] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[134];
acadoWorkspace.ubA[175] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[135];
acadoWorkspace.ubA[176] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[136];
acadoWorkspace.ubA[177] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[137];
acadoWorkspace.ubA[178] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[138];
acadoWorkspace.ubA[179] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[139];
acadoWorkspace.ubA[180] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[140];
acadoWorkspace.ubA[181] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[141];
acadoWorkspace.ubA[182] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[142];
acadoWorkspace.ubA[183] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[143];
acadoWorkspace.ubA[184] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[144];
acadoWorkspace.ubA[185] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[145];
acadoWorkspace.ubA[186] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[146];
acadoWorkspace.ubA[187] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[147];
acadoWorkspace.ubA[188] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[148];
acadoWorkspace.ubA[189] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[149];
acadoWorkspace.ubA[190] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[150];
acadoWorkspace.ubA[191] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[151];
acadoWorkspace.ubA[192] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[152];
acadoWorkspace.ubA[193] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[153];
acadoWorkspace.ubA[194] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[154];
acadoWorkspace.ubA[195] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[155];
acadoWorkspace.ubA[196] = (real_t)8.7266462599716474e-02 - acadoWorkspace.evH[156];
acadoWorkspace.ubA[197] = (real_t)4.3633231299858238e-01 - acadoWorkspace.evH[157];
acadoWorkspace.ubA[198] = (real_t)8.3384999999999998e+00 - acadoWorkspace.evH[158];
acadoWorkspace.ubA[199] = (real_t)1.0000000000000000e+12 - acadoWorkspace.evH[159];

}

void acado_condenseFdb(  )
{
int lRun1;
real_t tmp;

acadoWorkspace.Dx0[0] = acadoVariables.x0[0] - acadoVariables.x[0];
acadoWorkspace.Dx0[1] = acadoVariables.x0[1] - acadoVariables.x[1];
acadoWorkspace.Dx0[2] = acadoVariables.x0[2] - acadoVariables.x[2];
acadoWorkspace.Dx0[3] = acadoVariables.x0[3] - acadoVariables.x[3];
acadoWorkspace.Dx0[4] = acadoVariables.x0[4] - acadoVariables.x[4];
acadoWorkspace.Dx0[5] = acadoVariables.x0[5] - acadoVariables.x[5];
for (lRun1 = 0; lRun1 < 320; ++lRun1)
acadoWorkspace.Dy[lRun1] -= acadoVariables.y[lRun1];

acadoWorkspace.DyN[0] -= acadoVariables.yN[0];
acadoWorkspace.DyN[1] -= acadoVariables.yN[1];
acadoWorkspace.DyN[2] -= acadoVariables.yN[2];
acadoWorkspace.DyN[3] -= acadoVariables.yN[3];
acadoWorkspace.DyN[4] -= acadoVariables.yN[4];
acadoWorkspace.DyN[5] -= acadoVariables.yN[5];

acado_multRDy( acadoWorkspace.R2, acadoWorkspace.Dy, acadoWorkspace.g );
acado_multRDy( &(acadoWorkspace.R2[ 16 ]), &(acadoWorkspace.Dy[ 8 ]), &(acadoWorkspace.g[ 2 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 32 ]), &(acadoWorkspace.Dy[ 16 ]), &(acadoWorkspace.g[ 4 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 48 ]), &(acadoWorkspace.Dy[ 24 ]), &(acadoWorkspace.g[ 6 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 64 ]), &(acadoWorkspace.Dy[ 32 ]), &(acadoWorkspace.g[ 8 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 80 ]), &(acadoWorkspace.Dy[ 40 ]), &(acadoWorkspace.g[ 10 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 96 ]), &(acadoWorkspace.Dy[ 48 ]), &(acadoWorkspace.g[ 12 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 112 ]), &(acadoWorkspace.Dy[ 56 ]), &(acadoWorkspace.g[ 14 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 128 ]), &(acadoWorkspace.Dy[ 64 ]), &(acadoWorkspace.g[ 16 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 144 ]), &(acadoWorkspace.Dy[ 72 ]), &(acadoWorkspace.g[ 18 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 160 ]), &(acadoWorkspace.Dy[ 80 ]), &(acadoWorkspace.g[ 20 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 176 ]), &(acadoWorkspace.Dy[ 88 ]), &(acadoWorkspace.g[ 22 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 192 ]), &(acadoWorkspace.Dy[ 96 ]), &(acadoWorkspace.g[ 24 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 208 ]), &(acadoWorkspace.Dy[ 104 ]), &(acadoWorkspace.g[ 26 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 224 ]), &(acadoWorkspace.Dy[ 112 ]), &(acadoWorkspace.g[ 28 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 240 ]), &(acadoWorkspace.Dy[ 120 ]), &(acadoWorkspace.g[ 30 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 256 ]), &(acadoWorkspace.Dy[ 128 ]), &(acadoWorkspace.g[ 32 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 272 ]), &(acadoWorkspace.Dy[ 136 ]), &(acadoWorkspace.g[ 34 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 288 ]), &(acadoWorkspace.Dy[ 144 ]), &(acadoWorkspace.g[ 36 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 304 ]), &(acadoWorkspace.Dy[ 152 ]), &(acadoWorkspace.g[ 38 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 320 ]), &(acadoWorkspace.Dy[ 160 ]), &(acadoWorkspace.g[ 40 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 336 ]), &(acadoWorkspace.Dy[ 168 ]), &(acadoWorkspace.g[ 42 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 352 ]), &(acadoWorkspace.Dy[ 176 ]), &(acadoWorkspace.g[ 44 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 368 ]), &(acadoWorkspace.Dy[ 184 ]), &(acadoWorkspace.g[ 46 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 384 ]), &(acadoWorkspace.Dy[ 192 ]), &(acadoWorkspace.g[ 48 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 400 ]), &(acadoWorkspace.Dy[ 200 ]), &(acadoWorkspace.g[ 50 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 416 ]), &(acadoWorkspace.Dy[ 208 ]), &(acadoWorkspace.g[ 52 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 432 ]), &(acadoWorkspace.Dy[ 216 ]), &(acadoWorkspace.g[ 54 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 448 ]), &(acadoWorkspace.Dy[ 224 ]), &(acadoWorkspace.g[ 56 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 464 ]), &(acadoWorkspace.Dy[ 232 ]), &(acadoWorkspace.g[ 58 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 480 ]), &(acadoWorkspace.Dy[ 240 ]), &(acadoWorkspace.g[ 60 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 496 ]), &(acadoWorkspace.Dy[ 248 ]), &(acadoWorkspace.g[ 62 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 512 ]), &(acadoWorkspace.Dy[ 256 ]), &(acadoWorkspace.g[ 64 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 528 ]), &(acadoWorkspace.Dy[ 264 ]), &(acadoWorkspace.g[ 66 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 544 ]), &(acadoWorkspace.Dy[ 272 ]), &(acadoWorkspace.g[ 68 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 560 ]), &(acadoWorkspace.Dy[ 280 ]), &(acadoWorkspace.g[ 70 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 576 ]), &(acadoWorkspace.Dy[ 288 ]), &(acadoWorkspace.g[ 72 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 592 ]), &(acadoWorkspace.Dy[ 296 ]), &(acadoWorkspace.g[ 74 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 608 ]), &(acadoWorkspace.Dy[ 304 ]), &(acadoWorkspace.g[ 76 ]) );
acado_multRDy( &(acadoWorkspace.R2[ 624 ]), &(acadoWorkspace.Dy[ 312 ]), &(acadoWorkspace.g[ 78 ]) );

acado_multQDy( acadoWorkspace.Q2, acadoWorkspace.Dy, acadoWorkspace.QDy );
acado_multQDy( &(acadoWorkspace.Q2[ 48 ]), &(acadoWorkspace.Dy[ 8 ]), &(acadoWorkspace.QDy[ 6 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 96 ]), &(acadoWorkspace.Dy[ 16 ]), &(acadoWorkspace.QDy[ 12 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 144 ]), &(acadoWorkspace.Dy[ 24 ]), &(acadoWorkspace.QDy[ 18 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 192 ]), &(acadoWorkspace.Dy[ 32 ]), &(acadoWorkspace.QDy[ 24 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 240 ]), &(acadoWorkspace.Dy[ 40 ]), &(acadoWorkspace.QDy[ 30 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 288 ]), &(acadoWorkspace.Dy[ 48 ]), &(acadoWorkspace.QDy[ 36 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 336 ]), &(acadoWorkspace.Dy[ 56 ]), &(acadoWorkspace.QDy[ 42 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 384 ]), &(acadoWorkspace.Dy[ 64 ]), &(acadoWorkspace.QDy[ 48 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 432 ]), &(acadoWorkspace.Dy[ 72 ]), &(acadoWorkspace.QDy[ 54 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 480 ]), &(acadoWorkspace.Dy[ 80 ]), &(acadoWorkspace.QDy[ 60 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 528 ]), &(acadoWorkspace.Dy[ 88 ]), &(acadoWorkspace.QDy[ 66 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 576 ]), &(acadoWorkspace.Dy[ 96 ]), &(acadoWorkspace.QDy[ 72 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 624 ]), &(acadoWorkspace.Dy[ 104 ]), &(acadoWorkspace.QDy[ 78 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 672 ]), &(acadoWorkspace.Dy[ 112 ]), &(acadoWorkspace.QDy[ 84 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 720 ]), &(acadoWorkspace.Dy[ 120 ]), &(acadoWorkspace.QDy[ 90 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 768 ]), &(acadoWorkspace.Dy[ 128 ]), &(acadoWorkspace.QDy[ 96 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 816 ]), &(acadoWorkspace.Dy[ 136 ]), &(acadoWorkspace.QDy[ 102 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 864 ]), &(acadoWorkspace.Dy[ 144 ]), &(acadoWorkspace.QDy[ 108 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 912 ]), &(acadoWorkspace.Dy[ 152 ]), &(acadoWorkspace.QDy[ 114 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 960 ]), &(acadoWorkspace.Dy[ 160 ]), &(acadoWorkspace.QDy[ 120 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1008 ]), &(acadoWorkspace.Dy[ 168 ]), &(acadoWorkspace.QDy[ 126 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1056 ]), &(acadoWorkspace.Dy[ 176 ]), &(acadoWorkspace.QDy[ 132 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1104 ]), &(acadoWorkspace.Dy[ 184 ]), &(acadoWorkspace.QDy[ 138 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1152 ]), &(acadoWorkspace.Dy[ 192 ]), &(acadoWorkspace.QDy[ 144 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1200 ]), &(acadoWorkspace.Dy[ 200 ]), &(acadoWorkspace.QDy[ 150 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1248 ]), &(acadoWorkspace.Dy[ 208 ]), &(acadoWorkspace.QDy[ 156 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1296 ]), &(acadoWorkspace.Dy[ 216 ]), &(acadoWorkspace.QDy[ 162 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1344 ]), &(acadoWorkspace.Dy[ 224 ]), &(acadoWorkspace.QDy[ 168 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1392 ]), &(acadoWorkspace.Dy[ 232 ]), &(acadoWorkspace.QDy[ 174 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1440 ]), &(acadoWorkspace.Dy[ 240 ]), &(acadoWorkspace.QDy[ 180 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1488 ]), &(acadoWorkspace.Dy[ 248 ]), &(acadoWorkspace.QDy[ 186 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1536 ]), &(acadoWorkspace.Dy[ 256 ]), &(acadoWorkspace.QDy[ 192 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1584 ]), &(acadoWorkspace.Dy[ 264 ]), &(acadoWorkspace.QDy[ 198 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1632 ]), &(acadoWorkspace.Dy[ 272 ]), &(acadoWorkspace.QDy[ 204 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1680 ]), &(acadoWorkspace.Dy[ 280 ]), &(acadoWorkspace.QDy[ 210 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1728 ]), &(acadoWorkspace.Dy[ 288 ]), &(acadoWorkspace.QDy[ 216 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1776 ]), &(acadoWorkspace.Dy[ 296 ]), &(acadoWorkspace.QDy[ 222 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1824 ]), &(acadoWorkspace.Dy[ 304 ]), &(acadoWorkspace.QDy[ 228 ]) );
acado_multQDy( &(acadoWorkspace.Q2[ 1872 ]), &(acadoWorkspace.Dy[ 312 ]), &(acadoWorkspace.QDy[ 234 ]) );

acadoWorkspace.QDy[240] = + acadoWorkspace.QN2[0]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[1]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[2]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[3]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[4]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[5]*acadoWorkspace.DyN[5];
acadoWorkspace.QDy[241] = + acadoWorkspace.QN2[6]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[7]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[8]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[9]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[10]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[11]*acadoWorkspace.DyN[5];
acadoWorkspace.QDy[242] = + acadoWorkspace.QN2[12]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[13]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[14]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[15]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[16]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[17]*acadoWorkspace.DyN[5];
acadoWorkspace.QDy[243] = + acadoWorkspace.QN2[18]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[19]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[20]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[21]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[22]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[23]*acadoWorkspace.DyN[5];
acadoWorkspace.QDy[244] = + acadoWorkspace.QN2[24]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[25]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[26]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[27]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[28]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[29]*acadoWorkspace.DyN[5];
acadoWorkspace.QDy[245] = + acadoWorkspace.QN2[30]*acadoWorkspace.DyN[0] + acadoWorkspace.QN2[31]*acadoWorkspace.DyN[1] + acadoWorkspace.QN2[32]*acadoWorkspace.DyN[2] + acadoWorkspace.QN2[33]*acadoWorkspace.DyN[3] + acadoWorkspace.QN2[34]*acadoWorkspace.DyN[4] + acadoWorkspace.QN2[35]*acadoWorkspace.DyN[5];

acadoWorkspace.sbar[0] = acadoWorkspace.Dx0[0];
acadoWorkspace.sbar[1] = acadoWorkspace.Dx0[1];
acadoWorkspace.sbar[2] = acadoWorkspace.Dx0[2];
acadoWorkspace.sbar[3] = acadoWorkspace.Dx0[3];
acadoWorkspace.sbar[4] = acadoWorkspace.Dx0[4];
acadoWorkspace.sbar[5] = acadoWorkspace.Dx0[5];
acado_macASbar( acadoWorkspace.evGx, acadoWorkspace.sbar, &(acadoWorkspace.sbar[ 6 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 36 ]), &(acadoWorkspace.sbar[ 6 ]), &(acadoWorkspace.sbar[ 12 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 72 ]), &(acadoWorkspace.sbar[ 12 ]), &(acadoWorkspace.sbar[ 18 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 108 ]), &(acadoWorkspace.sbar[ 18 ]), &(acadoWorkspace.sbar[ 24 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 144 ]), &(acadoWorkspace.sbar[ 24 ]), &(acadoWorkspace.sbar[ 30 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 180 ]), &(acadoWorkspace.sbar[ 30 ]), &(acadoWorkspace.sbar[ 36 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 216 ]), &(acadoWorkspace.sbar[ 36 ]), &(acadoWorkspace.sbar[ 42 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 252 ]), &(acadoWorkspace.sbar[ 42 ]), &(acadoWorkspace.sbar[ 48 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 288 ]), &(acadoWorkspace.sbar[ 48 ]), &(acadoWorkspace.sbar[ 54 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 324 ]), &(acadoWorkspace.sbar[ 54 ]), &(acadoWorkspace.sbar[ 60 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 360 ]), &(acadoWorkspace.sbar[ 60 ]), &(acadoWorkspace.sbar[ 66 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 396 ]), &(acadoWorkspace.sbar[ 66 ]), &(acadoWorkspace.sbar[ 72 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 432 ]), &(acadoWorkspace.sbar[ 72 ]), &(acadoWorkspace.sbar[ 78 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 468 ]), &(acadoWorkspace.sbar[ 78 ]), &(acadoWorkspace.sbar[ 84 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 504 ]), &(acadoWorkspace.sbar[ 84 ]), &(acadoWorkspace.sbar[ 90 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 540 ]), &(acadoWorkspace.sbar[ 90 ]), &(acadoWorkspace.sbar[ 96 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 576 ]), &(acadoWorkspace.sbar[ 96 ]), &(acadoWorkspace.sbar[ 102 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 612 ]), &(acadoWorkspace.sbar[ 102 ]), &(acadoWorkspace.sbar[ 108 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 648 ]), &(acadoWorkspace.sbar[ 108 ]), &(acadoWorkspace.sbar[ 114 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 684 ]), &(acadoWorkspace.sbar[ 114 ]), &(acadoWorkspace.sbar[ 120 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 720 ]), &(acadoWorkspace.sbar[ 120 ]), &(acadoWorkspace.sbar[ 126 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 756 ]), &(acadoWorkspace.sbar[ 126 ]), &(acadoWorkspace.sbar[ 132 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 792 ]), &(acadoWorkspace.sbar[ 132 ]), &(acadoWorkspace.sbar[ 138 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 828 ]), &(acadoWorkspace.sbar[ 138 ]), &(acadoWorkspace.sbar[ 144 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 864 ]), &(acadoWorkspace.sbar[ 144 ]), &(acadoWorkspace.sbar[ 150 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 900 ]), &(acadoWorkspace.sbar[ 150 ]), &(acadoWorkspace.sbar[ 156 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 936 ]), &(acadoWorkspace.sbar[ 156 ]), &(acadoWorkspace.sbar[ 162 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 972 ]), &(acadoWorkspace.sbar[ 162 ]), &(acadoWorkspace.sbar[ 168 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1008 ]), &(acadoWorkspace.sbar[ 168 ]), &(acadoWorkspace.sbar[ 174 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1044 ]), &(acadoWorkspace.sbar[ 174 ]), &(acadoWorkspace.sbar[ 180 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1080 ]), &(acadoWorkspace.sbar[ 180 ]), &(acadoWorkspace.sbar[ 186 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1116 ]), &(acadoWorkspace.sbar[ 186 ]), &(acadoWorkspace.sbar[ 192 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1152 ]), &(acadoWorkspace.sbar[ 192 ]), &(acadoWorkspace.sbar[ 198 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1188 ]), &(acadoWorkspace.sbar[ 198 ]), &(acadoWorkspace.sbar[ 204 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1224 ]), &(acadoWorkspace.sbar[ 204 ]), &(acadoWorkspace.sbar[ 210 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1260 ]), &(acadoWorkspace.sbar[ 210 ]), &(acadoWorkspace.sbar[ 216 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1296 ]), &(acadoWorkspace.sbar[ 216 ]), &(acadoWorkspace.sbar[ 222 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1332 ]), &(acadoWorkspace.sbar[ 222 ]), &(acadoWorkspace.sbar[ 228 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1368 ]), &(acadoWorkspace.sbar[ 228 ]), &(acadoWorkspace.sbar[ 234 ]) );
acado_macASbar( &(acadoWorkspace.evGx[ 1404 ]), &(acadoWorkspace.sbar[ 234 ]), &(acadoWorkspace.sbar[ 240 ]) );

acadoWorkspace.w1[0] = + acadoWorkspace.QN1[0]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[1]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[2]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[3]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[4]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[5]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[240];
acadoWorkspace.w1[1] = + acadoWorkspace.QN1[6]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[7]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[8]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[9]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[10]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[11]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[241];
acadoWorkspace.w1[2] = + acadoWorkspace.QN1[12]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[13]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[14]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[15]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[16]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[17]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[242];
acadoWorkspace.w1[3] = + acadoWorkspace.QN1[18]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[19]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[20]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[21]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[22]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[23]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[243];
acadoWorkspace.w1[4] = + acadoWorkspace.QN1[24]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[25]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[26]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[27]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[28]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[29]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[244];
acadoWorkspace.w1[5] = + acadoWorkspace.QN1[30]*acadoWorkspace.sbar[240] + acadoWorkspace.QN1[31]*acadoWorkspace.sbar[241] + acadoWorkspace.QN1[32]*acadoWorkspace.sbar[242] + acadoWorkspace.QN1[33]*acadoWorkspace.sbar[243] + acadoWorkspace.QN1[34]*acadoWorkspace.sbar[244] + acadoWorkspace.QN1[35]*acadoWorkspace.sbar[245] + acadoWorkspace.QDy[245];
acado_macBTw1( &(acadoWorkspace.evGu[ 468 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 78 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1404 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 234 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1404 ]), &(acadoWorkspace.sbar[ 234 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 456 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 76 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1368 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 228 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1368 ]), &(acadoWorkspace.sbar[ 228 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 444 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 74 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1332 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 222 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1332 ]), &(acadoWorkspace.sbar[ 222 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 432 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 72 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1296 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 216 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1296 ]), &(acadoWorkspace.sbar[ 216 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 420 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 70 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1260 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 210 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1260 ]), &(acadoWorkspace.sbar[ 210 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 408 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 68 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1224 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 204 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1224 ]), &(acadoWorkspace.sbar[ 204 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 396 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 66 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1188 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 198 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1188 ]), &(acadoWorkspace.sbar[ 198 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 384 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 64 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1152 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 192 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1152 ]), &(acadoWorkspace.sbar[ 192 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 372 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 62 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1116 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 186 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1116 ]), &(acadoWorkspace.sbar[ 186 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 360 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 60 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1080 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 180 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1080 ]), &(acadoWorkspace.sbar[ 180 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 348 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 58 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1044 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 174 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1044 ]), &(acadoWorkspace.sbar[ 174 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 336 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 56 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 1008 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 168 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 1008 ]), &(acadoWorkspace.sbar[ 168 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 324 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 54 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 972 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 162 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 972 ]), &(acadoWorkspace.sbar[ 162 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 312 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 52 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 936 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 156 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 936 ]), &(acadoWorkspace.sbar[ 156 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 300 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 50 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 900 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 150 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 900 ]), &(acadoWorkspace.sbar[ 150 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 288 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 48 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 864 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 144 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 864 ]), &(acadoWorkspace.sbar[ 144 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 276 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 46 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 828 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 138 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 828 ]), &(acadoWorkspace.sbar[ 138 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 264 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 44 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 792 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 132 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 792 ]), &(acadoWorkspace.sbar[ 132 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 252 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 42 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 756 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 126 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 756 ]), &(acadoWorkspace.sbar[ 126 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 240 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 40 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 720 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 120 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 720 ]), &(acadoWorkspace.sbar[ 120 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 228 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 38 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 684 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 114 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 684 ]), &(acadoWorkspace.sbar[ 114 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 216 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 36 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 648 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 108 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 648 ]), &(acadoWorkspace.sbar[ 108 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 204 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 34 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 612 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 102 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 612 ]), &(acadoWorkspace.sbar[ 102 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 192 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 32 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 576 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 96 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 576 ]), &(acadoWorkspace.sbar[ 96 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 180 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 30 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 540 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 90 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 540 ]), &(acadoWorkspace.sbar[ 90 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 168 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 28 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 504 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 84 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 504 ]), &(acadoWorkspace.sbar[ 84 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 156 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 26 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 468 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 78 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 468 ]), &(acadoWorkspace.sbar[ 78 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 144 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 24 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 432 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 72 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 432 ]), &(acadoWorkspace.sbar[ 72 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 132 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 22 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 396 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 66 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 396 ]), &(acadoWorkspace.sbar[ 66 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 120 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 20 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 360 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 60 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 360 ]), &(acadoWorkspace.sbar[ 60 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 108 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 18 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 324 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 54 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 324 ]), &(acadoWorkspace.sbar[ 54 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 96 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 16 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 288 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 48 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 288 ]), &(acadoWorkspace.sbar[ 48 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 84 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 14 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 252 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 42 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 252 ]), &(acadoWorkspace.sbar[ 42 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 72 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 12 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 216 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 36 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 216 ]), &(acadoWorkspace.sbar[ 36 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 60 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 10 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 180 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 30 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 180 ]), &(acadoWorkspace.sbar[ 30 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 48 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 8 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 144 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 24 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 144 ]), &(acadoWorkspace.sbar[ 24 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 36 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 6 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 108 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 18 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 108 ]), &(acadoWorkspace.sbar[ 18 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 24 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 4 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 72 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 12 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 72 ]), &(acadoWorkspace.sbar[ 12 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( &(acadoWorkspace.evGu[ 12 ]), acadoWorkspace.w1, &(acadoWorkspace.g[ 2 ]) );
acado_macATw1QDy( &(acadoWorkspace.evGx[ 36 ]), acadoWorkspace.w1, &(acadoWorkspace.QDy[ 6 ]), acadoWorkspace.w2 );
acado_macQSbarW2( &(acadoWorkspace.Q1[ 36 ]), &(acadoWorkspace.sbar[ 6 ]), acadoWorkspace.w2, acadoWorkspace.w1 );
acado_macBTw1( acadoWorkspace.evGu, acadoWorkspace.w1, acadoWorkspace.g );


tmp = acadoWorkspace.sbar[6] + acadoVariables.x[6];
acadoWorkspace.lbA[0] = - tmp;
acadoWorkspace.ubA[0] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[12] + acadoVariables.x[12];
acadoWorkspace.lbA[1] = - tmp;
acadoWorkspace.ubA[1] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[18] + acadoVariables.x[18];
acadoWorkspace.lbA[2] = - tmp;
acadoWorkspace.ubA[2] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[24] + acadoVariables.x[24];
acadoWorkspace.lbA[3] = - tmp;
acadoWorkspace.ubA[3] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[30] + acadoVariables.x[30];
acadoWorkspace.lbA[4] = - tmp;
acadoWorkspace.ubA[4] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[36] + acadoVariables.x[36];
acadoWorkspace.lbA[5] = - tmp;
acadoWorkspace.ubA[5] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[42] + acadoVariables.x[42];
acadoWorkspace.lbA[6] = - tmp;
acadoWorkspace.ubA[6] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[48] + acadoVariables.x[48];
acadoWorkspace.lbA[7] = - tmp;
acadoWorkspace.ubA[7] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[54] + acadoVariables.x[54];
acadoWorkspace.lbA[8] = - tmp;
acadoWorkspace.ubA[8] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[60] + acadoVariables.x[60];
acadoWorkspace.lbA[9] = - tmp;
acadoWorkspace.ubA[9] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[66] + acadoVariables.x[66];
acadoWorkspace.lbA[10] = - tmp;
acadoWorkspace.ubA[10] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[72] + acadoVariables.x[72];
acadoWorkspace.lbA[11] = - tmp;
acadoWorkspace.ubA[11] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[78] + acadoVariables.x[78];
acadoWorkspace.lbA[12] = - tmp;
acadoWorkspace.ubA[12] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[84] + acadoVariables.x[84];
acadoWorkspace.lbA[13] = - tmp;
acadoWorkspace.ubA[13] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[90] + acadoVariables.x[90];
acadoWorkspace.lbA[14] = - tmp;
acadoWorkspace.ubA[14] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[96] + acadoVariables.x[96];
acadoWorkspace.lbA[15] = - tmp;
acadoWorkspace.ubA[15] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[102] + acadoVariables.x[102];
acadoWorkspace.lbA[16] = - tmp;
acadoWorkspace.ubA[16] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[108] + acadoVariables.x[108];
acadoWorkspace.lbA[17] = - tmp;
acadoWorkspace.ubA[17] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[114] + acadoVariables.x[114];
acadoWorkspace.lbA[18] = - tmp;
acadoWorkspace.ubA[18] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[120] + acadoVariables.x[120];
acadoWorkspace.lbA[19] = - tmp;
acadoWorkspace.ubA[19] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[126] + acadoVariables.x[126];
acadoWorkspace.lbA[20] = - tmp;
acadoWorkspace.ubA[20] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[132] + acadoVariables.x[132];
acadoWorkspace.lbA[21] = - tmp;
acadoWorkspace.ubA[21] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[138] + acadoVariables.x[138];
acadoWorkspace.lbA[22] = - tmp;
acadoWorkspace.ubA[22] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[144] + acadoVariables.x[144];
acadoWorkspace.lbA[23] = - tmp;
acadoWorkspace.ubA[23] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[150] + acadoVariables.x[150];
acadoWorkspace.lbA[24] = - tmp;
acadoWorkspace.ubA[24] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[156] + acadoVariables.x[156];
acadoWorkspace.lbA[25] = - tmp;
acadoWorkspace.ubA[25] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[162] + acadoVariables.x[162];
acadoWorkspace.lbA[26] = - tmp;
acadoWorkspace.ubA[26] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[168] + acadoVariables.x[168];
acadoWorkspace.lbA[27] = - tmp;
acadoWorkspace.ubA[27] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[174] + acadoVariables.x[174];
acadoWorkspace.lbA[28] = - tmp;
acadoWorkspace.ubA[28] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[180] + acadoVariables.x[180];
acadoWorkspace.lbA[29] = - tmp;
acadoWorkspace.ubA[29] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[186] + acadoVariables.x[186];
acadoWorkspace.lbA[30] = - tmp;
acadoWorkspace.ubA[30] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[192] + acadoVariables.x[192];
acadoWorkspace.lbA[31] = - tmp;
acadoWorkspace.ubA[31] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[198] + acadoVariables.x[198];
acadoWorkspace.lbA[32] = - tmp;
acadoWorkspace.ubA[32] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[204] + acadoVariables.x[204];
acadoWorkspace.lbA[33] = - tmp;
acadoWorkspace.ubA[33] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[210] + acadoVariables.x[210];
acadoWorkspace.lbA[34] = - tmp;
acadoWorkspace.ubA[34] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[216] + acadoVariables.x[216];
acadoWorkspace.lbA[35] = - tmp;
acadoWorkspace.ubA[35] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[222] + acadoVariables.x[222];
acadoWorkspace.lbA[36] = - tmp;
acadoWorkspace.ubA[36] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[228] + acadoVariables.x[228];
acadoWorkspace.lbA[37] = - tmp;
acadoWorkspace.ubA[37] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[234] + acadoVariables.x[234];
acadoWorkspace.lbA[38] = - tmp;
acadoWorkspace.ubA[38] = (real_t)4.7222222222222221e+01 - tmp;
tmp = acadoWorkspace.sbar[240] + acadoVariables.x[240];
acadoWorkspace.lbA[39] = - tmp;
acadoWorkspace.ubA[39] = (real_t)4.7222222222222221e+01 - tmp;

acado_macHxd( acadoWorkspace.evHx, acadoWorkspace.sbar, &(acadoWorkspace.lbA[ 40 ]), &(acadoWorkspace.ubA[ 40 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 24 ]), &(acadoWorkspace.sbar[ 6 ]), &(acadoWorkspace.lbA[ 44 ]), &(acadoWorkspace.ubA[ 44 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 48 ]), &(acadoWorkspace.sbar[ 12 ]), &(acadoWorkspace.lbA[ 48 ]), &(acadoWorkspace.ubA[ 48 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 72 ]), &(acadoWorkspace.sbar[ 18 ]), &(acadoWorkspace.lbA[ 52 ]), &(acadoWorkspace.ubA[ 52 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 96 ]), &(acadoWorkspace.sbar[ 24 ]), &(acadoWorkspace.lbA[ 56 ]), &(acadoWorkspace.ubA[ 56 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 120 ]), &(acadoWorkspace.sbar[ 30 ]), &(acadoWorkspace.lbA[ 60 ]), &(acadoWorkspace.ubA[ 60 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 144 ]), &(acadoWorkspace.sbar[ 36 ]), &(acadoWorkspace.lbA[ 64 ]), &(acadoWorkspace.ubA[ 64 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 168 ]), &(acadoWorkspace.sbar[ 42 ]), &(acadoWorkspace.lbA[ 68 ]), &(acadoWorkspace.ubA[ 68 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 192 ]), &(acadoWorkspace.sbar[ 48 ]), &(acadoWorkspace.lbA[ 72 ]), &(acadoWorkspace.ubA[ 72 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 216 ]), &(acadoWorkspace.sbar[ 54 ]), &(acadoWorkspace.lbA[ 76 ]), &(acadoWorkspace.ubA[ 76 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 240 ]), &(acadoWorkspace.sbar[ 60 ]), &(acadoWorkspace.lbA[ 80 ]), &(acadoWorkspace.ubA[ 80 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 264 ]), &(acadoWorkspace.sbar[ 66 ]), &(acadoWorkspace.lbA[ 84 ]), &(acadoWorkspace.ubA[ 84 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 288 ]), &(acadoWorkspace.sbar[ 72 ]), &(acadoWorkspace.lbA[ 88 ]), &(acadoWorkspace.ubA[ 88 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 312 ]), &(acadoWorkspace.sbar[ 78 ]), &(acadoWorkspace.lbA[ 92 ]), &(acadoWorkspace.ubA[ 92 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 336 ]), &(acadoWorkspace.sbar[ 84 ]), &(acadoWorkspace.lbA[ 96 ]), &(acadoWorkspace.ubA[ 96 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 360 ]), &(acadoWorkspace.sbar[ 90 ]), &(acadoWorkspace.lbA[ 100 ]), &(acadoWorkspace.ubA[ 100 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 384 ]), &(acadoWorkspace.sbar[ 96 ]), &(acadoWorkspace.lbA[ 104 ]), &(acadoWorkspace.ubA[ 104 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 408 ]), &(acadoWorkspace.sbar[ 102 ]), &(acadoWorkspace.lbA[ 108 ]), &(acadoWorkspace.ubA[ 108 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 432 ]), &(acadoWorkspace.sbar[ 108 ]), &(acadoWorkspace.lbA[ 112 ]), &(acadoWorkspace.ubA[ 112 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 456 ]), &(acadoWorkspace.sbar[ 114 ]), &(acadoWorkspace.lbA[ 116 ]), &(acadoWorkspace.ubA[ 116 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 480 ]), &(acadoWorkspace.sbar[ 120 ]), &(acadoWorkspace.lbA[ 120 ]), &(acadoWorkspace.ubA[ 120 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 504 ]), &(acadoWorkspace.sbar[ 126 ]), &(acadoWorkspace.lbA[ 124 ]), &(acadoWorkspace.ubA[ 124 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 528 ]), &(acadoWorkspace.sbar[ 132 ]), &(acadoWorkspace.lbA[ 128 ]), &(acadoWorkspace.ubA[ 128 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 552 ]), &(acadoWorkspace.sbar[ 138 ]), &(acadoWorkspace.lbA[ 132 ]), &(acadoWorkspace.ubA[ 132 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 576 ]), &(acadoWorkspace.sbar[ 144 ]), &(acadoWorkspace.lbA[ 136 ]), &(acadoWorkspace.ubA[ 136 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 600 ]), &(acadoWorkspace.sbar[ 150 ]), &(acadoWorkspace.lbA[ 140 ]), &(acadoWorkspace.ubA[ 140 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 624 ]), &(acadoWorkspace.sbar[ 156 ]), &(acadoWorkspace.lbA[ 144 ]), &(acadoWorkspace.ubA[ 144 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 648 ]), &(acadoWorkspace.sbar[ 162 ]), &(acadoWorkspace.lbA[ 148 ]), &(acadoWorkspace.ubA[ 148 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 672 ]), &(acadoWorkspace.sbar[ 168 ]), &(acadoWorkspace.lbA[ 152 ]), &(acadoWorkspace.ubA[ 152 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 696 ]), &(acadoWorkspace.sbar[ 174 ]), &(acadoWorkspace.lbA[ 156 ]), &(acadoWorkspace.ubA[ 156 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 720 ]), &(acadoWorkspace.sbar[ 180 ]), &(acadoWorkspace.lbA[ 160 ]), &(acadoWorkspace.ubA[ 160 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 744 ]), &(acadoWorkspace.sbar[ 186 ]), &(acadoWorkspace.lbA[ 164 ]), &(acadoWorkspace.ubA[ 164 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 768 ]), &(acadoWorkspace.sbar[ 192 ]), &(acadoWorkspace.lbA[ 168 ]), &(acadoWorkspace.ubA[ 168 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 792 ]), &(acadoWorkspace.sbar[ 198 ]), &(acadoWorkspace.lbA[ 172 ]), &(acadoWorkspace.ubA[ 172 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 816 ]), &(acadoWorkspace.sbar[ 204 ]), &(acadoWorkspace.lbA[ 176 ]), &(acadoWorkspace.ubA[ 176 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 840 ]), &(acadoWorkspace.sbar[ 210 ]), &(acadoWorkspace.lbA[ 180 ]), &(acadoWorkspace.ubA[ 180 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 864 ]), &(acadoWorkspace.sbar[ 216 ]), &(acadoWorkspace.lbA[ 184 ]), &(acadoWorkspace.ubA[ 184 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 888 ]), &(acadoWorkspace.sbar[ 222 ]), &(acadoWorkspace.lbA[ 188 ]), &(acadoWorkspace.ubA[ 188 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 912 ]), &(acadoWorkspace.sbar[ 228 ]), &(acadoWorkspace.lbA[ 192 ]), &(acadoWorkspace.ubA[ 192 ]) );
acado_macHxd( &(acadoWorkspace.evHx[ 936 ]), &(acadoWorkspace.sbar[ 234 ]), &(acadoWorkspace.lbA[ 196 ]), &(acadoWorkspace.ubA[ 196 ]) );

}

void acado_expand(  )
{
int lRun1;
acadoVariables.u[0] += acadoWorkspace.x[0];
acadoVariables.u[1] += acadoWorkspace.x[1];
acadoVariables.u[2] += acadoWorkspace.x[2];
acadoVariables.u[3] += acadoWorkspace.x[3];
acadoVariables.u[4] += acadoWorkspace.x[4];
acadoVariables.u[5] += acadoWorkspace.x[5];
acadoVariables.u[6] += acadoWorkspace.x[6];
acadoVariables.u[7] += acadoWorkspace.x[7];
acadoVariables.u[8] += acadoWorkspace.x[8];
acadoVariables.u[9] += acadoWorkspace.x[9];
acadoVariables.u[10] += acadoWorkspace.x[10];
acadoVariables.u[11] += acadoWorkspace.x[11];
acadoVariables.u[12] += acadoWorkspace.x[12];
acadoVariables.u[13] += acadoWorkspace.x[13];
acadoVariables.u[14] += acadoWorkspace.x[14];
acadoVariables.u[15] += acadoWorkspace.x[15];
acadoVariables.u[16] += acadoWorkspace.x[16];
acadoVariables.u[17] += acadoWorkspace.x[17];
acadoVariables.u[18] += acadoWorkspace.x[18];
acadoVariables.u[19] += acadoWorkspace.x[19];
acadoVariables.u[20] += acadoWorkspace.x[20];
acadoVariables.u[21] += acadoWorkspace.x[21];
acadoVariables.u[22] += acadoWorkspace.x[22];
acadoVariables.u[23] += acadoWorkspace.x[23];
acadoVariables.u[24] += acadoWorkspace.x[24];
acadoVariables.u[25] += acadoWorkspace.x[25];
acadoVariables.u[26] += acadoWorkspace.x[26];
acadoVariables.u[27] += acadoWorkspace.x[27];
acadoVariables.u[28] += acadoWorkspace.x[28];
acadoVariables.u[29] += acadoWorkspace.x[29];
acadoVariables.u[30] += acadoWorkspace.x[30];
acadoVariables.u[31] += acadoWorkspace.x[31];
acadoVariables.u[32] += acadoWorkspace.x[32];
acadoVariables.u[33] += acadoWorkspace.x[33];
acadoVariables.u[34] += acadoWorkspace.x[34];
acadoVariables.u[35] += acadoWorkspace.x[35];
acadoVariables.u[36] += acadoWorkspace.x[36];
acadoVariables.u[37] += acadoWorkspace.x[37];
acadoVariables.u[38] += acadoWorkspace.x[38];
acadoVariables.u[39] += acadoWorkspace.x[39];
acadoVariables.u[40] += acadoWorkspace.x[40];
acadoVariables.u[41] += acadoWorkspace.x[41];
acadoVariables.u[42] += acadoWorkspace.x[42];
acadoVariables.u[43] += acadoWorkspace.x[43];
acadoVariables.u[44] += acadoWorkspace.x[44];
acadoVariables.u[45] += acadoWorkspace.x[45];
acadoVariables.u[46] += acadoWorkspace.x[46];
acadoVariables.u[47] += acadoWorkspace.x[47];
acadoVariables.u[48] += acadoWorkspace.x[48];
acadoVariables.u[49] += acadoWorkspace.x[49];
acadoVariables.u[50] += acadoWorkspace.x[50];
acadoVariables.u[51] += acadoWorkspace.x[51];
acadoVariables.u[52] += acadoWorkspace.x[52];
acadoVariables.u[53] += acadoWorkspace.x[53];
acadoVariables.u[54] += acadoWorkspace.x[54];
acadoVariables.u[55] += acadoWorkspace.x[55];
acadoVariables.u[56] += acadoWorkspace.x[56];
acadoVariables.u[57] += acadoWorkspace.x[57];
acadoVariables.u[58] += acadoWorkspace.x[58];
acadoVariables.u[59] += acadoWorkspace.x[59];
acadoVariables.u[60] += acadoWorkspace.x[60];
acadoVariables.u[61] += acadoWorkspace.x[61];
acadoVariables.u[62] += acadoWorkspace.x[62];
acadoVariables.u[63] += acadoWorkspace.x[63];
acadoVariables.u[64] += acadoWorkspace.x[64];
acadoVariables.u[65] += acadoWorkspace.x[65];
acadoVariables.u[66] += acadoWorkspace.x[66];
acadoVariables.u[67] += acadoWorkspace.x[67];
acadoVariables.u[68] += acadoWorkspace.x[68];
acadoVariables.u[69] += acadoWorkspace.x[69];
acadoVariables.u[70] += acadoWorkspace.x[70];
acadoVariables.u[71] += acadoWorkspace.x[71];
acadoVariables.u[72] += acadoWorkspace.x[72];
acadoVariables.u[73] += acadoWorkspace.x[73];
acadoVariables.u[74] += acadoWorkspace.x[74];
acadoVariables.u[75] += acadoWorkspace.x[75];
acadoVariables.u[76] += acadoWorkspace.x[76];
acadoVariables.u[77] += acadoWorkspace.x[77];
acadoVariables.u[78] += acadoWorkspace.x[78];
acadoVariables.u[79] += acadoWorkspace.x[79];
acadoWorkspace.sbar[0] = acadoWorkspace.Dx0[0];
acadoWorkspace.sbar[1] = acadoWorkspace.Dx0[1];
acadoWorkspace.sbar[2] = acadoWorkspace.Dx0[2];
acadoWorkspace.sbar[3] = acadoWorkspace.Dx0[3];
acadoWorkspace.sbar[4] = acadoWorkspace.Dx0[4];
acadoWorkspace.sbar[5] = acadoWorkspace.Dx0[5];
for (lRun1 = 0; lRun1 < 240; ++lRun1)
acadoWorkspace.sbar[lRun1 + 6] = acadoWorkspace.d[lRun1];

acado_expansionStep( acadoWorkspace.evGx, acadoWorkspace.evGu, acadoWorkspace.x, acadoWorkspace.sbar, &(acadoWorkspace.sbar[ 6 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 36 ]), &(acadoWorkspace.evGu[ 12 ]), &(acadoWorkspace.x[ 2 ]), &(acadoWorkspace.sbar[ 6 ]), &(acadoWorkspace.sbar[ 12 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 72 ]), &(acadoWorkspace.evGu[ 24 ]), &(acadoWorkspace.x[ 4 ]), &(acadoWorkspace.sbar[ 12 ]), &(acadoWorkspace.sbar[ 18 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 108 ]), &(acadoWorkspace.evGu[ 36 ]), &(acadoWorkspace.x[ 6 ]), &(acadoWorkspace.sbar[ 18 ]), &(acadoWorkspace.sbar[ 24 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 144 ]), &(acadoWorkspace.evGu[ 48 ]), &(acadoWorkspace.x[ 8 ]), &(acadoWorkspace.sbar[ 24 ]), &(acadoWorkspace.sbar[ 30 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 180 ]), &(acadoWorkspace.evGu[ 60 ]), &(acadoWorkspace.x[ 10 ]), &(acadoWorkspace.sbar[ 30 ]), &(acadoWorkspace.sbar[ 36 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 216 ]), &(acadoWorkspace.evGu[ 72 ]), &(acadoWorkspace.x[ 12 ]), &(acadoWorkspace.sbar[ 36 ]), &(acadoWorkspace.sbar[ 42 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 252 ]), &(acadoWorkspace.evGu[ 84 ]), &(acadoWorkspace.x[ 14 ]), &(acadoWorkspace.sbar[ 42 ]), &(acadoWorkspace.sbar[ 48 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 288 ]), &(acadoWorkspace.evGu[ 96 ]), &(acadoWorkspace.x[ 16 ]), &(acadoWorkspace.sbar[ 48 ]), &(acadoWorkspace.sbar[ 54 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 324 ]), &(acadoWorkspace.evGu[ 108 ]), &(acadoWorkspace.x[ 18 ]), &(acadoWorkspace.sbar[ 54 ]), &(acadoWorkspace.sbar[ 60 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 360 ]), &(acadoWorkspace.evGu[ 120 ]), &(acadoWorkspace.x[ 20 ]), &(acadoWorkspace.sbar[ 60 ]), &(acadoWorkspace.sbar[ 66 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 396 ]), &(acadoWorkspace.evGu[ 132 ]), &(acadoWorkspace.x[ 22 ]), &(acadoWorkspace.sbar[ 66 ]), &(acadoWorkspace.sbar[ 72 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 432 ]), &(acadoWorkspace.evGu[ 144 ]), &(acadoWorkspace.x[ 24 ]), &(acadoWorkspace.sbar[ 72 ]), &(acadoWorkspace.sbar[ 78 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 468 ]), &(acadoWorkspace.evGu[ 156 ]), &(acadoWorkspace.x[ 26 ]), &(acadoWorkspace.sbar[ 78 ]), &(acadoWorkspace.sbar[ 84 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 504 ]), &(acadoWorkspace.evGu[ 168 ]), &(acadoWorkspace.x[ 28 ]), &(acadoWorkspace.sbar[ 84 ]), &(acadoWorkspace.sbar[ 90 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 540 ]), &(acadoWorkspace.evGu[ 180 ]), &(acadoWorkspace.x[ 30 ]), &(acadoWorkspace.sbar[ 90 ]), &(acadoWorkspace.sbar[ 96 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 576 ]), &(acadoWorkspace.evGu[ 192 ]), &(acadoWorkspace.x[ 32 ]), &(acadoWorkspace.sbar[ 96 ]), &(acadoWorkspace.sbar[ 102 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 612 ]), &(acadoWorkspace.evGu[ 204 ]), &(acadoWorkspace.x[ 34 ]), &(acadoWorkspace.sbar[ 102 ]), &(acadoWorkspace.sbar[ 108 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 648 ]), &(acadoWorkspace.evGu[ 216 ]), &(acadoWorkspace.x[ 36 ]), &(acadoWorkspace.sbar[ 108 ]), &(acadoWorkspace.sbar[ 114 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 684 ]), &(acadoWorkspace.evGu[ 228 ]), &(acadoWorkspace.x[ 38 ]), &(acadoWorkspace.sbar[ 114 ]), &(acadoWorkspace.sbar[ 120 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 720 ]), &(acadoWorkspace.evGu[ 240 ]), &(acadoWorkspace.x[ 40 ]), &(acadoWorkspace.sbar[ 120 ]), &(acadoWorkspace.sbar[ 126 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 756 ]), &(acadoWorkspace.evGu[ 252 ]), &(acadoWorkspace.x[ 42 ]), &(acadoWorkspace.sbar[ 126 ]), &(acadoWorkspace.sbar[ 132 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 792 ]), &(acadoWorkspace.evGu[ 264 ]), &(acadoWorkspace.x[ 44 ]), &(acadoWorkspace.sbar[ 132 ]), &(acadoWorkspace.sbar[ 138 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 828 ]), &(acadoWorkspace.evGu[ 276 ]), &(acadoWorkspace.x[ 46 ]), &(acadoWorkspace.sbar[ 138 ]), &(acadoWorkspace.sbar[ 144 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 864 ]), &(acadoWorkspace.evGu[ 288 ]), &(acadoWorkspace.x[ 48 ]), &(acadoWorkspace.sbar[ 144 ]), &(acadoWorkspace.sbar[ 150 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 900 ]), &(acadoWorkspace.evGu[ 300 ]), &(acadoWorkspace.x[ 50 ]), &(acadoWorkspace.sbar[ 150 ]), &(acadoWorkspace.sbar[ 156 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 936 ]), &(acadoWorkspace.evGu[ 312 ]), &(acadoWorkspace.x[ 52 ]), &(acadoWorkspace.sbar[ 156 ]), &(acadoWorkspace.sbar[ 162 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 972 ]), &(acadoWorkspace.evGu[ 324 ]), &(acadoWorkspace.x[ 54 ]), &(acadoWorkspace.sbar[ 162 ]), &(acadoWorkspace.sbar[ 168 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1008 ]), &(acadoWorkspace.evGu[ 336 ]), &(acadoWorkspace.x[ 56 ]), &(acadoWorkspace.sbar[ 168 ]), &(acadoWorkspace.sbar[ 174 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1044 ]), &(acadoWorkspace.evGu[ 348 ]), &(acadoWorkspace.x[ 58 ]), &(acadoWorkspace.sbar[ 174 ]), &(acadoWorkspace.sbar[ 180 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1080 ]), &(acadoWorkspace.evGu[ 360 ]), &(acadoWorkspace.x[ 60 ]), &(acadoWorkspace.sbar[ 180 ]), &(acadoWorkspace.sbar[ 186 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1116 ]), &(acadoWorkspace.evGu[ 372 ]), &(acadoWorkspace.x[ 62 ]), &(acadoWorkspace.sbar[ 186 ]), &(acadoWorkspace.sbar[ 192 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1152 ]), &(acadoWorkspace.evGu[ 384 ]), &(acadoWorkspace.x[ 64 ]), &(acadoWorkspace.sbar[ 192 ]), &(acadoWorkspace.sbar[ 198 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1188 ]), &(acadoWorkspace.evGu[ 396 ]), &(acadoWorkspace.x[ 66 ]), &(acadoWorkspace.sbar[ 198 ]), &(acadoWorkspace.sbar[ 204 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1224 ]), &(acadoWorkspace.evGu[ 408 ]), &(acadoWorkspace.x[ 68 ]), &(acadoWorkspace.sbar[ 204 ]), &(acadoWorkspace.sbar[ 210 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1260 ]), &(acadoWorkspace.evGu[ 420 ]), &(acadoWorkspace.x[ 70 ]), &(acadoWorkspace.sbar[ 210 ]), &(acadoWorkspace.sbar[ 216 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1296 ]), &(acadoWorkspace.evGu[ 432 ]), &(acadoWorkspace.x[ 72 ]), &(acadoWorkspace.sbar[ 216 ]), &(acadoWorkspace.sbar[ 222 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1332 ]), &(acadoWorkspace.evGu[ 444 ]), &(acadoWorkspace.x[ 74 ]), &(acadoWorkspace.sbar[ 222 ]), &(acadoWorkspace.sbar[ 228 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1368 ]), &(acadoWorkspace.evGu[ 456 ]), &(acadoWorkspace.x[ 76 ]), &(acadoWorkspace.sbar[ 228 ]), &(acadoWorkspace.sbar[ 234 ]) );
acado_expansionStep( &(acadoWorkspace.evGx[ 1404 ]), &(acadoWorkspace.evGu[ 468 ]), &(acadoWorkspace.x[ 78 ]), &(acadoWorkspace.sbar[ 234 ]), &(acadoWorkspace.sbar[ 240 ]) );
for (lRun1 = 0; lRun1 < 246; ++lRun1)
acadoVariables.x[lRun1] += acadoWorkspace.sbar[lRun1];

}

int acado_preparationStep(  )
{
int ret;

ret = acado_modelSimulation();
acado_evaluateObjective(  );
acado_condensePrep(  );
return ret;
}

int acado_feedbackStep(  )
{
int tmp;

acado_condenseFdb(  );

tmp = acado_solve( );

acado_expand(  );
return tmp;
}

int acado_initializeSolver(  )
{
int ret;

/* This is a function which must be called once before any other function call! */


ret = 0;

memset(&acadoWorkspace, 0, sizeof( acadoWorkspace ));
return ret;
}

void acado_initializeNodesByForwardSimulation(  )
{
int index;
for (index = 0; index < 40; ++index)
{
acadoWorkspace.state[0] = acadoVariables.x[index * 6];
acadoWorkspace.state[1] = acadoVariables.x[index * 6 + 1];
acadoWorkspace.state[2] = acadoVariables.x[index * 6 + 2];
acadoWorkspace.state[3] = acadoVariables.x[index * 6 + 3];
acadoWorkspace.state[4] = acadoVariables.x[index * 6 + 4];
acadoWorkspace.state[5] = acadoVariables.x[index * 6 + 5];
acadoWorkspace.state[54] = acadoVariables.u[index * 2];
acadoWorkspace.state[55] = acadoVariables.u[index * 2 + 1];
acadoWorkspace.state[56] = acadoVariables.od[index * 3];
acadoWorkspace.state[57] = acadoVariables.od[index * 3 + 1];
acadoWorkspace.state[58] = acadoVariables.od[index * 3 + 2];

acado_integrate(acadoWorkspace.state, index == 0);

acadoVariables.x[index * 6 + 6] = acadoWorkspace.state[0];
acadoVariables.x[index * 6 + 7] = acadoWorkspace.state[1];
acadoVariables.x[index * 6 + 8] = acadoWorkspace.state[2];
acadoVariables.x[index * 6 + 9] = acadoWorkspace.state[3];
acadoVariables.x[index * 6 + 10] = acadoWorkspace.state[4];
acadoVariables.x[index * 6 + 11] = acadoWorkspace.state[5];
}
}

void acado_shiftStates( int strategy, real_t* const xEnd, real_t* const uEnd )
{
int index;
for (index = 0; index < 40; ++index)
{
acadoVariables.x[index * 6] = acadoVariables.x[index * 6 + 6];
acadoVariables.x[index * 6 + 1] = acadoVariables.x[index * 6 + 7];
acadoVariables.x[index * 6 + 2] = acadoVariables.x[index * 6 + 8];
acadoVariables.x[index * 6 + 3] = acadoVariables.x[index * 6 + 9];
acadoVariables.x[index * 6 + 4] = acadoVariables.x[index * 6 + 10];
acadoVariables.x[index * 6 + 5] = acadoVariables.x[index * 6 + 11];
}

if (strategy == 1 && xEnd != 0)
{
acadoVariables.x[240] = xEnd[0];
acadoVariables.x[241] = xEnd[1];
acadoVariables.x[242] = xEnd[2];
acadoVariables.x[243] = xEnd[3];
acadoVariables.x[244] = xEnd[4];
acadoVariables.x[245] = xEnd[5];
}
else if (strategy == 2) 
{
acadoWorkspace.state[0] = acadoVariables.x[240];
acadoWorkspace.state[1] = acadoVariables.x[241];
acadoWorkspace.state[2] = acadoVariables.x[242];
acadoWorkspace.state[3] = acadoVariables.x[243];
acadoWorkspace.state[4] = acadoVariables.x[244];
acadoWorkspace.state[5] = acadoVariables.x[245];
if (uEnd != 0)
{
acadoWorkspace.state[54] = uEnd[0];
acadoWorkspace.state[55] = uEnd[1];
}
else
{
acadoWorkspace.state[54] = acadoVariables.u[78];
acadoWorkspace.state[55] = acadoVariables.u[79];
}
acadoWorkspace.state[56] = acadoVariables.od[120];
acadoWorkspace.state[57] = acadoVariables.od[121];
acadoWorkspace.state[58] = acadoVariables.od[122];

acado_integrate(acadoWorkspace.state, 1);

acadoVariables.x[240] = acadoWorkspace.state[0];
acadoVariables.x[241] = acadoWorkspace.state[1];
acadoVariables.x[242] = acadoWorkspace.state[2];
acadoVariables.x[243] = acadoWorkspace.state[3];
acadoVariables.x[244] = acadoWorkspace.state[4];
acadoVariables.x[245] = acadoWorkspace.state[5];
}
}

void acado_shiftControls( real_t* const uEnd )
{
int index;
for (index = 0; index < 39; ++index)
{
acadoVariables.u[index * 2] = acadoVariables.u[index * 2 + 2];
acadoVariables.u[index * 2 + 1] = acadoVariables.u[index * 2 + 3];
}

if (uEnd != 0)
{
acadoVariables.u[78] = uEnd[0];
acadoVariables.u[79] = uEnd[1];
}
}

real_t acado_getKKT(  )
{
real_t kkt;

int index;
real_t prd;

kkt = + acadoWorkspace.g[0]*acadoWorkspace.x[0] + acadoWorkspace.g[1]*acadoWorkspace.x[1] + acadoWorkspace.g[2]*acadoWorkspace.x[2] + acadoWorkspace.g[3]*acadoWorkspace.x[3] + acadoWorkspace.g[4]*acadoWorkspace.x[4] + acadoWorkspace.g[5]*acadoWorkspace.x[5] + acadoWorkspace.g[6]*acadoWorkspace.x[6] + acadoWorkspace.g[7]*acadoWorkspace.x[7] + acadoWorkspace.g[8]*acadoWorkspace.x[8] + acadoWorkspace.g[9]*acadoWorkspace.x[9] + acadoWorkspace.g[10]*acadoWorkspace.x[10] + acadoWorkspace.g[11]*acadoWorkspace.x[11] + acadoWorkspace.g[12]*acadoWorkspace.x[12] + acadoWorkspace.g[13]*acadoWorkspace.x[13] + acadoWorkspace.g[14]*acadoWorkspace.x[14] + acadoWorkspace.g[15]*acadoWorkspace.x[15] + acadoWorkspace.g[16]*acadoWorkspace.x[16] + acadoWorkspace.g[17]*acadoWorkspace.x[17] + acadoWorkspace.g[18]*acadoWorkspace.x[18] + acadoWorkspace.g[19]*acadoWorkspace.x[19] + acadoWorkspace.g[20]*acadoWorkspace.x[20] + acadoWorkspace.g[21]*acadoWorkspace.x[21] + acadoWorkspace.g[22]*acadoWorkspace.x[22] + acadoWorkspace.g[23]*acadoWorkspace.x[23] + acadoWorkspace.g[24]*acadoWorkspace.x[24] + acadoWorkspace.g[25]*acadoWorkspace.x[25] + acadoWorkspace.g[26]*acadoWorkspace.x[26] + acadoWorkspace.g[27]*acadoWorkspace.x[27] + acadoWorkspace.g[28]*acadoWorkspace.x[28] + acadoWorkspace.g[29]*acadoWorkspace.x[29] + acadoWorkspace.g[30]*acadoWorkspace.x[30] + acadoWorkspace.g[31]*acadoWorkspace.x[31] + acadoWorkspace.g[32]*acadoWorkspace.x[32] + acadoWorkspace.g[33]*acadoWorkspace.x[33] + acadoWorkspace.g[34]*acadoWorkspace.x[34] + acadoWorkspace.g[35]*acadoWorkspace.x[35] + acadoWorkspace.g[36]*acadoWorkspace.x[36] + acadoWorkspace.g[37]*acadoWorkspace.x[37] + acadoWorkspace.g[38]*acadoWorkspace.x[38] + acadoWorkspace.g[39]*acadoWorkspace.x[39] + acadoWorkspace.g[40]*acadoWorkspace.x[40] + acadoWorkspace.g[41]*acadoWorkspace.x[41] + acadoWorkspace.g[42]*acadoWorkspace.x[42] + acadoWorkspace.g[43]*acadoWorkspace.x[43] + acadoWorkspace.g[44]*acadoWorkspace.x[44] + acadoWorkspace.g[45]*acadoWorkspace.x[45] + acadoWorkspace.g[46]*acadoWorkspace.x[46] + acadoWorkspace.g[47]*acadoWorkspace.x[47] + acadoWorkspace.g[48]*acadoWorkspace.x[48] + acadoWorkspace.g[49]*acadoWorkspace.x[49] + acadoWorkspace.g[50]*acadoWorkspace.x[50] + acadoWorkspace.g[51]*acadoWorkspace.x[51] + acadoWorkspace.g[52]*acadoWorkspace.x[52] + acadoWorkspace.g[53]*acadoWorkspace.x[53] + acadoWorkspace.g[54]*acadoWorkspace.x[54] + acadoWorkspace.g[55]*acadoWorkspace.x[55] + acadoWorkspace.g[56]*acadoWorkspace.x[56] + acadoWorkspace.g[57]*acadoWorkspace.x[57] + acadoWorkspace.g[58]*acadoWorkspace.x[58] + acadoWorkspace.g[59]*acadoWorkspace.x[59] + acadoWorkspace.g[60]*acadoWorkspace.x[60] + acadoWorkspace.g[61]*acadoWorkspace.x[61] + acadoWorkspace.g[62]*acadoWorkspace.x[62] + acadoWorkspace.g[63]*acadoWorkspace.x[63] + acadoWorkspace.g[64]*acadoWorkspace.x[64] + acadoWorkspace.g[65]*acadoWorkspace.x[65] + acadoWorkspace.g[66]*acadoWorkspace.x[66] + acadoWorkspace.g[67]*acadoWorkspace.x[67] + acadoWorkspace.g[68]*acadoWorkspace.x[68] + acadoWorkspace.g[69]*acadoWorkspace.x[69] + acadoWorkspace.g[70]*acadoWorkspace.x[70] + acadoWorkspace.g[71]*acadoWorkspace.x[71] + acadoWorkspace.g[72]*acadoWorkspace.x[72] + acadoWorkspace.g[73]*acadoWorkspace.x[73] + acadoWorkspace.g[74]*acadoWorkspace.x[74] + acadoWorkspace.g[75]*acadoWorkspace.x[75] + acadoWorkspace.g[76]*acadoWorkspace.x[76] + acadoWorkspace.g[77]*acadoWorkspace.x[77] + acadoWorkspace.g[78]*acadoWorkspace.x[78] + acadoWorkspace.g[79]*acadoWorkspace.x[79];
kkt = fabs( kkt );
for (index = 0; index < 80; ++index)
{
prd = acadoWorkspace.y[index];
if (prd > 1e-12)
kkt += fabs(acadoWorkspace.lb[index] * prd);
else if (prd < -1e-12)
kkt += fabs(acadoWorkspace.ub[index] * prd);
}
for (index = 0; index < 200; ++index)
{
prd = acadoWorkspace.y[index + 80];
if (prd > 1e-12)
kkt += fabs(acadoWorkspace.lbA[index] * prd);
else if (prd < -1e-12)
kkt += fabs(acadoWorkspace.ubA[index] * prd);
}
return kkt;
}

real_t acado_getObjective(  )
{
real_t objVal;

int lRun1;
/** Row vector of size: 8 */
real_t tmpDy[ 8 ];

/** Row vector of size: 6 */
real_t tmpDyN[ 6 ];

for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
acadoWorkspace.objValueIn[0] = acadoVariables.x[lRun1 * 6];
acadoWorkspace.objValueIn[1] = acadoVariables.x[lRun1 * 6 + 1];
acadoWorkspace.objValueIn[2] = acadoVariables.x[lRun1 * 6 + 2];
acadoWorkspace.objValueIn[3] = acadoVariables.x[lRun1 * 6 + 3];
acadoWorkspace.objValueIn[4] = acadoVariables.x[lRun1 * 6 + 4];
acadoWorkspace.objValueIn[5] = acadoVariables.x[lRun1 * 6 + 5];
acadoWorkspace.objValueIn[6] = acadoVariables.u[lRun1 * 2];
acadoWorkspace.objValueIn[7] = acadoVariables.u[lRun1 * 2 + 1];
acadoWorkspace.objValueIn[8] = acadoVariables.od[lRun1 * 3];
acadoWorkspace.objValueIn[9] = acadoVariables.od[lRun1 * 3 + 1];
acadoWorkspace.objValueIn[10] = acadoVariables.od[lRun1 * 3 + 2];

acado_evaluateLSQ( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.Dy[lRun1 * 8] = acadoWorkspace.objValueOut[0] - acadoVariables.y[lRun1 * 8];
acadoWorkspace.Dy[lRun1 * 8 + 1] = acadoWorkspace.objValueOut[1] - acadoVariables.y[lRun1 * 8 + 1];
acadoWorkspace.Dy[lRun1 * 8 + 2] = acadoWorkspace.objValueOut[2] - acadoVariables.y[lRun1 * 8 + 2];
acadoWorkspace.Dy[lRun1 * 8 + 3] = acadoWorkspace.objValueOut[3] - acadoVariables.y[lRun1 * 8 + 3];
acadoWorkspace.Dy[lRun1 * 8 + 4] = acadoWorkspace.objValueOut[4] - acadoVariables.y[lRun1 * 8 + 4];
acadoWorkspace.Dy[lRun1 * 8 + 5] = acadoWorkspace.objValueOut[5] - acadoVariables.y[lRun1 * 8 + 5];
acadoWorkspace.Dy[lRun1 * 8 + 6] = acadoWorkspace.objValueOut[6] - acadoVariables.y[lRun1 * 8 + 6];
acadoWorkspace.Dy[lRun1 * 8 + 7] = acadoWorkspace.objValueOut[7] - acadoVariables.y[lRun1 * 8 + 7];
}
acadoWorkspace.objValueIn[0] = acadoVariables.x[240];
acadoWorkspace.objValueIn[1] = acadoVariables.x[241];
acadoWorkspace.objValueIn[2] = acadoVariables.x[242];
acadoWorkspace.objValueIn[3] = acadoVariables.x[243];
acadoWorkspace.objValueIn[4] = acadoVariables.x[244];
acadoWorkspace.objValueIn[5] = acadoVariables.x[245];
acadoWorkspace.objValueIn[6] = acadoVariables.od[120];
acadoWorkspace.objValueIn[7] = acadoVariables.od[121];
acadoWorkspace.objValueIn[8] = acadoVariables.od[122];
acado_evaluateLSQEndTerm( acadoWorkspace.objValueIn, acadoWorkspace.objValueOut );
acadoWorkspace.DyN[0] = acadoWorkspace.objValueOut[0] - acadoVariables.yN[0];
acadoWorkspace.DyN[1] = acadoWorkspace.objValueOut[1] - acadoVariables.yN[1];
acadoWorkspace.DyN[2] = acadoWorkspace.objValueOut[2] - acadoVariables.yN[2];
acadoWorkspace.DyN[3] = acadoWorkspace.objValueOut[3] - acadoVariables.yN[3];
acadoWorkspace.DyN[4] = acadoWorkspace.objValueOut[4] - acadoVariables.yN[4];
acadoWorkspace.DyN[5] = acadoWorkspace.objValueOut[5] - acadoVariables.yN[5];
objVal = 0.0000000000000000e+00;
for (lRun1 = 0; lRun1 < 40; ++lRun1)
{
tmpDy[0] = + acadoWorkspace.Dy[lRun1 * 8]*acadoVariables.W[0];
tmpDy[1] = + acadoWorkspace.Dy[lRun1 * 8 + 1]*acadoVariables.W[9];
tmpDy[2] = + acadoWorkspace.Dy[lRun1 * 8 + 2]*acadoVariables.W[18];
tmpDy[3] = + acadoWorkspace.Dy[lRun1 * 8 + 3]*acadoVariables.W[27];
tmpDy[4] = + acadoWorkspace.Dy[lRun1 * 8 + 4]*acadoVariables.W[36];
tmpDy[5] = + acadoWorkspace.Dy[lRun1 * 8 + 5]*acadoVariables.W[45];
tmpDy[6] = + acadoWorkspace.Dy[lRun1 * 8 + 6]*acadoVariables.W[54];
tmpDy[7] = + acadoWorkspace.Dy[lRun1 * 8 + 7]*acadoVariables.W[63];
objVal += + acadoWorkspace.Dy[lRun1 * 8]*tmpDy[0] + acadoWorkspace.Dy[lRun1 * 8 + 1]*tmpDy[1] + acadoWorkspace.Dy[lRun1 * 8 + 2]*tmpDy[2] + acadoWorkspace.Dy[lRun1 * 8 + 3]*tmpDy[3] + acadoWorkspace.Dy[lRun1 * 8 + 4]*tmpDy[4] + acadoWorkspace.Dy[lRun1 * 8 + 5]*tmpDy[5] + acadoWorkspace.Dy[lRun1 * 8 + 6]*tmpDy[6] + acadoWorkspace.Dy[lRun1 * 8 + 7]*tmpDy[7];
}

tmpDyN[0] = + acadoWorkspace.DyN[0]*acadoVariables.WN[0];
tmpDyN[1] = + acadoWorkspace.DyN[1]*acadoVariables.WN[7];
tmpDyN[2] = + acadoWorkspace.DyN[2]*acadoVariables.WN[14];
tmpDyN[3] = + acadoWorkspace.DyN[3]*acadoVariables.WN[21];
tmpDyN[4] = + acadoWorkspace.DyN[4]*acadoVariables.WN[28];
tmpDyN[5] = + acadoWorkspace.DyN[5]*acadoVariables.WN[35];
objVal += + acadoWorkspace.DyN[0]*tmpDyN[0] + acadoWorkspace.DyN[1]*tmpDyN[1] + acadoWorkspace.DyN[2]*tmpDyN[2] + acadoWorkspace.DyN[3]*tmpDyN[3] + acadoWorkspace.DyN[4]*tmpDyN[4] + acadoWorkspace.DyN[5]*tmpDyN[5];

objVal *= 0.5;
return objVal;
}

