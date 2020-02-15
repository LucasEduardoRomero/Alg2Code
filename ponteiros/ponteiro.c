#include <stdio.h>

int main(){

    int x,y,*p;
    p=&y;
    y=0;
    x = *p;
    x =4 ;
    (*p)++;
    --x;
    (*p) +=x;
    printf("x = %d \ny = %d\np = %d\n",x,y,*p);
    return 0;
}