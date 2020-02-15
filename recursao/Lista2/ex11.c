#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
//retorna recursivamente a quantidade de digitos de um numero
int contaDigitos(int numero){
    if( (numero%10) == numero){
        return 1;
    }else{
        return 1 + contaDigitos(numero/10);
    }
}
//retorna recursivamente a potencia de uma base por um expoente

int pot(int base,int exp){
    if( exp == 1){
        return base;
    }else{
        if( exp == 0 ){
            return 1;
        }else{
            return base*pot(base,(exp-1));
        } 
    }
}*/

//retorna recursivamente um na base binaria a partir de um parametro decimal
int decToBin(int inteiro){

    if( (inteiro/2) == 0 ){
        return inteiro%2;
    }else{
        if( (inteiro%2 == 0) ){
            return decToBin(inteiro/2)*10;
        }else{
            return ((decToBin(inteiro/2)*10)+1);
        }
    }
}

int main(){

    int res,n,b;
    
    printf("Digite um inteiro na base Decimal: ");
    scanf("%d",&n);    
    res = decToBin(n);
    printf("Decimal = %d -|- Binario = %d\n",n,res);
    return 0;
}