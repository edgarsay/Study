#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int busca_linear(int n, int *v,int elem){ // O(n)
    int i = 0;
    for(i = 0;i < n;i++){// olha elemento por elemento
        if(elem == v[i]){
            return i;// encontrou
        }
    }
    return -1;// não encontrou
}

int busca_linear_ord(int n, int *v, int elem){ // O(n)
    int i = 0;
    for(i = 0;i <n;i++){// olhando elemento por elemento
        if(elem == v[i]){
            return i;   // 
        }else if(elem < v[i]){
            return -1;
        }
    }

    return -1;
}

int busca_linear_bin(int n,int *v,int elem){ 
    // O(n/(2^n) or log de n na base 2)
    int ini = 0,fim = n-1,meio;

    while(ini <= fim){
        meio = (ini+fim)/2;
        if(elem < v[meio]){
            fim = meio-1;
        }else if(elem > v[meio]){
            ini = meio+1;
        }else{
            return meio;
        }
    }
}