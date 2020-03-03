#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
}No;

No* iniciarLista(){
    return NULL;
}

No* inserirFinal(No* lst, int val){
    No* no = (No*)malloc(sizeof(No));
    no->prox = NULL;
    no->valor = val;
    if(lst != NULL){
        No* aux = lst;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }else{
        lst = no;        
    }
    return lst;
}

int contarNos(No* lst){
    if(lst != NULL){
        return 1 + contarNos(lst->prox);
    }else{
        return 0;
    }
}

float calcMedia(No* lst){
    float sum = 0;
    int quant = contarNos(lst);
    while(lst != NULL){
        sum += lst->valor;
        lst = lst->prox;
    }
    return (sum/quant);
}   

void imprimirLista(No* lst){
    int cont = 0;
    while(lst != NULL){
        cont++;
        printf("No %d = %d\n",cont,lst->valor);
        lst = lst->prox;
    }
    printf("---------\n");
}

int main(){

    No* lista = iniciarLista();
    lista = inserirFinal(lista,2);
    lista = inserirFinal(lista,10);
    lista = inserirFinal(lista,3);
    float media = calcMedia(lista);
    printf("%.2f\n",media);

    return 0;
}