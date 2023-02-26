// Write a C program to implement Strassen’s matrix multiplication.

#include <stdio.h>
#include <stdlib.h>

void strassen(int n, int A[][n], int B[][n], int C[][n]);
void add(int n, int A[][n], int B[][n], int C[][n]);
void subtract(int n, int A[][n], int B[][n], int C[][n]);

int main()
{
    int n = 4, i, j;
    int A[n][n], B[n][n], C[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = i + j;
            B[i][j] = 2 * A[i][j];
        }
    }

    printf("Strassen's Matrix Multiplication in C\n", n, n);
    printf("Order of both matrices: %d * %d\n", n, n);
    strassen(n, A, B, C);

    printf("\nA matrix=\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }

    printf("\nB matrix=\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }

    printf("\nAxB matrix=\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}

void strassen(int n, int A[][n], int B[][n], int C[][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j;

    int A11[n / 2][n / 2], A12[n / 2][n / 2], A21[n / 2][n / 2], A22[n / 2][n / 2];
    int B11[n / 2][n / 2], B12[n / 2][n / 2], B21[n / 2][n / 2], B22[n / 2][n / 2];
    int C11[n / 2][n / 2], C12[n / 2][n / 2], C21[n / 2][n / 2], C22[n / 2][n / 2];
    int P1[n / 2][n / 2], P2[n / 2][n / 2], P3[n / 2][n / 2], P4[n / 2][n / 2], P5[n / 2][n / 2], P6[n / 2][n / 2], P7[n / 2][n / 2];
    int temp1[n / 2][n / 2], temp2[n / 2][n / 2];

    // Divide A into 4 submatrices
    for (i = 0; i < n / 2; i++)
        for (j = 0; j < n / 2; j++)
            A11[i][j] = A[i][j];
    for (i = 0; i < n / 2; i++)
        for (j = n / 2; j < n; j++)
            A12[i][j - n / 2] = A[i][j];
    for (i = n / 2; i < n; i++)
        for (j = 0; j < n / 2; j++)
            A21[i - n / 2][j] = A[i][j];
    for (i = n / 2; i < n; i++)
        for (j = n / 2; j < n; j++)
            A22[i - n / 2][j - n / 2] = A[i][j];

    // Divide B into 4 submatrices
    for (i = 0; i < n / 2; i++)
        for (j = 0; j < n / 2; j++)
            B11[i][j] = B[i][j];
    for (i = 0; i < n / 2; i++)
        for (j = n / 2; j < n; j++)
            B12[i][j - n / 2] = B[i][j];
    for (i = n / 2; i < n; i++)
        for (j = 0; j < n / 2; j++)
            B21[i - n / 2][j] = B[i][j];
    for (i = n / 2; i < n; i++)
        for (j = n / 2; j < n; j++)
            B22[i - n / 2][j - n / 2] = B[i][j];

    // Calculate the 7 products
    add(n / 2, A11, A22, temp1);
    add(n / 2, B11, B22, temp2);
    strassen(n / 2, temp1, temp2, P1);

    add(n / 2, A21, A22, temp1);
    strassen(n / 2, temp1, B11, P2);

    subtract(n / 2, B12, B22, temp1);
    strassen(n / 2, A11, temp1, P3);

    subtract(n / 2, B21, B11, temp1);
    strassen(n / 2, A22, temp1, P4);

    add(n / 2, A11, A12, temp1);
    strassen(n / 2, temp1, B22, P5);

    subtract(n / 2, A21, A11, temp1);
    add(n / 2, B11, B12, temp2);
    strassen(n / 2, temp1, temp2, P6);

    subtract(n / 2, A12, A22, temp1);
    add(n / 2, B21, B22, temp2);
    strassen(n / 2, temp1, temp2, P7);

    // Calculate the 4 quadrants of C using the products
    add(n / 2, P1, P4, temp1);
    subtract(n / 2, temp1, P5, temp2);
    add(n / 2, temp2, P7, C11);

    add(n / 2, P3, P5, C12);

    add(n / 2, P2, P4, C21);

    add(n / 2, P1, P3, temp1);
    subtract(n / 2, temp1, P2, temp2);
    add(n / 2, temp2, P6, C22);

    // Combine the 4 quadrants of C into one matrix
    for (i = 0; i < n / 2; i++)
        for (j = 0; j < n / 2; j++)
            C[i][j] = C11[i][j];
    for (i = 0; i < n / 2; i++)
        for (j = n / 2; j < n; j++)
            C[i][j] = C12[i][j - n / 2];
    for (i = n / 2; i < n; i++)
        for (j = 0; j < n / 2; j++)
            C[i][j] = C21[i - n / 2][j];
    for (i = n / 2; i < n; i++)
        for (j = n / 2; j < n; j++)
            C[i][j] = C22[i - n / 2][j - n / 2];
}

void add(int n, int A[][n], int B[][n], int C[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[][n], int B[][n], int C[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// OUTPUT
// Strassen's Matrix Multiplication
// Order of both matrices: 4 * 4

// A matrix=
// 0       1       2       3
// 1       2       3       4
// 2       3       4       5
// 3       4       5       6

// B matrix=
// 0       2       4       6
// 2       4       6       8
// 4       6       8       10
// 6       8       10      12

// AxB matrix=
// 28      40      52      64
// 40      60      80      100
// 52      80      108     136
// 64      100     136     172