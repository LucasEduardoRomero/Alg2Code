#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct No{
	float valor;
	struct No* prox;
}No;

No* iniciarLista(){
	return NULL;
}

No* inserirFinal(No* lst,float val){
	No* no =(No*)malloc(sizeof(No));
	no->valor = val;
	no->prox = NULL;

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

//FUNCAO REQUISITADA NO EXERCICIO
int inserirOrdenado(No* lst, float val){
	if(lst == NULL){
		No* no =(No*)malloc(sizeof(No));
		no->prox = NULL;
		no->valor = val;
		lst = no;
		return 1;
	}else{
		if(lst->valor == val){
			return (0);
		}else{
			if(lst->valor > val){
				No* no =(No*)malloc(sizeof(No));
				no->prox = lst->prox;
				no->valor = lst->valor;
				lst->valor = val;
				lst->prox = no;
				return 1;
			}else{
				return 1 + inserirOrdenado(lst->prox,val);
			}
		}
	}
}


void imprimirLista(No* lst){
	int cont = 0;
	while(lst != NULL){
		cont++;
		printf("No %d = %.2f\n",cont,lst->valor);
		lst = lst->prox;
	}
	printf("-------\n");
}
 
int main(){

	No* lista = iniciarLista();
	lista = inserirFinal(lista, 2);
	lista = inserirFinal(lista, 2);
	lista = inserirFinal(lista, 2);
	lista = inserirFinal(lista, 2);

	int i = inserirOrdenado(lista,10);
	if(i == 0){
		printf("inserção falhou!\n");
	}else{
		printf("posição da inserção = %d\n",i);
	}
	return 0;
}
