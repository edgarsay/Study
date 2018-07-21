#include <stdio.h>

int QTD_caracter(char * nome){

    int i = 0;
    while(nome[i] != '\0'){
        i++;
    }

    return i ;
}

void imprime(char *e){
    int i;
    int tamanho = QTD_caracter(e);
    for(i = 0;i < tamanho;i++){
        printf("%c",e[i]);
    }
    printf("\n");
}


int main (){

char e[] = "VAI DA BOM";
imprime(e);
int tamanho = QTD_caracter(e);
printf("Tem %d caracteres!\n",tamanho);


    return 0;
}
