#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hsh.h"

int main (){

  Hash tab;//I ISSO?

  int mat;
  char nome[81];
  char turma;
  float n[4];
  int controlador;

  //lendo arquivo
  printf("ESCREVA O NOME DO ARQUIVO:\n");
  char arquivo[100];
  scanf(" %256[^\n]",arquivo);
  FILE* file = fopen(arquivo,"rt");
  if(file == NULL){
    printf("ARQUIVO NÃO ENCONTRADO\n");
    exit(0);
  }
  char linha[150];
  while (fgets(linha,150,file) != NULL) {
    int x = sscanf(linha," %s",nome);
    strcpy(nome,linha);
    if(x > 0){
      fgets(linha,150,file);
      sscanf(linha," %d %c %f %f %f %f",&mat,&turma,&n[0],&n[1],&n[2],&n[3]);
      hsh_insere(tab,mat,nome,n,turma);
    }
  }

  while(1){
    printf("DIGITE 0 : SAIR\n");
    printf("DIGITE 1 : buscar\n");
    printf("DIGITE 2 : inserir\n");
    printf("DIGITE 3 : modificar\n");
    printf("DIGITE 4 : excluir\n");
    scanf(" %d",&controlador);
    if(controlador == 0){
      exit(0);
    }else if(controlador == 1){
      printf("MATRICULA\n");
      scanf(" %d",&mat);
      hsh_busca(tab,mat);
    }else if(controlador == 2){
      printf("MATRICULA:\n");
      scanf(" %d",&mat);
      printf("NOME:\n");
      scanf(" %256[^\n]",nome);
      printf("TURMA:\n");
      scanf(" %c",&turma);
      printf("N1:\n");
      scanf(" %f",&n[0]);
      printf("N2:\n");
      scanf(" %f",&n[1]);
      printf("N3:\n");
      scanf(" %f",&n[2]);
      printf("N4:\n");
      scanf(" %f",&n[3]);

      hsh_insere(tab,mat,nome,n,turma);
    }else if(controlador == 3){
      printf("MATRICULA\n");
      scanf(" %d",&mat);
      hsh_modificar(tab,mat);
    }else if(controlador == 4){
      printf("MATRICULA\n");
      scanf(" %d",&mat);
      hsh_excluir(tab,mat);
    }else{
      printf("\nOPÇÃO INVALIDA! tente novamente...\n\n");
    }
  }

  return 0;
}
