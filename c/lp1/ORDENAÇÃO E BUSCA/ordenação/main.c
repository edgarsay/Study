#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main(){

    int i;
    float vetor[5];
    printf("======================================================================\n");
    for(i = 0; i < 5; i++){//scanf
        scanf(" %f",&vetor[i]);
    }
    printf("======================================================================\n");

    bolha_gen(5,vetor,sizeof(float),compara);

    for(i = 0; i < 5; i++){//print
        printf("%.2f\n",vetor[i]);
    }
    return 0;
}