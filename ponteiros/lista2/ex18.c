#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    float valor;
    struct No* prox;
} No;

No* iniciarLista(){
    return NULL;
}

No* inserirFinal(No* lst,int val){
    No* no = (No*) malloc(sizeof(no));
    no->valor = val;
    no->prox = NULL;
    if(lst == NULL){
        lst = no;
    }else{
        No* aux = lst;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return lst;
}

No* primeiroParaUltimo(No* lst){
    No* aux = lst;
    if(aux == NULL){
        return NULL;
    }    
    while(aux->prox != NULL){
        aux = aux->prox;    
    }
    aux->prox = lst; // ultimo aponta para o primeiro
    lst = lst->prox; // inicio aponta para o segundo
    aux = aux->prox;
    aux->prox = NULL; // ultimo aponta para NULL
    return lst;
}

void imprimirLista(No* lst){
    int indice = 0;
    while(lst != NULL){
        indice++;
        printf("Elemento %d = %.2f\n",indice,lst->valor);
        lst = lst->prox;
    }
    printf("-----------\n\n\n");
}

int main(){

    No* lista = iniciarLista();
    for(int i =0;i < 30 ;i++){
        lista = inserirFinal(lista,i);
    }
    imprimirLista(lista);
    lista = primeiroParaUltimo(lista);
    imprimirLista(lista);
    return 0;
}