// ---------------------------------------------
//-----ATENÇÃO-----------------------------------
// para não existir confusão, é utilizado o sistema
// de indexação do C, isto é, índice de 0 à (tamanho da lista-1)

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

No* inserirN(No* lst,int val,int n){
    
    No* no = (No*)malloc(sizeof(No));
    no->valor = val;
    if((n == 0) || (lst == NULL)){
        no->prox = lst;
        lst = no;        
    }else{
        No* aux = lst;
        int cont = 0;
        while(cont < (n-1) && aux->prox != NULL){
            cont++;
            aux = aux->prox;
        }
    no->prox = aux->prox;
    aux->prox = no;
    }
    
    return lst;
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

    lista = inserirInicio(lista,12);
    lista = inserirInicio(lista,30);
    lista = inserirN(lista,100,1);
    imprimirLista(lista);

    return 0;
}