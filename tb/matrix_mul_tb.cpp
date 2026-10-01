#include <iostream>
using namespace std;

#define N 4

void matrix_mul(int A[N][N], int B[N][N], int C[N][N]);

int main()
{
    int A[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[N][N] =
    {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    int C[N][N];

    matrix_mul(A, B, C);

    cout << "Output Matrix" << endl;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
