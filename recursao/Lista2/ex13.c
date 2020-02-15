#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
a37e = 41854
a59c = 42396
*/

int transformLetter(char letter){
    int asc_number = (int)letter;
    if(asc_number >=65 && asc_number <=70){
        return asc_number-55;
    }else{
        if(asc_number >=48 && asc_number <= 57){
            return asc_number-48;
        }else{
            if(asc_number >=97 && asc_number <=102 ){
                return asc_number-87;
            }else{
                return -999999;
            }
        }
    }
}
   /* if(asc_number == 65){
        return 10;
    }else{
        if(asc_number == 66){
            return 11;
        }else{
            if(asc_number == 67){
                return 12;
            }else{
                if(asc_number == 68){
                    return 13;
                }else{
                    if(asc_number == 69){
                        return 14;
                    }else{
                        if(asc_number == 70){
                            return 15;
                        }else{
                            if(asc_number == 48){
                                return 0;
                            }else{
                                if(asc_number == 49){
                                    return 1;
                                }else{
                                    if(asc_number == 50){
                                        return 2;
                                    }else{
                                        if(asc_number == 51){
                                            return 3;
                                        }else{
                                            if(asc_number== 52){
                                                return 4;                                                
                                            }else{
                                                if(asc_number==53){
                                                    return 5;
                                                }else{
                                                    if(asc_number == 54){
                                                        return 6;
                                                    }else{
                                                        if(asc_number == 55){
                                                            return 7;
                                                        }else{
                                                            if(asc_number == 56){
                                                                return 8;
                                                            }else{
                                                                if(asc_number == 57){
                                                                    return 9;
                                                                }else{
                                                                    return -999999;
                                                                }
                                                            }
                                                        }
                                                    }                                                    
                                                }
                                            }
                                        }
                                    }
                                }
                            }                   
                        }                    
                    }                    
                }
            }                   
        }
    }
}
*/

int po(int base,int exp){
    int pot = 1;
    for(int i = 0; i < exp;i++){
        pot = pot*base;
    }
    return pot;
}

int hexToDec(char* string,int i,int n){    
    if( n == i){       
        return transformLetter(string[n]);
    }else{
        return ( (transformLetter(string[n])*po(16,(i-n))) + hexToDec(string,i,n+1));
    }
}

int main(){
    int res;
    char hexa[20];
    printf("Digite o numero em hexadecimal: ");
    scanf("%s",hexa);
    res = hexToDec(hexa,(strlen(hexa)-1),0);    
    printf("Conversao de %s para Base Decimal = %d\n",hexa,res);
    return 0;   
}
