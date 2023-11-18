#include <stdio.h>
#include <stdlib.h>

int recursiveFibonacci(int n){
    if(n<= 1){
        return n;
    }else{
        return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
}

int main(){
    int n;

    printf("Enter the number of terms that you want to see in the Fibonacci sequence:");
    scanf("%d",&n);

    printf("Fibonaci series for %d elements. \n",n);
    for(int i=0; i<n; i++){
        printf("%d ", recursiveFibonacci(i));
    }
}