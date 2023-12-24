#include <stdio.h>

int main(){
    float sum(float list[],int n ){
        if(n){
            return sum(list,n-1) + list[n-1];
        }
        return 0;

    }
}