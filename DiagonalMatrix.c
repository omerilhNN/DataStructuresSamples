#include <stdio.h>
#include <stdlib.h>

struct DiagonalMatrix{
    int *elements;
    int dimension;
};

struct DiagonalMatrix* createDiagonalMatrix(int dimension){
    struct DiagonalMatrix *matrixPtr = (struct DiagonalMatrix*)malloc(sizeof(struct DiagonalMatrix));

    if(matrixPtr == NULL){
        fprintf(stderr,"Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    matrixPtr -> dimension = dimension;
    matrixPtr -> elements = (int *)malloc(dimension*sizeof(int));

    if(matrixPtr->elements == NULL){
        fprintf(stderr, "Memory Allocation error\n");
        free(matrixPtr);
        exit(EXIT_FAILURE);
    }
    //Initializing 0 to every elements of the array.
    for(int i=0; i<dimension;i++){
        matrixPtr->elements[i] = 0;
    }
    return matrixPtr;
}
void printDiagonalMatrix(struct DiagonalMatrix *matrixPtr){
    printf("Diagonal matrix\n");
    for(int i=0; i<matrixPtr->dimension; i++){
        for(int j =0; j<matrixPtr->dimension;j++){
            if(i==j){
                printf("%d ",matrixPtr->elements[i]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void freeDiagonalMatrix(struct DiagonalMatrix *matrixPtr){
    free(matrixPtr->elements);
    free(matrixPtr);
}
int main(){
    int dimension;

    printf("Enter the dimension of Diagonal Matrix: \n");
    scanf("%d",&dimension);

    struct DiagonalMatrix *diagonalMatrix = createDiagonalMatrix(dimension);

    printf("Enter the elements of the Diagonal Matrix \n");
    for(int i=0; i <dimension; i++){
        printf("Element [%d][%d]:", i + 1, i + 1);
        scanf("%d", &diagonalMatrix->elements[i]);
    }

    printDiagonalMatrix(diagonalMatrix);

    freeDiagonalMatrix(diagonalMatrix);

    return 0;

}