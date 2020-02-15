#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 25;
    int *pa = &a;
    int b = *pa + a;
    printf("%d %ls %ls %d %d %ls \n\n", a,pa,&a,*pa,b,&b);

    

    return 0;
}