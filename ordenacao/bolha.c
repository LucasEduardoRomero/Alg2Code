#include <stdio.h>

int estourarBolha(int *vetor){
    int k,aux;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            k=j+1;
            if(vetor[j] > vetor[k]){
                aux = vetor[j];
                vetor[j] = vetor[k];
                vetor[k] = aux;
            }
        }
    }
    return 1;
}


int main(){

    int vetor[5];
    int cont=0;
    int num=0;
    while(cont < 5){
        printf("\nDigite um número: ");
        scanf("%d",&num);
        vetor[cont] = num;
        cont++;
    }
    estourarBolha(vetor);

        printf("\n VETOR ORDENADO POR BOLHA:\n ");
    for(int i=0;i<5;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    return 0;
}