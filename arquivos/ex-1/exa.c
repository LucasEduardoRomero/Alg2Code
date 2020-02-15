#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DIR "ex1.dat"

//      nome a ser pesquisadado | matricula a ser pesquisada
//                      \/             \/
bool incluirRegistro(char *nome,int matricula){
    
    char nm[100]; // var pra guardar nome atual do arquivo
    char mtr[13]; // var pra guardar matricula atual do arquivo
    FILE *cad;
    int aux;    
    
    int pontoDoNome;
    int flag = 0;
    cad = fopen(DIR,"r+");
    if(cad == NULL){
        return false;
    }
    printf("Nome Digitado = %s e Matricula Digitada = %d\n\n",nome,matricula);
    
    while(!(feof(cad))){
        //fscanf(cad,"%s %d",nm,&aux);
        pontoDoNome = ftell(cad); //guarda a posição do início do nome no arquivo
        fscanf(cad,"%s",nm);printf("%li ",ftell(cad));
        fscanf(cad,"%d",&aux);printf("%li ",ftell(cad));
       // sprintf(mtr,"%d",aux);
        printf("Nome Atual = %s e Matricula Atual = %d\n",nm,aux);
        //printf("%s\n",mtr);
        if( matricula == aux ){
            flag = 1;
            if( strcmp(nome,nm) == 0 ){
                return false;
            }else{
                int pontoDeRetorno;
                //TROCAR O NOME
                pontoDeRetorno = ftell(cad);
                fseek(cad,pontoDoNome,SEEK_SET);                
                if(pontoDoNome == 0){                    
                    fprintf(cad,"%s",nome);
                }else{
                    fprintf(cad,"\n%s",nome);
                }
                int lenNomeFuturo = strlen(nome);
                int lenNomeAtual = strlen(nm);
                int cont = 0;
                if( lenNomeFuturo < lenNomeAtual){
                   // printf("\n%d %d\n",lenNomeAtual,lenNomeFuturo);
                    while( (lenNomeAtual - lenNomeFuturo) > cont ){
                        fprintf(cad,"%s","?");
                        cont++;
                    }
                }                
                fseek(cad,pontoDeRetorno,SEEK_SET);
                // fprintf(cad,"%s",);
                // printf("%li",ftell(cad));            
            }
        }
    }
    if( flag == 0 ){
        //novo registro com matricula e nome
    }
}

struct Pessoa{
    char nome[100];
    int idade;
};

int main(){


    incluirRegistro("jose",20192);

    return 0;
}