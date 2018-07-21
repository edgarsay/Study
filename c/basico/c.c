#include <stdio.h>

 int main() {
   int c;
   int nlinhas = 0;
   FILE * fp = fopen("entrada.txt","wt");
   if(fp == NULL){
     printf("DEU MERDA!");
     return (1);
   }


   while((c = fgetc(fp)) != EOF){// int fgetc(FILE *) = VAI PEGANDO TODOS OS CARACTES DO ARQUIVO E TRAZ COMO INTEIRO ; EOF = END OF FILE
     if(c == '\n'){
       nlinhas++;
     }
   }
   fclose(fp);
   printf("O NÚMERO DE LINHAS É :%d\n",nlinhas);
  return 0;
}
