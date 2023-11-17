#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int *data, int start, int end) {
    if (start == end) {
        //Print permutation result
        for (int i = 0; i <= end; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Swapping elements.
            swap(&data[start], &data[i]);

            //Recursively call generatePermutations with start+1
            generatePermutations(data, start + 1, end);

            // Backtrack
            swap(&data[start], &data[i]);
        }
    }
}

int main() {
    int n;
    int *data;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    data = (int *)malloc(n*sizeof(int));

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    //Permutation process and printing result.
    printf("Permutations: \n");
    generatePermutations(data, 0, n - 1);

    free(data);

    return 0;
}