#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    float valor;
    struct No* prox;
}No;

No* iniciarLista(){
    return NULL;
}

No* inserirFinal(No* lst, float val){
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

No* duplicarLista(No* lst){
    if(lst != NULL){
        No* no = (No*)malloc(sizeof(No));
        no->valor = lst->valor; 
        no->prox = duplicarLista(lst->prox);
        return no;
    }else{
        return NULL;
    }
}

void imprimirLista(No* lst){
    int cont = 0;
    while(lst != NULL){
        cont++;
        printf("No %d = %.2f\n",cont,lst->valor);
        lst = lst->prox;
    }
    printf("---------\n");
}

int main(){

    No* lista = iniciarLista();
    lista = inserirFinal(lista, 2.1);
    imprimirLista(lista);
    
    No* lista2 = duplicarLista(lista);
    imprimirLista(lista2);
    return 0;
}