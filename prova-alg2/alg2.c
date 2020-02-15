/*
    Input: 1234 +
    Operacao: (12 + 34)
    Output : 46
    Input 2222 *
    Operacao: (22*22)
    Output:484
    Input: 6969 %
    Operacao: nada
    Output: 6969
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int operar(int num,char operation){
    int res;
    if(strcmp(&operation,"%")==0){
                res=num;
    }else{

        char str_num[9];
        char str_num2[3];
        char expression[11];
        int j,tamanho,number1,number2;
        snprintf(expression, 10, "%d", num);
        tamanho = strlen(expression);
        j = tamanho - 2;    
        for(int cont=0;cont<2;cont++){
            str_num2[cont] = expression[j];
            j++;
        }
        strncpy(str_num,expression,tamanho-2);
        number1 = atoi(str_num);
        number2 = atoi(str_num2);

        if(strcmp(&operation,"*")==0){
            res=number1*number2;
        }else{
            if(strcmp(&operation,"+")==0){
                res=number1+number2;
            }else{  
                printf("Não foi identificada a operação");
                res=0;                          
            }
        } 
    }    
    return res;
}
int main(){
    
    int res,num;
    char op[2];

    printf("Digite um numero: ");
    scanf("%d",&num);
    printf("\nDigite a operacao: ");
    scanf("%s",&op[0]);
    res = operar(num,op[0]);
    printf("%d\n",res);
    return 0;
}