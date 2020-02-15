#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int numero;
    struct no* prox;
}no;

no* criarLista(){
    return NULL;
}

no* inserirFim(no* lst,int val){
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->numero = val;
    novoNo->prox = NULL;
    no* aux = lst;
    if(aux == NULL){
        lst = novoNo;        
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;             
        }    
        aux->prox = novoNo;          
    }
    return lst;
}

no* excluirPorNumero(no* lst,int val){
    if(lst == NULL){
        return NULL;
    }else{
        while(lst->numero == val){        
            no* aux = lst;
            lst = lst->prox;
            free(aux);        
        }
        no* current = lst;
        while(current->prox != NULL){
            if(current->prox->numero == val){
                no* aux = current->prox;
                current->prox = current->prox->prox;
                free(aux);
            }else{
                current = current->prox;
            }
        }
    }









    
    
    
    
    
    
    
    
    
    
    no* aux2 =lst;
    if(aux2 == NULL){
        return NULL;
    }else{
        while(aux2 != NULL){
            if(aux2->numero == val){
                no* aux = aux2;
                aux2 = aux2->prox;
                free(aux);
                lst = aux2;
            }else{
                aux2 = aux2->prox;
            }    
        }
    }
    return lst;
}

void imprimirLista(no* lst){    
    
    int cont = 0;
    while( lst != NULL){
        cont++;
        printf("valor do elemento %d = %d\n",cont,lst->numero);
        lst = lst->prox;
    }
}

int main(){

    printf("\nLista Original:\n");
    no* lista = criarLista();
    lista = inserirFim(lista,10);
    lista = inserirFim(lista,9);
    lista = inserirFim(lista,0);
    lista = inserirFim(lista,4);
    imprimirLista(lista);
    printf("\nLista Alterada:\n");
    lista = excluirPorNumero(lista,9);
    imprimirLista(lista);
    return 0;
}