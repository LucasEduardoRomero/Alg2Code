#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    char matricula[13];
} Aluno;

#define DIR "ex1.dat"
#define TAM_ALUNO sizeof(Aluno)

int quantRegistros(FILE *pf,int tr){
    fseek(pf,0,SEEK_END);    
    int iteracoes = ftell(pf)/tr;
    fseek(pf,0,SEEK_SET);
    return iteracoes;
}
bool incluirAluno(char n[50],char m[13]){
    //--VAR--
    long int posAlunoAtual;
    long int posPosterior;
    FILE *file;
    Aluno alunoAtual;
    int interacoes,cont;
    
    //--COMAND--
    file = fopen(DIR,"r+b");
    if( file == NULL ){
        return false;
    }
    interacoes = quantRegistros(file,TAM_ALUNO);
    while(interacoes > cont){
        cont++;
        posAlunoAtual = ftell(file); 
        printf("%li",posAlunoAtual);     
        fread(&alunoAtual,TAM_ALUNO,1,file);        
        posPosterior = ftell(file);
        if( strcmp(m,alunoAtual.matricula) == 0){
            if( strcmp(n,alunoAtual.nome) == 0 ){
                //Nome e matricula são iguais portanto o novo
                //aluno não deve ser registrado.
                fclose(file);
                return false;
            }else{
                //matricula igual mas nome diferente, logo
                // substituir o nome no registro 
                strcpy(alunoAtual.nome,n);
                fseek(file,posAlunoAtual,SEEK_SET);
                printf("\n%li ponteiro na substituicao\n",ftell(file));
                fwrite(&alunoAtual,TAM_ALUNO,1,file);
                fseek(file,posPosterior,SEEK_SET);  
                fclose(file);
                return true;                                        
            }
        }  
    }
    strcpy(alunoAtual.nome,n);
    strcpy(alunoAtual.matricula,m);
    fseek(file,0,SEEK_END);
    fwrite(&alunoAtual,TAM_ALUNO,1,file);
    fclose(file);
    return true;  

}
//***************************************************
//**************** Lista os Alunos ******************
//***************************************************
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
        printf("********* Aluno %d *********\n",cont);
        printf("* %s        *       %s\n",aluno.nome,aluno.matricula);
        printf("****************************\n");
    
    }    
    fclose(file);
}

int main(){

    bool stats;
    char nome[50];
    char matri[13];
    printf("Digite o nome a ser pesquisado: ");
    scanf("%s",nome);
    printf("Digite a matricula a ser pesquisada: ");
    scanf("%s",matri);
    stats = incluirAluno(nome,matri);
    if(stats){
        printf("\nINCLUSAO CONCLUIDA COM SUCESSO.\n");
    }else{
        printf("\nINCLUSAO FALHOU.\n");
    }
    listarAlunos();
    return 0;
}