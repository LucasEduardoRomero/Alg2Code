#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;    
}No;

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

No* iniciarLista(){
    return NULL;
}

void imprimirLista(No* lst){
    int indice = 0;
    while(lst != NULL){
        indice++;
        printf("Elemento %d = %d\n",indice,lst->valor);
        lst = lst->prox;
    }
    printf("-----------\n\n\n");
}

No* ordenarLista(No* lst){
    if(lst != NULL && lst->prox != NULL){
        int flag = 1;

        while(flag){
            No* a = NULL;
            No* p = lst; 
            No* prox = p->prox;
            
            flag = 0;
            while(p->prox != NULL){            
                if(p->valor > prox->valor){
                    flag = 1;
                    p->prox = p->prox->prox;
                    if(a == NULL){
                        lst = prox;
                        prox->prox = p;
                    }else{
                        prox->prox = p;
                        a->prox = prox;
                    }
                    a = prox;
                    prox = p->prox;                                     
                }else{
                    a = p;
                    p = prox;
                    prox = prox->prox;  
                }                
            }
        }                      
    }
    return lst;   
}

int main(){

    No* lista = iniciarLista();
    lista = inserirFinal(lista, 2);
    lista = inserirFinal(lista, 3);
    lista = inserirFinal(lista, -2);
    lista = inserirFinal(lista, 1);
    lista = inserirFinal(lista, 0);
    imprimirLista(lista);    
    lista = ordenarLista(lista);
    imprimirLista(lista);
    return 0;
}
