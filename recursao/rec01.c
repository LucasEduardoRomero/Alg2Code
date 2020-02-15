#include <stdio.h>

int multiplicar(int int1,int int2){

    //int1 contador
    //int2 soma

    if(int1 > 0){
        return int2 + multiplicar(int1-1,int2);
    }    
    else{
        if(int1 < 0){            
            return -int2 + multiplicar(int1+1,int2);               
        }else{
            return 0;
        }
    }
    

}


int main(){

    int contador,soma,res;

    printf("Digite um numero: ");
    scanf("%d",&contador);
    printf("Digite um numero: ");
    scanf("%d",&soma);
    res = multiplicar(contador,soma);
    printf("\n%d * %d = %d\n",contador,soma,res);
    return 0;
}