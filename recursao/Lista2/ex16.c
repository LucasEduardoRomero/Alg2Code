#include <stdio.h>
#include <string.h>
// 25 CHAMADAS PARA X(6)
int x(int n){
    if ((n >= 0) && (n <= 2)){
        return n;
    }else{
        return x(n-1) + x(n-2) + x(n-3);
    } 
}

int main(){

    int res,n;
    printf("Digite um inteiro N: ");
    scanf("%d",&n);
    res = x(n);
    printf("X(%d) = %d\n",n,res); 
    return 0;
}