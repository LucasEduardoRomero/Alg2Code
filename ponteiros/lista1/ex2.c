#include <stdio.h>
#include <stdlib.h>

int main(){

    int i = 3,j = 5;
    int *p,*q;
    p = &i;
    q = &j;
    //first
    if(p == &i){
            printf("true\n");
    }    
    // second
    int val2 = *p - *q;
    printf("*p - *q = %d \n", val2);

    //third
    printf("**&p = %d\n",**&p);

    int val3 = 3* - *p/(*q)+7;
    printf("3* - *p/(*q)+7 = %d \n", val3);
    

    return 0;
}