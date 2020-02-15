#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Colaborador{
    char nome[50];
    float salario;
} Colaborador;

#define DIR "arq2.dat"
#define TAM_ALUNO sizeof(Aluno)

void pedirInfo(char *nm,float *sal){
    char aux[20];
    printf("Digite o nome: ");  
    scanf("%s",nm);
    printf("Digite o salario: ");
    scanf("%f",sal);      
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
    Colaborador cadastro;
    // A entrada da matrícula deve ser caracter para 
    // Detectar a string nula
    char entrada_matricula[13]; 

 
    file = fopen(DIR,"wb");
    pedirInfo(cadastro.nome,cadastro.matricula);
    while( strcmp(cadastro.matricula,"") != 0 ){
        fwrite(&cadastro,TAM_ALUNO,1,file);
      //  printf("%s %s\n",cadastro.nome,cadastro.matricula);
      //  printf("tamanho cadastro. %s\ntamanho matricu");
        pedirInfo(cadastro.nome,cadastro.matricula);        
    }    
    fclose(file);

}
