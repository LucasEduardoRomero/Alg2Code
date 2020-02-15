#include <stdio.h>
#include <string.h>


char reverso(char string[50],char *destino){
    char string_atual[50];
    if(strlen(string) == 1){
        return string;
    }else{
        for(int i=1;i<strlen(string);i++){
            string_atual[i-1] = string[i];
        }      
        char res[50];
        strcat(res,string_atual);
        strcat(res,)  
        return reverso(string_atual)
    }
}

int main(){


    return 0;
}