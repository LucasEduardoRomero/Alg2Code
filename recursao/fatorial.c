#include <stdio.h>

int fat(int num){

    if(num == 0){
        return 1;        
    }else{
        return num*fat(num-1);
    }
}

int main(){
    
    int fatorial,n;
    printf("Digite o numero para calcular o fatorial: ");
    scanf("%d",&n);
    fatorial = fat(n);
    printf("%d! = %d \n",n,fatorial);

    return 0;
}