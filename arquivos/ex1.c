#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DIR "ex1.dat"
// ROUBADO DO EXA.C
//***************************************************
//**************** Lista os Alunos ******************
//***************************************************
int listarAlunos(){

    FILE *file;
    file = fopen(DIR,"rb");
    Aluno aluno;
    int cont = 0;
    if(file == NULL){
        printf("test");
        return -1;
    }
    while(!(feof(file))){
        cont++;
        fread(&aluno,TAM_ALUNO,1,file);
        printf("ALUNO %d:\nNome-%s\nMatricula-%d\n\n",cont,aluno.nome,aluno.matricula);
    }
}


bool incluirRegistro(char *nm,char *mtr){
    
    char name[100];
    char matri[100];
    int cont;
    FILE *cad;
    cad = fopen(DIR,"r+");
    if(cad == NULL){
        return false;
    }
    while(!(feof(cad))){
        fscanf(cad,"%s",name);
        fscanf(cad,"%s",matri);
        if( strcmp(mtr,matri) == 0){
            if( !(strcmp(name,nm)) == 0){
                fprintf(cad,"%s",)
            }
        }
    }

int main(){

    FILE *cadastro;
    char matricula[13];
    char nome[50];
    char str[200];

    cadastro = fopen(DIR,"w");
    
    printf("Digite o nome: ");
    scanf("%s",nome);    
    printf("Digite a matricula: ");
    //strcpy(matricula,"");
    scanf("%*1[\n]");
    scanf("%13[^\n]",matricula);
    while( strcmp(matricula,"") != 0 ){
        fprintf(cadastro,"%s ",nome);
        fprintf(cadastro,"%s\n",matricula);
        printf("Digite o nome: ");
        scanf("%s",nome);    
        printf("Digite a matricula: ");
        strcpy(matricula,"");
        scanf("%*1[\n]");
        scanf("%13[^\n]",matricula);
    }
    fclose(cadastro);

    //-----------------

  //  incluirRegistro("Romerada","201911310029");

    return 0;
}