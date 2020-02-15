#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    char matricula[13];
} Aluno;

#define DIR "ex1.dat"
#define TAM_ALUNO sizeof(Aluno)

void pedirInfo(char *nm,char *mtr){
    printf("Digite o nome: ");
    scanf("%s",nm);
    printf("Digite a matricula: ");
    strcpy(mtr,"");
    scanf("%*1[\n]");
    scanf("%13[^\n]",mtr);
}
int quantRegistros(FILE *pf,int tr){
    fseek(pf,0,SEEK_END);    
    int iteracoes = ftell(pf)/tr;
    fseek(pf,0,SEEK_SET);
    return iteracoes;
}
int listarAlunos(){

    FILE *file;
    file = fopen(DIR,"rb");
    Aluno aluno;
    int cont = 0;
    if(file == NULL){
        printf("ERRO");
        return -1;
    }
    int iteracoes = quantRegistros(file,TAM_ALUNO);    
    while(iteracoes > cont){
        cont++;
        fread(&aluno,TAM_ALUNO,1,file);
    }
    
    fclose(file);
}

int registrarAlunos(){
    printf("**** Registrando Novos Alunos ****\n\n");
    //******************************************//
    //**** Criando novo registro *****************//
    //******************************************//
    FILE *file;
    Aluno cadastro;
    // A entrada da matrícula deve ser caracter para 
    // Detectar a string nula
    char entrada_matricula[13]; 

 
    file = fopen(DIR,"wb");
    pedirInfo(cadastro.nome,cadastro.matricula);
    while( strcmp(cadastro.matricula,"") != 0 ){
        fwrite(&cadastro,TAM_ALUNO,1,file);
        printf("%s %s\n",cadastro.nome,cadastro.matricula);
      //  printf("tamanho cadastro. %s\ntamanho matricu");
        pedirInfo(cadastro.nome,cadastro.matricula);        
    }    
    fclose(file);

}

int main(){
    
    registrarAlunos();
    listarAlunos();
    
    //*******************************************//
    return 0;
}