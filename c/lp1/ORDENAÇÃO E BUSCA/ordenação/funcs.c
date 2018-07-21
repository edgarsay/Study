#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

//bolha =====================================================================
void bolha(int n,int *v){// n == tamanho do vetor, v = vetor
    int i,j;
    troca = 0; // verifica se o vetor está ou não organizado
    for(i = n-1;i >= 1 && x;i--){
        x = 0;
        for(j=0;j<i;j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j]=v[j+1];
                v[j+1] = temp;
                x = 1;
            }
        }
    }
}

//bolha com recursão ================================================================
void bolhaR(int n, int *v){
    int j;
    int troca = 0;
    for(j=0;j<n-1;j++){
        if(v[j]>v[j+1]){
            int temp = v[j];
            v[j+1] = temp;
            troca = 1;
        }
        if(troca!=0)
            bolhaR(n-1,v);
    }
}

//bolha generica ====================================================================
void bolha_gen(int n,void *v, int tam, int(*cmp)(void*,void*)){
    int i,j;
    for(i = n-1;i>0;i--){
        int troca_ = 0;
        for(j=0;j<i;j++){
            void *p1 = acessa(v,j,tam);
            void *p2 = acessa(v,j+1,tam);
            if(cmp(p1,p2)>0){
                troca(p1,p2,tam);
                troca_ = 1;
            }
        }
        if(troca_ == 0){
            return;
        }
    }
}

//acessa um item de um vetor generico =====================================================================
void *acessa(void *v, int i, int tam){// o void!*!acessa retorna um tipo generico
                        //int tam = sizeof(tamanho que voce quer)
    char* t = (char*)v; // é o minimo possivel
    t = t + i*tam;
    return (void*)t;
}

//diz se é ou não necessario trocar dois elementos inteiros
int compara(void * a, void *b){
    float *p1 = (float *)a;
    float *p2 = (float *)b;
    if((*p1)>(*p2))
        return 1;
    else
        return 0;
}

//troca dois elementos em um vetor generico
void troca (void *a, void *b, int tam){
    char *p1 = (char*)a;
    char *p2 = (char*)b;
    for(int i = 0; i < tam; i++){
        char aux = p1[i];
        p1[i] = p2[i];
        p2[i] = aux; 
    }
}