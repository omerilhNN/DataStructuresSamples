#include <stdio.h>

#define SIZE 3

void printUpperTriangularMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j < i) {
                printf("0\t");
            } else {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int upperTriangularMatrix[SIZE][SIZE];

    // Değerleri matrise atama
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j < i) {
                upperTriangularMatrix[i][j] = 0;
            } else {
                printf("Enter element at position (%d, %d): ", i, j);
                scanf("%d", &upperTriangularMatrix[i][j]);
            }
        }
    }

    // Üst üçgensel matrisi yazdırma
    printf("Upper Triangular Matrix:\n");
    printUpperTriangularMatrix(upperTriangularMatrix);

    return 0;
}