#include <stdio.h>
#include <string.h>

#define DIR "ex1.dat"

typedef struct Pessoa{
    char nome[100];
    char matricula[13];
} Pessoa;

int main(){

    FILE *file;
    file = fopen(DIR,"w");
    Pessoa cadastro;
    strcpy(cadastro.matricula,"");
    int flag = 1;
    
    do{
        printf("Digite o nome: ");
        scanf("%s",cadastro.nome);
        printf("Digite a matricula: ");
        strcpy(cadastro.matricula,"");
        scanf("%*1[\n]");
        scanf("%13[^\n]",cadastro.matricula);
        if( strlen(cadastro.matricula) != 0 ){
            
            fprintf(file,"%s ",cadastro.nome);
            fprintf(file,"%s\n",cadastro.matricula);

        }else{
            flag = 0;
        }

    }while( flag != 0 );
    fclose(file);
    return 0;
}