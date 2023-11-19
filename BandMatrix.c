#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, bandWidth;

    printf("Enter matris size: \n");
    scanf("%d",&size);

    printf("Enter matris band width: ");
    scanf("%d",&bandWidth);

    //Allocate memory for 1D band matrix.
    int *matrix = (int *)malloc(size*size*sizeof(int ));

    for(int i=0; i< size;i++){
        for(int j =0; j<size; j++){
            if(abs(i-j)<=bandWidth){ //Just get input for non-zero elements.
                printf("matrix[%d][%d]",i,j);
                scanf("%d",&matrix[i*size+ j]); //THATS BECAUSE WE KEEP MATRIX in 1D Array.
            }
        }
    }
    printf("Band Matrix: \n");
    for(int i =0; i<size;i++){
        for(int j =0; j<size; j++){
            if(abs(i-j)<=bandWidth){
                printf("%d ",matrix[i*size + j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    free(matrix);

    return 0;
}