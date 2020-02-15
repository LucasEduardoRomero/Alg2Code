#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex3.c"
#define FLOR "Colaboradores.dat"
#define FLDEST "Colaboradores5000.dat"

int main(){    
    
    int res ;
    printf("***************INSERIR COLABORADORES************************************\n");
    if(registrarColaboradores(FLOR) == 1){
        printf("**Registro Finalizado**\n");
    }else{
        printf("Erro\n :(");        
        return 0;
    }
    printf("\n\n");
    if(listarColaboradores(FLOR) == 1){
        printf("**REGISTROS LISTADOS COM SUCESSO**\n");
    }else{
        printf("ERRO :/\n");
    }
    
    printf("\n********PESQUISADOR DE COLABORADORES*************\n");
    if(  filtrarPorSalario(5000,FLOR,FLDEST) == 1 ){
        printf("Lista filtrada com sucesso!\n");
    }else{
        printf("Algo inesperado aconteceu!\n");
    }
    listarColaboradores(FLDEST);
    return 0;
}