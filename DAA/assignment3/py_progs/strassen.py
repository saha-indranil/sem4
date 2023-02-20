# Write a Python program to implement Strassen’s matrix multiplication.

import numpy as np


def strassen_multiply(A, B):
    n = A.shape[0]

    # Base case: if the matrices are 1x1
    if n == 1:
        return A * B

    # Split matrices into quadrants
    A11 = A[:n//2, :n//2]
    A12 = A[:n//2, n//2:]
    A21 = A[n//2:, :n//2]
    A22 = A[n//2:, n//2:]

    B11 = B[:n//2, :n//2]
    B12 = B[:n//2, n//2:]
    B21 = B[n//2:, :n//2]
    B22 = B[n//2:, n//2:]

    # Recursively compute products of smaller matrices
    P1 = strassen_multiply(A11 + A22, B11 + B22)
    P2 = strassen_multiply(A21 + A22, B11)
    P3 = strassen_multiply(A11, B12 - B22)
    P4 = strassen_multiply(A22, B21 - B11)
    P5 = strassen_multiply(A11 + A12, B22)
    P6 = strassen_multiply(A21 - A11, B11 + B12)
    P7 = strassen_multiply(A12 - A22, B21 + B22)

    # Compute the quadrants of the product matrix
    C11 = P1 + P4 - P5 + P7
    C12 = P3 + P5
    C21 = P2 + P4
    C22 = P1 - P2 + P3 + P6

    # Combine the quadrants into a single matrix and return
    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
    return C


if __name__ == "__main__":
    n = 4
    A = [[i+j for j in range(n)] for i in range(n)]
    B = [[2*A[i][j] for j in range(n)] for i in range(n)]
    print("Strassen's Matrix Multiplication in Python")
    print("A matrix =")
    print(A)
    print("B matrix =")
    print(B)
    A = np.array(A)
    B = np.array(B)
    C = strassen_multiply(A, B)
    C = C.tolist()
    print("A*B matrix =")
    print(C)

# OUTPUT
# Strassen's Matrix Multiplication in Python
# A matrix =
# [[0, 1, 2, 3], [1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6]]
# B matrix =
# [[0, 2, 4, 6], [2, 4, 6, 8], [4, 6, 8, 10], [6, 8, 10, 12]]
# A*B matrix =
# [[28, 40, 52, 64], [40, 60, 80, 100], [52, 80, 108, 136], [64, 100, 136, 172]]
