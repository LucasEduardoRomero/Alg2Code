#include <stdio.h>

int soma(int n){
    if(n<=0){
        return -1;
    }else{    
        if(n==2){
            return 1;
        }else{
            return  ((n-1) + soma(n-1));
        }
    }
}

int main(){

    int num,res;
    printf("Digite um numero: ");
    scanf("%d",&num);
    res = soma(num);
    if(res== -1){
        printf("Numero inserido invalido!\n");
    }else{
        printf("soma dos numeros inteiros positivos menores que %d = %d\n",num,res);
    }
    return 0;
}