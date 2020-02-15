/*
    Input: 1234 +
    Operacao: (12 + 34)
    Output : 46
    Input 2222 *
    Operacao: (22*22)
    Output:484
    Input: 6969 %
    Operacao: nada
    Output: 6969
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pesquisarBin(int num,int *vet,int lenf){

    int contador=0;
    int lim_inf,lim_sup,med;
    lim_inf = 0;
    lim_sup = lenf-1;
    med = (lim_sup-lim_inf)/2;    
    while((vet[med]!=num) && (contador<=lenf)){
        
        if(num==vet[med]){
            return med;
        }else{
            if(num > vet[med]){
                lim_sup = med-1;
                med = (lim_sup-lim_inf)/2;       
            }else{
                lim_inf = med+1; 
                med = (lim_sup-lim_inf)/2 + lim_inf;
            }
        }
        contador++;
    }
    if(vet[med]!=num){
        med = -1;
    }
    return med; 
  
}
int main(){
    
    int aux,indice;
    int len,num;
    int numeros[1000];
    printf("Digite quantos numeros o vetor ordenado de forma decrescente tem: ");
    scanf("%d",&len);
    if(len > 0){
        for(int cont=0;cont<len;cont++){
            printf("\nDigite um numero: ");
            scanf("%d",&aux);
            numeros[cont] = aux;
        }
        printf("Digite o numero a ser procurado: ");
        scanf("%d",&num); 
        indice = pesquisarBin(num,numeros,len); 
        if(indice >= 0){
            printf("\n vetor[%d] = %d \n ",indice,num);        
        }else{
            printf("\nO numero procurado não está presente no vetor\n");        
        }    
        
    }else{
        printf("\n Tamanho inválido para um vetor \n");
    }
    return 0;
}