#include <stdio.h>

int fib(int n){

    if(n==1){
        return 1;
    }else{
        if(n==0){
            return 0;
        }else{
            return (fib(n-1)+fib(n-2));
        }
    }
}

int main(){

    int num,res;
    printf("Digite um numero");
    scanf("%d",&num);
    res = fib(num);
    printf("\nelemento %d da sequencia de fibonnaci = %d",num,res);

    return 0;
}