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
    No* no = (No*)malloc(sizeof(No));
    no->valor = val;
    no->prox = lst;
    return no;
}

void imprimirLista(No* lst){
    if(lst == NULL){
        printf("Lista Vazia\n");
    }else{
        int cont = 0;
        while(lst != NULL){
            cont++;
            printf("Elemento %d = %d\n", cont,lst->valor);
            lst = lst->prox;
        }
    }
}

int len(No* lst){
    if(lst == NULL){
        return 0;
    }else{
        return 1 + len(lst->prox);
    }
}

int main(){

    No* lista = iniciarLista();
    lista = inserirInicio(lista,10);
    lista = inserirInicio(lista,30);
    lista = inserirInicio(lista,90);
  //  imprimirLista(lista);
    int tamanho = len(lista);
    printf("Tamanho da lista = %d\n", tamanho);
    return 0;
}