#include <stdio.h>

int mdc(int n,int m){

        if(n > m){
            mdc(m,n);
        }else{
            if( n== 0){
                return m;
            }else{
                if(n > 0 && n <= m){
                    return mdc(n,m%n);
                }
            }
        }

}

int main(){

    int num_n,num_m,res;
    printf("Digite um numero: ");
    scanf("%d",&num_n);
    printf("Digite outro numero: ");
    scanf("%d",&num_m);
    res=mdc(num_n,num_m);
    printf("MDC entre %d e %d = %d\n",num_n,num_m,res);
    
    

    return 0;
}