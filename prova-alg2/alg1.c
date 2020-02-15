/*
    Criar uma função que inverta o número da entrada
    Input: 12345
    Output: 54321    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int inverte(int num){

    int number_inverted;
    char inverted[51];
    char str_num[51];
    snprintf(str_num, 50, "%d", num);
    int tamanho = strlen(str_num);
    int j = tamanho-1;
    for(int i=0;i<tamanho;i++){
        inverted[j] = str_num[i];
        j--;
    }
    //printf("%s",inverted);
    number_inverted = atoi(inverted);
    return number_inverted;
}
int main(){
    int x,num;
    printf("Digite um número: ");
    scanf("%d",&num);
    x = inverte(num);  
    printf("Número invertido: %d\n",x);     
    return 0;
}