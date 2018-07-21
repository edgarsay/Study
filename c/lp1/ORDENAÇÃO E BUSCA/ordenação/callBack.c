#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int gen(int a, int b, int(*func)(int, int)){
    return func(a,b);
}

int main (){
    int a = 2, b = 1;
    printf("soma: %d\n",gen(a,b,soma));
    printf("sub: %d\n",gen(a,b,sub));

}