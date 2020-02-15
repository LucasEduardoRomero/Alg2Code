#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int numero;
    struct no* prox;
} no;

no* criarLista(){
    return NULL;
}

no* inserirInicio(no* lst,int val){
    no* first = (no*) malloc(sizeof(no));
    first->numero = val;
    first->prox = lst; 
    return first;
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

void imprimirLista(no* lst){    
    
    int cont = 0;
    while( lst != NULL){
        cont++;
        printf("valor do elemento %d = %d\n",cont,lst->numero);
        lst = lst->prox;
    }

}

int main(){

    no* lista = criarLista();
    lista = inserirInicio(lista,0);
    lista = inserirInicio(lista,1);
    lista = inserirFim(lista,2);
    lista = inserirFim(lista,1000);  
    imprimirLista(lista); 

    return 0;
}