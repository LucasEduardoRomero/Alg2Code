#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct No{
	int valor;
	struct No* prox;
}No;

No* iniciarLista(){
	return NULL;
}

No* inserirFinal(No* lst,int val){
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


void imprimirLista(No* lst){
	int cont = 0;
	while(lst != NULL){
		cont++;
		printf("No %d = %d\n",cont,lst->valor);
		lst = lst->prox;
	}
	printf("-------\n");
}
 
void separarLista(No* lst,No** impar,No** par){
	
	if(lst != NULL){
		bool flagi = true;
		bool flagp = true;	
		No* i = (No*)malloc(sizeof(No));
		No* p = (No*)malloc(sizeof(No));	
		while(lst != NULL){
			if(!((lst->valor % 2) == 0)){				
				if(flagi){
					*impar = i;
					flagi = false;	
					i->valor = lst->valor;							
				}else{
					i->prox = (No*)malloc(sizeof(No));
					i = i->prox;
					i->valor=lst->valor;	

				}
				
			}else{	
				if(flagp){
					*impar = p;
					flagp = false;	
					p->valor = lst->valor;							
				}else{
					p->prox = (No*)malloc(sizeof(No));
					p = p->prox;
					p->valor=lst->valor;	

				}
			}
			lst= lst->prox;
		}

	}
}

int main(){

	No* impar = iniciarLista();
	No* par = iniciarLista();
	No* lista = iniciarLista();

	lista = inserirFinal(lista, 1);
	lista = inserirFinal(lista, 2);
	lista = inserirFinal(lista, 3);
	lista = inserirFinal(lista, 4);
	lista = inserirFinal(lista, 5);
	lista = inserirFinal(lista, 6);

	 
	separarLista(lista,&impar,&par);

	imprimirLista(impar);
	imprimirLista(par);

	return 0;
}
