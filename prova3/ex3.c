#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No{
	char texto[20];
	struct No* prox;
}No;

No* iniciarLista(){
	return NULL;
}

No* inserirFinal(No* lst,char text[20]){
	No* no =(No*)malloc(sizeof(No));
	strcpy(no->texto,text);
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

// FUNCAO REQUISITADA NO EXERCICIO
bool removerNo(int p,No** pont){
	No* lst = *pont;
	if(lst != NULL && p > 0){		
		if(p == 1){
			No* aux = lst;
			*pont = lst->prox;
			free(aux);
			return true;
		}else{
			int i =2;
			while(i < p && lst != NULL){
				lst = lst->prox;
				i++;
			}
			if( lst != 	NULL){				
				No* aux = lst->prox;
				lst->prox = aux->prox;
				free(aux);
				return true;				
			}
		}
	}
	return false;
}

void imprimirLista(No* lst){
	int cont = 0;
	while(lst != NULL){
		cont++;
		printf("No %d = %s\n",cont,lst->texto);
		lst = lst->prox;
	}
	printf("-------\n");
}
 
int main(){
	No* lista = iniciarLista();
	lista = inserirFinal(lista, "eu" );
	lista = inserirFinal(lista, "amo" );
	lista = inserirFinal(lista, "algoritmos" );
	lista = inserirFinal(lista, "<3" );
	imprimirLista(lista);
	int p = 3;
	
	if(removerNo(p,&lista)){
		printf("Remoção do Nó %d conlcuída\n",p);
	}else{
		printf("Remoção falhou\n");
	}

	imprimirLista(lista);



	return 0;
}
