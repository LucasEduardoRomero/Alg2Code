#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No{
	char texto;
	struct No* prox;
}No;

No* iniciarLista(){
	return NULL;
}

No* inserirFinal(No* lst,char text){
	No* no =(No*)malloc(sizeof(No));
	no->texto = text;
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

// FUNCAO REQUISITADA
No* reverterLista(No* lst){
	if(lst != NULL){
		if(lst->prox == NULL){
			return lst;
		}
		bool first = true;
		No* inverso = iniciarLista();
		No* aux = lst;
		No* pinverso;
		No* last = NULL;
		while(last != lst){
			aux = lst;
			while(aux->prox != last){
				aux = aux->prox;
			}
			
			last = aux;			

			if(first){
				inverso = (No*)malloc(sizeof(No));
				inverso->texto = aux->texto;		
				inverso->prox = (No*)malloc(sizeof(No));
				pinverso = inverso->prox;								
				first = false;				
			}else{
				pinverso->texto = aux->texto;
				if(last != lst){
					pinverso->prox = (No*)malloc(sizeof(No));
					pinverso = pinverso->prox;
				}		
			}

		}
		return inverso;
	}else{
		return NULL;
	}	
}

void imprimirLista(No* lst){
	int cont = 0;
	while(lst != NULL){
		cont++;
		printf("No %d = %c\n",cont,lst->texto);
		lst = lst->prox;
	}
	printf("-------\n");
}

int main(){

	No* lista = iniciarLista();
	lista = inserirFinal(lista,'x');
	lista = inserirFinal(lista,'y');
	lista = inserirFinal(lista,'w');
	lista = inserirFinal(lista,'z');
	No* invertida = reverterLista(lista);
	imprimirLista(invertida);
	return 0;
}
