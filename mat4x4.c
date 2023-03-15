#include <stdio.h>
#include "math.h"
int c1=0,c2=0,c3=0,addi=0,subt=0,mat=0,mult;
void add(int A[][8], int B[][8], int n, int C[][8])
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    c1++;
}

void sub(int A[][8], int B[][8], int n, int C[][8])
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    c2++;
}

void strassen(int A[][8], int B[][8], int C[][8])
{
    int i, j, k,rec,mu;;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            C[i][j] = 0;
            for (k = 0; k < 8; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    c3++;
    return;
    i=0;j=0;
    if(mat==2) {
        rec=1;
        mu=1;
    }
    // allocate memory for submatrices
    int A11[4][4], A12[4][4], A21[4][4], A22[4][4];
    int B11[4][4], B12[4][4], B21[4][4], B22[4][4];
    int C11[4][4], C12[4][4], C21[4][4], C22[4][4];
    int M1[4][4], M2[4][4], M3[4][4], M4[4][4], M5[4][4], M6[4][4], M7[4][4];
    if(mat==4){
        rec=7;
        mu=2;
    }
    if(mat==5){
        rec=49;
        mu=3;
    }
    addi=rec*18;
    mult=pow(7,mu);
    // divide matrices into submatrices
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + 4];
            A21[i][j] = A[i + 4][j];
            A22[i][j] = A[i + 4][j + 4];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + 4];
            B21[i][j] = B[i + 4][j];
            B22[i][j] = B[i + 4][j + 4];
        }
    }

    // compute submatrices M1 to M7
    sub(B12, B22, 4, M1);
    strassen(A11, M1, M2);
    add(C11, M2, 4, C11);

    add(A11, A12, 4, M1);
    strassen(M1, B22, M2);
    sub(C12, M2, 4, C12);

    add(A21, A22, 4, M1);
    strassen(M1, B11, M2);
    sub(M2, C21, 4, C21);

sub(B21, B11, 4, M1);
strassen(A22, M1, M2);
add(C22, M2, 4, C22);

add(A11, A22, 4, M1);
add(B11, B22, 4, M2);
strassen(M1, M2, M3);
add(C11, M3, 4, C11);

sub(A12, A22, 4, M1);
add(B21, B22, 4, M2);
strassen(M1, M2, M3);
add(C21, M3, 4, C21);

sub(A11, A21, 4, M1);
add(B11, B12, 4, M2);
strassen(M1, M2, M3);
add(C12, M3, 4, C12);

add(A12, A21, 4, M1);
strassen(M1, B22, M2);
add(C22, M2, 4, C22);



// merge submatrices into result matrix
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        C[i][j] = C11[i][j];
        C[i][j + 4] = C12[i][j];
        C[i + 4][j] = C21[i][j];
        C[i + 4][j + 4] = C22[i][j];
    }
}
}

void print_matrix(int A[][8])
{
int i, j;
for (i = 0; i < 8; i++) {
for (j = 0; j < 8; j++) {
printf("%d ", A[i][j]);
}
printf("\n");
}
}

int main()
{

//int A[8][8],B[8][8],C[8][8];
int A[8][8] = {{1,2,3,4,5,6,7,8},
{9,10,11,12,13,14,15,16},
{17,18,19,20,21,22,23,24},
{25,26,27,28,29,30,31,32},
{33,34,35,36,37,38,39,40},
{41,42,43,44,45,46,47,48},
{49,50,51,52,53,54,55,56},
{57,58,59,60,61,62,63,64}};
int B[8][8] = {{1,2,3,4,5,6,7,8},
{9,10,11,12,13,14,15,16},
{17,18,19,20,21,22,23,24},
{25,26,27,28,29,30,31,32},
{33,34,35,36,37,38,39,40},
{41,42,43,44,45,46,47,48},
{49,50,51,52,53,54,55,56},
{57,58,59,60,61,62,63,64}};
int C[8][8];
int i,j;
//printf("give the input of A matrix\n");
//for(i=0;i<8;i++)
//{
//    for(j=0;j<8;j++)
//    scanf("%d",&A[i][j]);
//}
//printf("give the input of B matrix\n");
//for(i=0;i<8;i++)
//{
//    for(j=0;j<8;j++)
//    scanf("%d",&B[i][j]);
//}
strassen(A, B, C);


printf("\nMatrix C (A x B):\n");
print_matrix(C);
printf("number of addition operators are: %d\n",c1);
printf("number of subtraction operators are: %d\n",c2);
printf("number of multiplication operators are: %d\n",mult);
printf("total number of addition operators are: %d\n",addi+subt);

return 0;

}
