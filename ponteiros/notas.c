#include <stdio.h>
#include <stdlib.h>

int main(){

    int quant;
    float *p,media; 

    printf("Digite a quantia de notas: ");
    scanf("%d",&quant);   

    if(quant <= 0){
        printf("you cego man??\n");
    }else{
        media = 0;
        p = (float*)malloc(sizeof(float)*quant); 
        for(int i=0;i<quant;i++){
            printf("Digite a nota: ");
            scanf("%f",&p[i]);
            media = media + p[i];            
        }
        media = media/quant;
        for(int i =0;i<quant;i++){
            printf("nota %d = %.2f\n" ,++i,p[i]);  
            --i;
        }
        printf("media = %.2f\n",media);
        free(p);
    }

    return 0;
}