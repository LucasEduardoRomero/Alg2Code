#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decToOctal(int inteiro,char* strDestino){
    char aux[12];
    if( inteiro < 8){
        sprintf(strDestino,"%d",inteiro);        
        return;
    }else{
        decToOctal((inteiro/8),strDestino);        
        sprintf(aux,"%d",(inteiro%8));
        strcat(strDestino,aux);
        return;
    }
    return;
}

int main(){
    
    char res[13];
    int n;
    printf("Digite um inteiro na base decimal: ");
    scanf("%d",&n);
    decToOctal(n,res);
    printf("%d na base decimal = %s na base octal\n",n,res);
    return 0;
}