#include <stdio.h>

int pesquisar(int a,int b){

    if(a%10 == a){
        if(a == b){
            return 1;
        }else{
            return 0;
        }
    }else{    
        if((a%10) == b){

            return 1 + pesquisar(a/10,b);
        }else{
            return 0 + pesquisar(a/10,b);
        }
    }
  

}
int main(){

    int algarismo,numero,vezes;

    printf("Digite o algarismo a ser pesquisado: ");
    scanf("%d",&algarismo);
    while(algarismo%10 != algarismo){
        printf("Número incorreto,digite o número novamente: ");
        scanf("%d",&algarismo);
    }
    printf("Digite o numero: ");
    scanf("%d",&numero);
    vezes = pesquisar(numero,algarismo);
    printf("\nO algarismo %d foi encontrado %d vezes no numero %d\n",algarismo,vezes,numero);
    return 0;
}