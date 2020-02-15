#include <stdio.h>
#include <string.h>

int x(int n,int m){
    if(n == m || m == 0){
        return 1;
    }else{
        return x(n-1,m) + x(n-1,m-1);
    }
}
int main(){

    int res,a,b;
    printf("Digite dois valores inteiros separados por espaco: ");
    scanf("%d %d",&a,&b);
    res = x(a,b);
    printf("Resultado = %d\n",res);
    return 0;   
}