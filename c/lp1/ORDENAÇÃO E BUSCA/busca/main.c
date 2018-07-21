#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main (){
    int n = 6;
    int v[n];
    int i = 0;
    for(i = 0;i < n;i++){
        scanf(" %d",&v[i]);
    }
    int elem = v[n-1];
    i = busca_linear_bin(n,v,elem);
    printf("elemento na posição %d : %d\n",i,v[i]);

}