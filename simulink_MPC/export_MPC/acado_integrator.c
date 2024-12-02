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
const real_t* u = in + 7;
/* Vector of auxiliary variables; number of elements: 4. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = (cos(xd[1]));
a[1] = (sin(xd[1]));
a[2] = (cos(xd[1]));
a[3] = (sin(xd[1]));

/* Compute outputs: */
out[0] = (((real_t)(2.3876035623045149e-03)*u[1])+(xd[4]*xd[3]));
out[1] = xd[4];
out[2] = ((a[0]*xd[0])-(a[1]*xd[3]));
out[3] = (((((real_t)(-2.2463768115942028e+02)/xd[0])*xd[3])+((((real_t)(7.3231884057971016e+01)/xd[0])-xd[0])*xd[4]))+((real_t)(8.6956521739130437e+01)*xd[5]));
out[4] = (((((real_t)(3.8360220155627253e+01)/xd[0])*xd[3])+((real_t)(6.3040425128107799e+01)*xd[5]))-(((real_t)(2.2981725564623270e+02)*xd[4])/xd[0]));
out[5] = u[0];
out[6] = ((a[2]*xd[3])+(a[3]*xd[0]));
}



void acado_diffs(const real_t* in, real_t* out)
{
const real_t* xd = in;
/* Vector of auxiliary variables; number of elements: 16. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = (cos(xd[1]));
a[1] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[1])));
a[2] = (cos(xd[1]));
a[3] = (sin(xd[1]));
a[4] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[5] = (a[4]*a[4]);
a[6] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[7] = (a[6]*a[6]);
a[8] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[9] = (a[8]*a[8]);
a[10] = ((real_t)(1.0000000000000000e+00)/xd[0]);
a[11] = (a[10]*a[10]);
a[12] = (sin(xd[1]));
a[13] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[1])));
a[14] = (cos(xd[1]));
a[15] = (cos(xd[1]));

/* Compute outputs: */
out[0] = (real_t)(0.0000000000000000e+00);
out[1] = (real_t)(0.0000000000000000e+00);
out[2] = (real_t)(0.0000000000000000e+00);
out[3] = xd[4];
out[4] = xd[3];
out[5] = (real_t)(0.0000000000000000e+00);
out[6] = (real_t)(0.0000000000000000e+00);
out[7] = (real_t)(0.0000000000000000e+00);
out[8] = (real_t)(2.3876035623045149e-03);
out[9] = (real_t)(0.0000000000000000e+00);
out[10] = (real_t)(0.0000000000000000e+00);
out[11] = (real_t)(0.0000000000000000e+00);
out[12] = (real_t)(0.0000000000000000e+00);
out[13] = (real_t)(1.0000000000000000e+00);
out[14] = (real_t)(0.0000000000000000e+00);
out[15] = (real_t)(0.0000000000000000e+00);
out[16] = (real_t)(0.0000000000000000e+00);
out[17] = (real_t)(0.0000000000000000e+00);
out[18] = a[0];
out[19] = ((a[1]*xd[0])-(a[2]*xd[3]));
out[20] = (real_t)(0.0000000000000000e+00);
out[21] = ((real_t)(0.0000000000000000e+00)-a[3]);
out[22] = (real_t)(0.0000000000000000e+00);
out[23] = (real_t)(0.0000000000000000e+00);
out[24] = (real_t)(0.0000000000000000e+00);
out[25] = (real_t)(0.0000000000000000e+00);
out[26] = (real_t)(0.0000000000000000e+00);
out[27] = ((((real_t)(0.0000000000000000e+00)-((real_t)(-2.2463768115942028e+02)*a[5]))*xd[3])+((((real_t)(0.0000000000000000e+00)-((real_t)(7.3231884057971016e+01)*a[7]))-(real_t)(1.0000000000000000e+00))*xd[4]));
out[28] = (real_t)(0.0000000000000000e+00);
out[29] = (real_t)(0.0000000000000000e+00);
out[30] = ((real_t)(-2.2463768115942028e+02)/xd[0]);
out[31] = (((real_t)(7.3231884057971016e+01)/xd[0])-xd[0]);
out[32] = (real_t)(8.6956521739130437e+01);
out[33] = (real_t)(0.0000000000000000e+00);
out[34] = (real_t)(0.0000000000000000e+00);
out[35] = (real_t)(0.0000000000000000e+00);
out[36] = ((((real_t)(0.0000000000000000e+00)-((real_t)(3.8360220155627253e+01)*a[9]))*xd[3])-((real_t)(0.0000000000000000e+00)-(((real_t)(2.2981725564623270e+02)*xd[4])*a[11])));
out[37] = (real_t)(0.0000000000000000e+00);
out[38] = (real_t)(0.0000000000000000e+00);
out[39] = ((real_t)(3.8360220155627253e+01)/xd[0]);
out[40] = ((real_t)(0.0000000000000000e+00)-((real_t)(2.2981725564623270e+02)*a[10]));
out[41] = (real_t)(6.3040425128107799e+01);
out[42] = (real_t)(0.0000000000000000e+00);
out[43] = (real_t)(0.0000000000000000e+00);
out[44] = (real_t)(0.0000000000000000e+00);
out[45] = (real_t)(0.0000000000000000e+00);
out[46] = (real_t)(0.0000000000000000e+00);
out[47] = (real_t)(0.0000000000000000e+00);
out[48] = (real_t)(0.0000000000000000e+00);
out[49] = (real_t)(0.0000000000000000e+00);
out[50] = (real_t)(0.0000000000000000e+00);
out[51] = (real_t)(0.0000000000000000e+00);
out[52] = (real_t)(1.0000000000000000e+00);
out[53] = (real_t)(0.0000000000000000e+00);
out[54] = a[12];
out[55] = ((a[13]*xd[3])+(a[14]*xd[0]));
out[56] = (real_t)(0.0000000000000000e+00);
out[57] = a[15];
out[58] = (real_t)(0.0000000000000000e+00);
out[59] = (real_t)(0.0000000000000000e+00);
out[60] = (real_t)(0.0000000000000000e+00);
out[61] = (real_t)(0.0000000000000000e+00);
out[62] = (real_t)(0.0000000000000000e+00);
}



void acado_solve_dim7_triangular( real_t* const A, real_t* const b )
{

b[6] = b[6]/A[48];
b[5] -= + A[41]*b[6];
b[5] = b[5]/A[40];
b[4] -= + A[34]*b[6];
b[4] -= + A[33]*b[5];
b[4] = b[4]/A[32];
b[3] -= + A[27]*b[6];
b[3] -= + A[26]*b[5];
b[3] -= + A[25]*b[4];
b[3] = b[3]/A[24];
b[2] -= + A[20]*b[6];
b[2] -= + A[19]*b[5];
b[2] -= + A[18]*b[4];
b[2] -= + A[17]*b[3];
b[2] = b[2]/A[16];
b[1] -= + A[13]*b[6];
b[1] -= + A[12]*b[5];
b[1] -= + A[11]*b[4];
b[1] -= + A[10]*b[3];
b[1] -= + A[9]*b[2];
b[1] = b[1]/A[8];
b[0] -= + A[6]*b[6];
b[0] -= + A[5]*b[5];
b[0] -= + A[4]*b[4];
b[0] -= + A[3]*b[3];
b[0] -= + A[2]*b[2];
b[0] -= + A[1]*b[1];
b[0] = b[0]/A[0];
}

real_t acado_solve_dim7_system( real_t* const A, real_t* const b, int* const rk_perm )
{
real_t det;

int i;
int j;
int k;

int indexMax;

int intSwap;

real_t valueMax;

real_t temp;

for (i = 0; i < 7; ++i)
{
rk_perm[i] = i;
}
det = 1.0000000000000000e+00;
for( i=0; i < (6); i++ ) {
	indexMax = i;
	valueMax = fabs(A[i*7+i]);
	for( j=(i+1); j < 7; j++ ) {
		temp = fabs(A[j*7+i]);
		if( temp > valueMax ) {
			indexMax = j;
			valueMax = temp;
		}
	}
	if( indexMax > i ) {
for (k = 0; k < 7; ++k)
{
	acadoWorkspace.rk_dim7_swap = A[i*7+k];
	A[i*7+k] = A[indexMax*7+k];
	A[indexMax*7+k] = acadoWorkspace.rk_dim7_swap;
}
	acadoWorkspace.rk_dim7_swap = b[i];
	b[i] = b[indexMax];
	b[indexMax] = acadoWorkspace.rk_dim7_swap;
	intSwap = rk_perm[i];
	rk_perm[i] = rk_perm[indexMax];
	rk_perm[indexMax] = intSwap;
	}
	det *= A[i*7+i];
	for( j=i+1; j < 7; j++ ) {
		A[j*7+i] = -A[j*7+i]/A[i*7+i];
		for( k=i+1; k < 7; k++ ) {
			A[j*7+k] += A[j*7+i] * A[i*7+k];
		}
		b[j] += A[j*7+i] * b[i];
	}
}
det *= A[48];
det = fabs(det);
acado_solve_dim7_triangular( A, b );
return det;
}

void acado_solve_dim7_system_reuse( real_t* const A, real_t* const b, int* const rk_perm )
{

acadoWorkspace.rk_dim7_bPerm[0] = b[rk_perm[0]];
acadoWorkspace.rk_dim7_bPerm[1] = b[rk_perm[1]];
acadoWorkspace.rk_dim7_bPerm[2] = b[rk_perm[2]];
acadoWorkspace.rk_dim7_bPerm[3] = b[rk_perm[3]];
acadoWorkspace.rk_dim7_bPerm[4] = b[rk_perm[4]];
acadoWorkspace.rk_dim7_bPerm[5] = b[rk_perm[5]];
acadoWorkspace.rk_dim7_bPerm[6] = b[rk_perm[6]];
acadoWorkspace.rk_dim7_bPerm[1] += A[7]*acadoWorkspace.rk_dim7_bPerm[0];

acadoWorkspace.rk_dim7_bPerm[2] += A[14]*acadoWorkspace.rk_dim7_bPerm[0];
acadoWorkspace.rk_dim7_bPerm[2] += A[15]*acadoWorkspace.rk_dim7_bPerm[1];

acadoWorkspace.rk_dim7_bPerm[3] += A[21]*acadoWorkspace.rk_dim7_bPerm[0];
acadoWorkspace.rk_dim7_bPerm[3] += A[22]*acadoWorkspace.rk_dim7_bPerm[1];
acadoWorkspace.rk_dim7_bPerm[3] += A[23]*acadoWorkspace.rk_dim7_bPerm[2];

acadoWorkspace.rk_dim7_bPerm[4] += A[28]*acadoWorkspace.rk_dim7_bPerm[0];
acadoWorkspace.rk_dim7_bPerm[4] += A[29]*acadoWorkspace.rk_dim7_bPerm[1];
acadoWorkspace.rk_dim7_bPerm[4] += A[30]*acadoWorkspace.rk_dim7_bPerm[2];
acadoWorkspace.rk_dim7_bPerm[4] += A[31]*acadoWorkspace.rk_dim7_bPerm[3];

acadoWorkspace.rk_dim7_bPerm[5] += A[35]*acadoWorkspace.rk_dim7_bPerm[0];
acadoWorkspace.rk_dim7_bPerm[5] += A[36]*acadoWorkspace.rk_dim7_bPerm[1];
acadoWorkspace.rk_dim7_bPerm[5] += A[37]*acadoWorkspace.rk_dim7_bPerm[2];
acadoWorkspace.rk_dim7_bPerm[5] += A[38]*acadoWorkspace.rk_dim7_bPerm[3];
acadoWorkspace.rk_dim7_bPerm[5] += A[39]*acadoWorkspace.rk_dim7_bPerm[4];

acadoWorkspace.rk_dim7_bPerm[6] += A[42]*acadoWorkspace.rk_dim7_bPerm[0];
acadoWorkspace.rk_dim7_bPerm[6] += A[43]*acadoWorkspace.rk_dim7_bPerm[1];
acadoWorkspace.rk_dim7_bPerm[6] += A[44]*acadoWorkspace.rk_dim7_bPerm[2];
acadoWorkspace.rk_dim7_bPerm[6] += A[45]*acadoWorkspace.rk_dim7_bPerm[3];
acadoWorkspace.rk_dim7_bPerm[6] += A[46]*acadoWorkspace.rk_dim7_bPerm[4];
acadoWorkspace.rk_dim7_bPerm[6] += A[47]*acadoWorkspace.rk_dim7_bPerm[5];


acado_solve_dim7_triangular( A, acadoWorkspace.rk_dim7_bPerm );
b[0] = acadoWorkspace.rk_dim7_bPerm[0];
b[1] = acadoWorkspace.rk_dim7_bPerm[1];
b[2] = acadoWorkspace.rk_dim7_bPerm[2];
b[3] = acadoWorkspace.rk_dim7_bPerm[3];
b[4] = acadoWorkspace.rk_dim7_bPerm[4];
b[5] = acadoWorkspace.rk_dim7_bPerm[5];
b[6] = acadoWorkspace.rk_dim7_bPerm[6];
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
acadoWorkspace.rk_xxx[7] = rk_eta[70];
acadoWorkspace.rk_xxx[8] = rk_eta[71];

for (run = 0; run < 3; ++run)
{
if( run > 0 ) {
for (i = 0; i < 7; ++i)
{
acadoWorkspace.rk_diffsPrev2[i * 9] = rk_eta[i * 7 + 7];
acadoWorkspace.rk_diffsPrev2[i * 9 + 1] = rk_eta[i * 7 + 8];
acadoWorkspace.rk_diffsPrev2[i * 9 + 2] = rk_eta[i * 7 + 9];
acadoWorkspace.rk_diffsPrev2[i * 9 + 3] = rk_eta[i * 7 + 10];
acadoWorkspace.rk_diffsPrev2[i * 9 + 4] = rk_eta[i * 7 + 11];
acadoWorkspace.rk_diffsPrev2[i * 9 + 5] = rk_eta[i * 7 + 12];
acadoWorkspace.rk_diffsPrev2[i * 9 + 6] = rk_eta[i * 7 + 13];
acadoWorkspace.rk_diffsPrev2[i * 9 + 7] = rk_eta[i * 2 + 56];
acadoWorkspace.rk_diffsPrev2[i * 9 + 8] = rk_eta[i * 2 + 57];
}
}
if( resetIntegrator ) {
for (i = 0; i < 1; ++i)
{
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 63 ]) );
for (j = 0; j < 7; ++j)
{
tmp_index1 = (run1 * 7) + (j);
acadoWorkspace.rk_A[tmp_index1 * 7] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 1] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 2] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 3] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 4] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 5] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 6] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 7) + (j)] -= 1.0000000000000000e+00;
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 7] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 7 + 1] = acadoWorkspace.rk_kkk[run1 + 1] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 7 + 2] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 7 + 3] = acadoWorkspace.rk_kkk[run1 + 3] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 7 + 4] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 7 + 5] = acadoWorkspace.rk_kkk[run1 + 5] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 7 + 6] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[6];
}
det = acado_solve_dim7_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim7_perm );
for (j = 0; j < 1; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 7];
acadoWorkspace.rk_kkk[j + 1] += acadoWorkspace.rk_b[j * 7 + 1];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 7 + 2];
acadoWorkspace.rk_kkk[j + 3] += acadoWorkspace.rk_b[j * 7 + 3];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 7 + 4];
acadoWorkspace.rk_kkk[j + 5] += acadoWorkspace.rk_b[j * 7 + 5];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 7 + 6];
}
}
}
for (i = 0; i < 5; ++i)
{
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 7] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 7 + 1] = acadoWorkspace.rk_kkk[run1 + 1] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 7 + 2] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 7 + 3] = acadoWorkspace.rk_kkk[run1 + 3] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 7 + 4] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 7 + 5] = acadoWorkspace.rk_kkk[run1 + 5] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 7 + 6] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[6];
}
acado_solve_dim7_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim7_perm );
for (j = 0; j < 1; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 7];
acadoWorkspace.rk_kkk[j + 1] += acadoWorkspace.rk_b[j * 7 + 1];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 7 + 2];
acadoWorkspace.rk_kkk[j + 3] += acadoWorkspace.rk_b[j * 7 + 3];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 7 + 4];
acadoWorkspace.rk_kkk[j + 5] += acadoWorkspace.rk_b[j * 7 + 5];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 7 + 6];
}
}
for (run1 = 0; run1 < 1; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1]*acadoWorkspace.rk_kkk[tmp_index1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 63 ]) );
for (j = 0; j < 7; ++j)
{
tmp_index1 = (run1 * 7) + (j);
acadoWorkspace.rk_A[tmp_index1 * 7] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 1] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 2] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 3] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 4] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 5] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 7 + 6] = + acado_Ah_mat[run1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 7) + (j)] -= 1.0000000000000000e+00;
}
}
for (run1 = 0; run1 < 7; ++run1)
{
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_b[i * 7] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1)];
acadoWorkspace.rk_b[i * 7 + 1] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 9)];
acadoWorkspace.rk_b[i * 7 + 2] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 18)];
acadoWorkspace.rk_b[i * 7 + 3] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 27)];
acadoWorkspace.rk_b[i * 7 + 4] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 36)];
acadoWorkspace.rk_b[i * 7 + 5] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 45)];
acadoWorkspace.rk_b[i * 7 + 6] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 54)];
}
if( 0 == run1 ) {
det = acado_solve_dim7_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim7_perm );
}
 else {
acado_solve_dim7_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim7_perm );
}
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 7];
acadoWorkspace.rk_diffK[i + 1] = acadoWorkspace.rk_b[i * 7 + 1];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 7 + 2];
acadoWorkspace.rk_diffK[i + 3] = acadoWorkspace.rk_b[i * 7 + 3];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 7 + 4];
acadoWorkspace.rk_diffK[i + 5] = acadoWorkspace.rk_b[i * 7 + 5];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 7 + 6];
}
for (i = 0; i < 7; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1)] = (i == run1-0);
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1)] += + acadoWorkspace.rk_diffK[i]*(real_t)3.3333333333333335e-03;
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (i = 0; i < 1; ++i)
{
for (j = 0; j < 7; ++j)
{
tmp_index1 = (i * 7) + (j);
tmp_index2 = (run1) + (j * 9);
acadoWorkspace.rk_b[tmp_index1] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (tmp_index2 + 7)];
}
}
acado_solve_dim7_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim7_perm );
for (i = 0; i < 1; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 7];
acadoWorkspace.rk_diffK[i + 1] = acadoWorkspace.rk_b[i * 7 + 1];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 7 + 2];
acadoWorkspace.rk_diffK[i + 3] = acadoWorkspace.rk_b[i * 7 + 3];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 7 + 4];
acadoWorkspace.rk_diffK[i + 5] = acadoWorkspace.rk_b[i * 7 + 5];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 7 + 6];
}
for (i = 0; i < 7; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1 + 7)] = + acadoWorkspace.rk_diffK[i]*(real_t)3.3333333333333335e-03;
}
}
rk_eta[0] += + acadoWorkspace.rk_kkk[0]*(real_t)3.3333333333333335e-03;
rk_eta[1] += + acadoWorkspace.rk_kkk[1]*(real_t)3.3333333333333335e-03;
rk_eta[2] += + acadoWorkspace.rk_kkk[2]*(real_t)3.3333333333333335e-03;
rk_eta[3] += + acadoWorkspace.rk_kkk[3]*(real_t)3.3333333333333335e-03;
rk_eta[4] += + acadoWorkspace.rk_kkk[4]*(real_t)3.3333333333333335e-03;
rk_eta[5] += + acadoWorkspace.rk_kkk[5]*(real_t)3.3333333333333335e-03;
rk_eta[6] += + acadoWorkspace.rk_kkk[6]*(real_t)3.3333333333333335e-03;
if( run == 0 ) {
for (i = 0; i < 7; ++i)
{
for (j = 0; j < 7; ++j)
{
tmp_index2 = (j) + (i * 7);
rk_eta[tmp_index2 + 7] = acadoWorkspace.rk_diffsNew2[(i * 9) + (j)];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 56] = acadoWorkspace.rk_diffsNew2[(i * 9) + (j + 7)];
}
}
}
else {
for (i = 0; i < 7; ++i)
{
for (j = 0; j < 7; ++j)
{
tmp_index2 = (j) + (i * 7);
rk_eta[tmp_index2 + 7] = + acadoWorkspace.rk_diffsNew2[i * 9]*acadoWorkspace.rk_diffsPrev2[j];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 1]*acadoWorkspace.rk_diffsPrev2[j + 9];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 2]*acadoWorkspace.rk_diffsPrev2[j + 18];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 3]*acadoWorkspace.rk_diffsPrev2[j + 27];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 4]*acadoWorkspace.rk_diffsPrev2[j + 36];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 5]*acadoWorkspace.rk_diffsPrev2[j + 45];
rk_eta[tmp_index2 + 7] += + acadoWorkspace.rk_diffsNew2[i * 9 + 6]*acadoWorkspace.rk_diffsPrev2[j + 54];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 56] = acadoWorkspace.rk_diffsNew2[(i * 9) + (j + 7)];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9]*acadoWorkspace.rk_diffsPrev2[j + 7];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 1]*acadoWorkspace.rk_diffsPrev2[j + 16];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 2]*acadoWorkspace.rk_diffsPrev2[j + 25];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 3]*acadoWorkspace.rk_diffsPrev2[j + 34];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 4]*acadoWorkspace.rk_diffsPrev2[j + 43];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 5]*acadoWorkspace.rk_diffsPrev2[j + 52];
rk_eta[tmp_index2 + 56] += + acadoWorkspace.rk_diffsNew2[i * 9 + 6]*acadoWorkspace.rk_diffsPrev2[j + 61];
}
}
}
resetIntegrator = 0;
acadoWorkspace.rk_ttt += 3.3333333333333331e-01;
}
for (i = 0; i < 7; ++i)
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



