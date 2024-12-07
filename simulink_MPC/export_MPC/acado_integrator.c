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


void acado_rhs(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 6;
/* Vector of auxiliary variables; number of elements: 4. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = (cos(xd[4]));
a[1] = (sin(xd[4]));
a[2] = (cos(xd[4]));
a[3] = (sin(xd[4]));

/* Compute outputs: */
out[0] = (((real_t)(2.3876035623045149e-03)*u[1])+(xd[5]*xd[3]));
out[1] = ((a[0]*xd[0])-(a[1]*xd[3]));
out[2] = ((a[2]*xd[3])+(a[3]*xd[0]));
out[3] = (((((real_t)(-2.2463768115942028e+02)/xd[0])*xd[3])+((((real_t)(7.3231884057971016e+01)/xd[0])-xd[0])*xd[5]))+((real_t)(8.6956521739130437e+01)*u[0]));
out[4] = xd[5];
out[5] = (((((real_t)(-2.2981725564623270e+02)*xd[5])/xd[0])+(((real_t)(3.8360220155627253e+01)/xd[0])*xd[3]))+((real_t)(6.3040425128107799e+01)*u[0]));
}



void acado_diffs(const real_t* in, real_t* out)
{
const real_t* xd = in;
/* Vector of auxiliary variables; number of elements: 16. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = (cos(xd[4]));
a[1] = (sin(xd[4]));
a[2] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[4])));
a[3] = (cos(xd[4]));
a[4] = (sin(xd[4]));
a[5] = (cos(xd[4]));
a[6] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[4])));
a[7] = (cos(xd[4]));
a[8] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[9] = (a[8]*a[8]);
a[10] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[11] = (a[10]*a[10]);
a[12] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[13] = (a[12]*a[12]);
a[14] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[15] = (a[14]*a[14]);

/* Compute outputs: */
out[0] = (real_t)(0.0000000000000000e+00);
out[1] = (real_t)(0.0000000000000000e+00);
out[2] = (real_t)(0.0000000000000000e+00);
out[3] = xd[5];
out[4] = (real_t)(0.0000000000000000e+00);
out[5] = xd[3];
out[6] = (real_t)(0.0000000000000000e+00);
out[7] = (real_t)(2.3876035623045149e-03);
out[8] = a[0];
out[9] = (real_t)(0.0000000000000000e+00);
out[10] = (real_t)(0.0000000000000000e+00);
out[11] = ((real_t)(0.0000000000000000e+00)-a[1]);
out[12] = ((a[2]*xd[0])-(a[3]*xd[3]));
out[13] = (real_t)(0.0000000000000000e+00);
out[14] = (real_t)(0.0000000000000000e+00);
out[15] = (real_t)(0.0000000000000000e+00);
out[16] = a[4];
out[17] = (real_t)(0.0000000000000000e+00);
out[18] = (real_t)(0.0000000000000000e+00);
out[19] = a[5];
out[20] = ((a[6]*xd[3])+(a[7]*xd[0]));
out[21] = (real_t)(0.0000000000000000e+00);
out[22] = (real_t)(0.0000000000000000e+00);
out[23] = (real_t)(0.0000000000000000e+00);
out[24] = ((((real_t)(0.0000000000000000e+00)-((real_t)(-2.2463768115942028e+02)*a[9]))*xd[3])+((((real_t)(0.0000000000000000e+00)-((real_t)(7.3231884057971016e+01)*a[11]))-(real_t)(1.0000000000000000e+00))*xd[5]));
out[25] = (real_t)(0.0000000000000000e+00);
out[26] = (real_t)(0.0000000000000000e+00);
out[27] = ((real_t)(-2.2463768115942028e+02)/xd[0]);
out[28] = (real_t)(0.0000000000000000e+00);
out[29] = (((real_t)(7.3231884057971016e+01)/xd[0])-xd[0]);
out[30] = (real_t)(8.6956521739130437e+01);
out[31] = (real_t)(0.0000000000000000e+00);
out[32] = (real_t)(0.0000000000000000e+00);
out[33] = (real_t)(0.0000000000000000e+00);
out[34] = (real_t)(0.0000000000000000e+00);
out[35] = (real_t)(0.0000000000000000e+00);
out[36] = (real_t)(0.0000000000000000e+00);
out[37] = (real_t)(1.0000000000000000e+00);
out[38] = (real_t)(0.0000000000000000e+00);
out[39] = (real_t)(0.0000000000000000e+00);
out[40] = (((real_t)(0.0000000000000000e+00)-(((real_t)(-2.2981725564623270e+02)*xd[5])*a[13]))+(((real_t)(0.0000000000000000e+00)-((real_t)(3.8360220155627253e+01)*a[15]))*xd[3]));
out[41] = (real_t)(0.0000000000000000e+00);
out[42] = (real_t)(0.0000000000000000e+00);
out[43] = ((real_t)(3.8360220155627253e+01)/xd[0]);
out[44] = (real_t)(0.0000000000000000e+00);
out[45] = ((real_t)(-2.2981725564623270e+02)*a[12]);
out[46] = (real_t)(6.3040425128107799e+01);
out[47] = (real_t)(0.0000000000000000e+00);
}



void acado_solve_dim6_triangular( real_t* const A, real_t* const b )
{

b[5] = b[5]/A[35];
b[4] -= + A[29]*b[5];
b[4] = b[4]/A[28];
b[3] -= + A[23]*b[5];
b[3] -= + A[22]*b[4];
b[3] = b[3]/A[21];
b[2] -= + A[17]*b[5];
b[2] -= + A[16]*b[4];
b[2] -= + A[15]*b[3];
b[2] = b[2]/A[14];
b[1] -= + A[11]*b[5];
b[1] -= + A[10]*b[4];
b[1] -= + A[9]*b[3];
b[1] -= + A[8]*b[2];
b[1] = b[1]/A[7];
b[0] -= + A[5]*b[5];
b[0] -= + A[4]*b[4];
b[0] -= + A[3]*b[3];
b[0] -= + A[2]*b[2];
b[0] -= + A[1]*b[1];
b[0] = b[0]/A[0];
}

real_t acado_solve_dim6_system( real_t* const A, real_t* const b, int* const rk_perm )
{
real_t det;

int i;
int j;
int k;

int indexMax;

int intSwap;

real_t valueMax;

real_t temp;

for (i = 0; i < 6; ++i)
{
rk_perm[i] = i;
}
det = 1.0000000000000000e+00;
for( i=0; i < (5); i++ ) {
	indexMax = i;
	valueMax = fabs(A[i*6+i]);
	for( j=(i+1); j < 6; j++ ) {
		temp = fabs(A[j*6+i]);
		if( temp > valueMax ) {
			indexMax = j;
			valueMax = temp;
		}
	}
	if( indexMax > i ) {
for (k = 0; k < 6; ++k)
{
	acadoWorkspace.rk_dim6_swap = A[i*6+k];
	A[i*6+k] = A[indexMax*6+k];
	A[indexMax*6+k] = acadoWorkspace.rk_dim6_swap;
}
	acadoWorkspace.rk_dim6_swap = b[i];
	b[i] = b[indexMax];
	b[indexMax] = acadoWorkspace.rk_dim6_swap;
	intSwap = rk_perm[i];
	rk_perm[i] = rk_perm[indexMax];
	rk_perm[indexMax] = intSwap;
	}
	det *= A[i*6+i];
	for( j=i+1; j < 6; j++ ) {
		A[j*6+i] = -A[j*6+i]/A[i*6+i];
		for( k=i+1; k < 6; k++ ) {
			A[j*6+k] += A[j*6+i] * A[i*6+k];
		}
		b[j] += A[j*6+i] * b[i];
	}
}
det *= A[35];
det = fabs(det);
acado_solve_dim6_triangular( A, b );
return det;
}

void acado_solve_dim6_system_reuse( real_t* const A, real_t* const b, int* const rk_perm )
{

acadoWorkspace.rk_dim6_bPerm[0] = b[rk_perm[0]];
acadoWorkspace.rk_dim6_bPerm[1] = b[rk_perm[1]];
acadoWorkspace.rk_dim6_bPerm[2] = b[rk_perm[2]];
acadoWorkspace.rk_dim6_bPerm[3] = b[rk_perm[3]];
acadoWorkspace.rk_dim6_bPerm[4] = b[rk_perm[4]];
acadoWorkspace.rk_dim6_bPerm[5] = b[rk_perm[5]];
acadoWorkspace.rk_dim6_bPerm[1] += A[6]*acadoWorkspace.rk_dim6_bPerm[0];

acadoWorkspace.rk_dim6_bPerm[2] += A[12]*acadoWorkspace.rk_dim6_bPerm[0];
acadoWorkspace.rk_dim6_bPerm[2] += A[13]*acadoWorkspace.rk_dim6_bPerm[1];

acadoWorkspace.rk_dim6_bPerm[3] += A[18]*acadoWorkspace.rk_dim6_bPerm[0];
acadoWorkspace.rk_dim6_bPerm[3] += A[19]*acadoWorkspace.rk_dim6_bPerm[1];
acadoWorkspace.rk_dim6_bPerm[3] += A[20]*acadoWorkspace.rk_dim6_bPerm[2];

acadoWorkspace.rk_dim6_bPerm[4] += A[24]*acadoWorkspace.rk_dim6_bPerm[0];
acadoWorkspace.rk_dim6_bPerm[4] += A[25]*acadoWorkspace.rk_dim6_bPerm[1];
acadoWorkspace.rk_dim6_bPerm[4] += A[26]*acadoWorkspace.rk_dim6_bPerm[2];
acadoWorkspace.rk_dim6_bPerm[4] += A[27]*acadoWorkspace.rk_dim6_bPerm[3];

acadoWorkspace.rk_dim6_bPerm[5] += A[30]*acadoWorkspace.rk_dim6_bPerm[0];
acadoWorkspace.rk_dim6_bPerm[5] += A[31]*acadoWorkspace.rk_dim6_bPerm[1];
acadoWorkspace.rk_dim6_bPerm[5] += A[32]*acadoWorkspace.rk_dim6_bPerm[2];
acadoWorkspace.rk_dim6_bPerm[5] += A[33]*acadoWorkspace.rk_dim6_bPerm[3];
acadoWorkspace.rk_dim6_bPerm[5] += A[34]*acadoWorkspace.rk_dim6_bPerm[4];


acado_solve_dim6_triangular( A, acadoWorkspace.rk_dim6_bPerm );
b[0] = acadoWorkspace.rk_dim6_bPerm[0];
b[1] = acadoWorkspace.rk_dim6_bPerm[1];
b[2] = acadoWorkspace.rk_dim6_bPerm[2];
b[3] = acadoWorkspace.rk_dim6_bPerm[3];
b[4] = acadoWorkspace.rk_dim6_bPerm[4];
b[5] = acadoWorkspace.rk_dim6_bPerm[5];
}



/** Column vector of size: 1 */
static const real_t acado_Ah_mat[ 1 ] = 
{ 1.6666666666666668e-03 };


/* Fixed step size:0.00333333 */
int acado_integrate( real_t* const rk_eta, int resetIntegrator )
{
int error;

int i;
int j;
int k;
int run;
int run1;
int tmp_index1;
int tmp_index2;

real_t det;

acadoWorkspace.rk_ttt = 0.0000000000000000e+00;
acadoWorkspace.rk_xxx[6] = rk_eta[54];
acadoWorkspace.rk_xxx[7] = rk_eta[55];

for (run = 0; run < 3; ++run)
{
if( run > 0 ) {
for (i = 0; i < 6; ++i)
{
acadoWorkspace.rk_diffsPrev2[i * 8] = rk_eta[i * 6 + 6];
acadoWorkspace.rk_diffsPrev2[i * 8 + 1] = rk_eta[i * 6 + 7];
acadoWorkspace.rk_diffsPrev2[i * 8 + 2] = rk_eta[i * 6 + 8];
acadoWorkspace.rk_diffsPrev2[i * 8 + 3] = rk_eta[i * 6 + 9];
acadoWorkspace.rk_diffsPrev2[i * 8 + 4] = rk_eta[i * 6 + 10];
acadoWorkspace.rk_diffsPrev2[i * 8 + 5] = rk_eta[i * 6 + 11];
acadoWorkspace.rk_diffsPrev2[i * 8 + 6] = rk_eta[i * 2 + 42];
acadoWorkspace.rk_diffsPrev2[i * 8 + 7] = rk_eta[i * 2 + 43];
}
}
if( resetIntegrator ) {
for (i = 0; i < 1; ++i)
{
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 6; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 48 ]) );
for (j = 0; j < 6; ++j)
{
tmp_index1 = (run1 * 6) + (j);
acadoWorkspace.rk_A[tmp_index1 * 6] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 1] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 2] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 3] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 4] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 5] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 6) + (j)] -= 1.0000000000000000e+00;
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 6] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 6 + 1] = acadoWorkspace.rk_kkk[run1 + 1] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 6 + 2] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 6 + 3] = acadoWorkspace.rk_kkk[run1 + 3] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 6 + 4] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 6 + 5] = acadoWorkspace.rk_kkk[run1 + 5] - acadoWorkspace.rk_rhsTemp[5];
}
det = acado_solve_dim6_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim6_perm );
for (j = 0; j < 1; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 6];
acadoWorkspace.rk_kkk[j + 1] += acadoWorkspace.rk_b[j * 6 + 1];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 6 + 2];
acadoWorkspace.rk_kkk[j + 3] += acadoWorkspace.rk_b[j * 6 + 3];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 6 + 4];
acadoWorkspace.rk_kkk[j + 5] += acadoWorkspace.rk_b[j * 6 + 5];
}
}
}
for (i = 0; i < 5; ++i)
{
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 6; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 6] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 6 + 1] = acadoWorkspace.rk_kkk[run1 + 1] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 6 + 2] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 6 + 3] = acadoWorkspace.rk_kkk[run1 + 3] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 6 + 4] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 6 + 5] = acadoWorkspace.rk_kkk[run1 + 5] - acadoWorkspace.rk_rhsTemp[5];
}
acado_solve_dim6_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim6_perm );
for (j = 0; j < 1; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 6];
acadoWorkspace.rk_kkk[j + 1] += acadoWorkspace.rk_b[j * 6 + 1];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 6 + 2];
acadoWorkspace.rk_kkk[j + 3] += acadoWorkspace.rk_b[j * 6 + 3];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 6 + 4];
acadoWorkspace.rk_kkk[j + 5] += acadoWorkspace.rk_b[j * 6 + 5];
}
}
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 6; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 48 ]) );
for (j = 0; j < 6; ++j)
{
tmp_index1 = (run1 * 6) + (j);
acadoWorkspace.rk_A[tmp_index1 * 6] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 1] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 2] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 3] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 4] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 6 + 5] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 48) + (j * 8 + 5)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 6) + (j)] -= 1.0000000000000000e+00;
}
}
for (run1 = 0; run1 < 6; ++run1)
{
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_b[i * 6] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1)];
acadoWorkspace.rk_b[i * 6 + 1] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 8)];
acadoWorkspace.rk_b[i * 6 + 2] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 16)];
acadoWorkspace.rk_b[i * 6 + 3] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 24)];
acadoWorkspace.rk_b[i * 6 + 4] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 32)];
acadoWorkspace.rk_b[i * 6 + 5] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (run1 + 40)];
}
if( 0 == run1 ) {
det = acado_solve_dim6_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim6_perm );
}
 else {
acado_solve_dim6_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim6_perm );
}
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 6];
acadoWorkspace.rk_diffK[i + 1] = acadoWorkspace.rk_b[i * 6 + 1];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 6 + 2];
acadoWorkspace.rk_diffK[i + 3] = acadoWorkspace.rk_b[i * 6 + 3];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 6 + 4];
acadoWorkspace.rk_diffK[i + 5] = acadoWorkspace.rk_b[i * 6 + 5];
}
for (i = 0; i < 6; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 8) + (run1)] = (i == run1-0);
acadoWorkspace.rk_diffsNew2[(i * 8) + (run1)] += + acadoWorkspace.rk_diffK[i]*(real_t)3.3333333333333335e-03;
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (i = 0; i < 1; ++i)
{
for (j = 0; j < 6; ++j)
{
tmp_index1 = (i * 6) + (j);
tmp_index2 = (run1) + (j * 8);
acadoWorkspace.rk_b[tmp_index1] = - acadoWorkspace.rk_diffsTemp2[(i * 48) + (tmp_index2 + 6)];
}
}
acado_solve_dim6_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim6_perm );
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 6];
acadoWorkspace.rk_diffK[i + 1] = acadoWorkspace.rk_b[i * 6 + 1];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 6 + 2];
acadoWorkspace.rk_diffK[i + 3] = acadoWorkspace.rk_b[i * 6 + 3];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 6 + 4];
acadoWorkspace.rk_diffK[i + 5] = acadoWorkspace.rk_b[i * 6 + 5];
}
for (i = 0; i < 6; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 8) + (run1 + 6)] = + acadoWorkspace.rk_diffK[i]*(real_t)3.3333333333333335e-03;
}
}
rk_eta[0] += + acadoWorkspace.rk_kkk[0]*(real_t)3.3333333333333335e-03;
rk_eta[1] += + acadoWorkspace.rk_kkk[1]*(real_t)3.3333333333333335e-03;
rk_eta[2] += + acadoWorkspace.rk_kkk[2]*(real_t)3.3333333333333335e-03;
rk_eta[3] += + acadoWorkspace.rk_kkk[3]*(real_t)3.3333333333333335e-03;
rk_eta[4] += + acadoWorkspace.rk_kkk[4]*(real_t)3.3333333333333335e-03;
rk_eta[5] += + acadoWorkspace.rk_kkk[5]*(real_t)3.3333333333333335e-03;
if( run == 0 ) {
for (i = 0; i < 6; ++i)
{
for (j = 0; j < 6; ++j)
{
tmp_index2 = (j) + (i * 6);
rk_eta[tmp_index2 + 6] = acadoWorkspace.rk_diffsNew2[(i * 8) + (j)];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 42] = acadoWorkspace.rk_diffsNew2[(i * 8) + (j + 6)];
}
}
}
else {
for (i = 0; i < 6; ++i)
{
for (j = 0; j < 6; ++j)
{
tmp_index2 = (j) + (i * 6);
rk_eta[tmp_index2 + 6] = + acadoWorkspace.rk_diffsNew2[i * 8]*acadoWorkspace.rk_diffsPrev2[j];
rk_eta[tmp_index2 + 6] += + acadoWorkspace.rk_diffsNew2[i * 8 + 1]*acadoWorkspace.rk_diffsPrev2[j + 8];
rk_eta[tmp_index2 + 6] += + acadoWorkspace.rk_diffsNew2[i * 8 + 2]*acadoWorkspace.rk_diffsPrev2[j + 16];
rk_eta[tmp_index2 + 6] += + acadoWorkspace.rk_diffsNew2[i * 8 + 3]*acadoWorkspace.rk_diffsPrev2[j + 24];
rk_eta[tmp_index2 + 6] += + acadoWorkspace.rk_diffsNew2[i * 8 + 4]*acadoWorkspace.rk_diffsPrev2[j + 32];
rk_eta[tmp_index2 + 6] += + acadoWorkspace.rk_diffsNew2[i * 8 + 5]*acadoWorkspace.rk_diffsPrev2[j + 40];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 42] = acadoWorkspace.rk_diffsNew2[(i * 8) + (j + 6)];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8]*acadoWorkspace.rk_diffsPrev2[j + 6];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8 + 1]*acadoWorkspace.rk_diffsPrev2[j + 14];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8 + 2]*acadoWorkspace.rk_diffsPrev2[j + 22];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8 + 3]*acadoWorkspace.rk_diffsPrev2[j + 30];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8 + 4]*acadoWorkspace.rk_diffsPrev2[j + 38];
rk_eta[tmp_index2 + 42] += + acadoWorkspace.rk_diffsNew2[i * 8 + 5]*acadoWorkspace.rk_diffsPrev2[j + 46];
}
}
}
resetIntegrator = 0;
acadoWorkspace.rk_ttt += 3.3333333333333331e-01;
}
for (i = 0; i < 6; ++i)
{
}
if( det < 1e-12 ) {
error = 2;
} else if( det < 1e-6 ) {
error = 1;
} else {
error = 0;
}
return error;
}



