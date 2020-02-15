#include <stdio.h>
#include <string.h>

int f(int* vetor,int n){
    if(n <= 0){
        return 1;
    }
    return vetor[n-1]*f(vetor,n-2)+1;
}

int main(){
    int num,res;
    int vet[6] = {0,1,2,3,4,5};
    printf("Digite um numero inteiro: ");
    scanf("%d",&num);
    res = f(vet,num);
    printf("Resultado = %d\n",res);
    return 0;
}