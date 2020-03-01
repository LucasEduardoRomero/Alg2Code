#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
} No;

No* iniciarLista(){
    return NULL;
}

No* inserirInicio(No* lst,int val){
    No* first = (No*) malloc(sizeof(No));
    first->prox = lst;
    first->valor = val;
    return first;
}

No* excluirElementos(No* lst){
    if(lst != NULL){
        excluirElementos(lst->prox);
        free(lst);  
        
    }
    return NULL;
}

void imprimirLista(No* lst){
    if( lst == NULL){
        printf("Lista Vazia\n");
    }
    int cont = 0;
    while( lst != NULL){
        cont++;
        printf("valor do elemento %d = %d\n",cont,lst->valor);
        lst = lst->prox;
    }
}

int main(){

    No* lista = iniciarLista();
    lista = inserirInicio(lista,10);
    lista = inserirInicio(lista,3);
    lista = inserirInicio(lista,4);
    lista = inserirInicio(lista,33);
    lista = inserirInicio(lista,45);
    lista = inserirInicio(lista,5);
    lista = inserirInicio(lista,101);

    imprimirLista(lista);

    lista = excluirElementos(lista);
    
    imprimirLista(lista);
    return 0;
}