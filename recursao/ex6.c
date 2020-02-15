#include <stdio.h>

double s(double n,double d){

    if(d == 39 && n == 20){
        return 20/39;
    }else{
        return (n/d) + s(n+1,d+2);
    }

}
int main(){

    int num,den;
    double res;
    printf("Digite o numerador inicial: ");
    scanf("%d",&num);
    res = s((double)num,(double)num);
    printf("s = %lf\n",res);
    
    

    return 0;
}