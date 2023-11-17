#include <stdio.h>

void generateFibonacci(int n){
    int first =0,second =1,next;

    printf("Fibonacci sequence up to %d terms:\n",n);

    for(int i=0; i<n;i++){
        printf("%d",first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}
int main(){
    int n;

    //Get the number of terms assign upper bound of the output.
    printf("Enter the upper bound of the sequence");
    scanf("%d",&n);

    if(n<=0){
        printf("Please enter positive number: ");
        return 1;
    }

    generateFibonacci(n);

    return 0;
}