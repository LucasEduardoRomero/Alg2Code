#include <stdio.h>
void linha(int n){
    if( n > 0){
        printf("-");
        linha(n-1);
    }else{
        printf("\n");
    }
}
void desenhar(int n){
    if(n>0){
        desenhar(n-1);
        linha(n);
        desenhar(n-1); 
    }
}

int main(){
    int number;
    printf("Escreva a ordem da régua: ");
    scanf("%d",&number);
    desenhar(number);
    return 0;
}