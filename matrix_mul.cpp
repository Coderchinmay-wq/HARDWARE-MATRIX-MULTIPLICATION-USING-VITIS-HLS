#include <ap_int.h>

#define N 4

void matrix_mul(int A[N][N], int B[N][N], int C[N][N])
{
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=A
#pragma HLS INTERFACE s_axilite port=B
#pragma HLS INTERFACE s_axilite port=C

    int i, j, k;

Row:
    for(i = 0; i < N; i++)
    {
Col:
        for(j = 0; j < N; j++)
        {
            int sum = 0;

Product:
            for(k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }

            C[i][j] = sum;
        }
    }
}