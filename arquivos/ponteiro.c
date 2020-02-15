#include <stdio.h>

typedef struct TAluno {
    char Nome[30] ;
    int RGA;
    char Curso[50];
} TAluno;
//∗*
int main(){

    int *pNum;
    char *pNome;
    TAluno *pEst;
    int valor;
    valor = 45;
    pNum = &valor;
    valor = 30;
    printf("%d\n",*pNum);
}