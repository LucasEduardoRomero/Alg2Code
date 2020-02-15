#include <stdio.h>
#include <string.h>
//#include <stdbool.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    char matricula[13];
} Aluno;

#define ARQ1 "arq1.dat"
#define ARQ2 "arq2.dat"
#define ARQ_FINAL "dados.dat"
#define TAM_ALUNO sizeof(Aluno)

int quantRegistros(FILE *pf,int tr){
    fseek(pf,0,SEEK_END);    
    int iteracoes = ftell(pf)/tr;
    fseek(pf,0,SEEK_SET);
    return iteracoes;
}

int exportarArquivos(char *dir_fonte,char *dir_final,char modo[4]){

    Aluno aluno;
    FILE *fileFinal;
    fileFinal = fopen(dir_final,modo);
    FILE *fileFonte;
    fileFonte = fopen(dir_fonte,"rb");
    if((fileFinal == NULL) || (fileFonte == NULL)){        
        fclose(fileFinal);
        fclose(fileFonte);
        return -1;
    }
    int iteracoes = quantRegistros(fileFonte,TAM_ALUNO);
    int cont = 0;
    while( cont < iteracoes){        
        fread(&aluno,TAM_ALUNO,1,fileFonte);
        fwrite(&aluno,TAM_ALUNO,1,fileFinal);
        cont++;        
    }
    fclose(fileFinal);
    fclose(fileFonte);
}

int main(){
    if( exportarArquivos(ARQ1,ARQ_FINAL,"wb") == -1 ||  exportarArquivos(ARQ2,ARQ_FINAL,"ab") == -1 ){
        printf("erro\n");
    }     
    return 0;
}