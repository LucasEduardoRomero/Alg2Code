#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int valor;
    struct No* prox;
} No;

No* iniciarListar(){
    return NULL;
}

No* inserirFinal(No* lst,int val){
    No* no = (No*)malloc(sizeof(No*));
    no->prox = NULL;
    no->valor = val;    
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


bool removerNoIntervalo(No* lst, int a, int b){
    bool resp = false;
    if(lst != NULL){
        No* aux = lst;
        No* pa, *pb;
        while(aux->prox != NULL && aux->valor != a){
            aux = aux->prox;
        }
        if(aux->valor == a){
            pa = aux;            
            while(aux->prox != NULL && aux->valor != b){                
                aux = aux->prox;
            }
            if(aux->valor == b){
                pb = aux;
                aux = pa->prox;
                No* temp;
                while(aux->valor != b){
                    temp = aux;
                    aux = aux->prox;
                    free(temp);
                    resp = true;
                } 
                pa->prox = pb;               
            }
        }
    }
    return resp;
}

void imprimirLista(No* lst){
    int cont = 0;
    while(lst != NULL){
        cont++;
        printf("No %d = %d\n",cont,lst->valor);
        lst = lst->prox;
    }
    printf("--------------\n");
}


int main(){

    No* lista = iniciarListar();
    lista = inserirFinal(lista,3);
    lista = inserirFinal(lista,0);
    lista = inserirFinal(lista,10);
    lista = inserirFinal(lista,191);
    lista = inserirFinal(lista,1);
    lista = inserirFinal(lista,1);
    imprimirLista(lista);

    removerNoIntervalo(lista,3,1);
    imprimirLista(lista);
    

    return 0;
}