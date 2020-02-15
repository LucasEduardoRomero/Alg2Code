#include <stdio.h>
#include <string.h>

float somatoria(float *vetor,int indice){    
    if(indice > 0 ){
        return vetor[indice-1] + somatoria(vetor,indice-1);
    }else{
        return vetor[indice];
    }
}
int main(){

    int ind,cont;
    float soma;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&ind);

    //**declaração do vetor com base na var ind
    float vet[ind];
    printf("\n");
    for(cont=0;ind>cont;cont++){
        printf("digite o numero do vetor: ");
        scanf("%f",&vet[cont]);
    }
    soma = somatoria(vet,(ind-1));
    printf("*******************************************\n");
    printf("Resultado da somatória = %.3f",soma);
    printf("\n*******************************************\n");
    return 0;
}