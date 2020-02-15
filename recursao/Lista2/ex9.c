#include <stdio.h>
#include <string.h>


long int somatorio(long int k){

    if(k == 0){
        printf("%li",k);
        return k;
    }else{        
        long int aux = k+somatorio(k-1);
        printf(", %li", aux );
        return aux;
    }
}

int main(){

    long int n;
    printf("Digite um valor inteior N: ");
    scanf("%li",&n);    
    if(n < 0){
        printf("\n**NUMERO INVALIDO**\n");
    }else{
        somatorio(n);
    }
    printf("\n");
    return 0;   
}