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
bool isEqual(No* lst1, No* lst2){	
	if(lst1 == NULL){
		if(lst2 == NULL){
			return true;
		}else{
			return false;
		}		
	}else{
		if(lst2 == NULL){
			return false;
		}else{
			if((strcmp(lst1->texto,lst2->texto) == 0)){
				return isEqual(lst1->prox,lst2->prox);
			}else{
				return false;
			}				
		}

	}
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
	No* lista1 = iniciarLista();
	No* lista2 = iniciarLista();

	lista1 = inserirFinal(lista1, "TESTE" );
	lista1 = inserirFinal(lista1, "" );
	lista1 = inserirFinal(lista1, "TESTE" );
	lista1 = inserirFinal(lista1, "" );

	lista2 = inserirFinal(lista2, "TESTE" );
	lista2 = inserirFinal(lista2, "" );
	lista2 = inserirFinal(lista2, "TESTE" );
	lista2 = inserirFinal(lista2, "" );

	if(isEqual(lista1,lista2)){
		printf("igual!\n");
	}else{
		printf("diferente\n");
	}
	return 0;
}
