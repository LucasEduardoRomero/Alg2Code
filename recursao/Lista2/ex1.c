#include <stdio.h>
#include <string.h>

char calcular(string word){
    n=strlen(word);
    permutar(word,n-1);
}
void permutar(char fixo,char palavra){

    int n,i;
    n=strlen(palavra);
    if(n > 1){
        for(i=0;i<n;i++){
            char aux[strlen(palavra)-1];            
            permutar(fixo+strncpy(i,palavra,1),strncpy());
        }
    }
}
int main(){

    char string[50];
    printf("Digite a string: ");
    scanf("%s",string);
   
    calcular(string);



    return 0;
}