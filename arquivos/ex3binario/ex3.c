typedef struct Colaborador{
    char nome[50];
    float salario;
} Colaborador;

#define TAM_REG_COLAB sizeof(Colaborador)

int quantRegistros(FILE *pf,int tr){
    fseek(pf,0,SEEK_END);    
    int iteracoes = ftell(pf)/tr;
    fseek(pf,0,SEEK_SET);
    return iteracoes;
}
int filtrarPorSalario(int valSalario,char arquivoOrigem[40],char arquivoDestino[40]){
    
    Colaborador colab;
    FILE *fileDest,*fileOr;
    fileOr = fopen(arquivoOrigem,"rb");
    fileDest = fopen(arquivoDestino,"wb");
    for(int i=0  ; i<quantRegistros(fileOr,TAM_REG_COLAB)  ; i++ ){
        fread(&colab,TAM_REG_COLAB,1,fileOr);
        if(colab.salario >= valSalario){
            fwrite(&colab,TAM_REG_COLAB,1,fileDest);
        }
    }
    fclose(fileDest);
    fclose(fileOr);
    return 1;   
}
int listarColaboradores(char nomeArquivo[40]){

    FILE *file;
    file = fopen(nomeArquivo,"rb");
    Colaborador colab;
    int cont = 0;
    if(file == NULL){
        return -1;
    }
    int iteracoes = quantRegistros(file,TAM_REG_COLAB);    
    while(iteracoes > cont){
        cont++;
        fread(&colab,TAM_REG_COLAB,1,file);
        printf("COLABORADOR %d\nNome: %s\nSalario: %.2lf\n\n",cont,colab.nome,colab.salario);
    }
    
    fclose(file);
    return 1;
}
void pedirInfo(char *nm,float *sal){
    char aux[20];
    printf("Digite o nome: ");  
    scanf("%s",nm);
    printf("Digite o salario: ");    
    scanf("%f",sal);      
}
int registrarColaboradores(char nomeArquivo[40]){

    FILE *file;
    Colaborador colab; 
    file = fopen(nomeArquivo,"wb");
    colab.salario = 0;   
    pedirInfo(colab.nome,&colab.salario);   
    while(colab.salario > 0){
        fwrite(&colab,TAM_REG_COLAB,1,file);
        colab.salario = 0; 
        pedirInfo(colab.nome,&colab.salario);  
       
    }   
    fclose(file);
    return 1;
}
