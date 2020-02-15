#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    char matricula[13];
} Aluno;

#define TAM_ALUNO sizeof(Aluno)
#define DIR "arq2.dat"

int quantRegistros(FILE *pf,int tr){
    fseek(pf,0,SEEK_END);    
    int iteracoes = ftell(pf)/tr;
    fseek(pf,0,SEEK_SET);
    return iteracoes;
}
int listarAlunos(char *dir){

    FILE *file;
    file = fopen(dir,"rb");
    Aluno aluno;
    int cont = 0;
    if(file == NULL){
        printf("test");
        return -1;
    }
    int iteracoes = quantRegistros(file,TAM_ALUNO);
    while(cont < iteracoes){
        cont++;
        fread(&aluno,TAM_ALUNO,1,file);
        printf("ALUNO %d:\nNome-%s\nMatricula-%s\n\n",cont,aluno.nome,aluno.matricula);
    
    }
    
}
int main(){
    listarAlunos(DIR);
    return 0;
}