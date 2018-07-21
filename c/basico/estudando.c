#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int existe(FILE*file,int mat){

  char linha [150];

  int matricula2;
  char nome[50];
  char classe;
  float n1,n2,n3,n4;
  int cont = 0;
  while (fgets(linha,150,file) != NULL) {
    cont++;
    int n = sscanf(linha," %s",nome);
    if(n > 0){
      fgets(linha,150,file);
      cont++;
      sscanf(linha," %i %c %f %f %f %f",&matricula2,&classe,&n1,&n2,&n3,&n4);
          if (mat == matricula2) {
            return cont;
          }
    }
  }
  if(fgets(linha,150,file) == NULL){
    return 0;
  }
//existe();
}

void modificar (FILE*file){
  printf("MATRICULA:\n");
  int mat = 0;
  scanf(" %d",&mat);
  int vali = existe(file,mat);

  if(vali != 0){
    fopen("teste.txt","wt");
    char linha[150];
    int i;
    for(i = 0;i<vali;i++){
      fgets(linha,150,file);
    }

    char nome[82];

    int mat;
    char turma;
    float n1;
    float n2;
    float n3;
    float n4;
      printf("NOME DO ALUNO:\n");
      scanf(" %s",nome);
      printf("TURMA DO ALUNO:\n");
      scanf(" %c",&turma);
      printf("N1 DO ALUNO:\n");
      scanf(" %f",&n1);
      printf("N2 DO ALUNO:\n");
      scanf(" %f",&n2);
      printf("N3 DO ALUNO:\n");
      scanf(" %f",&n3);
      printf("N4 DO ALUNO:\n");
      scanf(" %f",&n4);

      fputs(nome,file);
      char buffer [150];
      sprintf (buffer,"\n%d %c %.2f %.2f %.2f %.2f\n\n",mat,turma,n1,n2,n3,n4);
      fputs(buffer,file);

      fclose(file);

  }else{
    printf("MATRICULA NÃO CADASTRADA\n");
  }
}


void buscar (FILE* file){
  char linha [150];

  int matricula1;
  printf("MATRICULA: ");
  scanf (" %i", &matricula1);

  int matricula2;
  char nome[50];
  char classe;
  float n1,n2,n3,n4;

  while (fgets(linha,150,file) != NULL) {
    int n = sscanf(linha," %s",nome);
    if(n > 0){
      fgets(linha,150,file);
      sscanf(linha," %i %c %f %f %f %f",&matricula2,&classe,&n1,&n2,&n3,&n4);
          if (matricula1 == matricula2) {
            float media = (n1+n2+n3+n4)/4;
            printf("O ALUNO %s DA CLASSE %c TEM MEDIA %.2f\n",nome,classe,media);
            break;
          }
    }
  }
  if(fgets(linha,150,file) == NULL){
    printf("\nNÃO ENCONTRADO!\n\n");
  }


}


void inserir(FILE* file) {

  char nome[82];

  int mat;
  char turma;
  float n1;
  float n2;
  float n3;
  float n4;
  printf("MATRICULA DO ALUNO:\n");
  scanf(" %d",&mat);
  int validador = existe(file,mat);
  if(validador != 0){
    printf("\nMATRICULA JA CADASTRADA\n\n");
  }else{
    printf("NOME DO ALUNO:\n");
    scanf(" %s",nome);
    printf("TURMA DO ALUNO:\n");
    scanf(" %c",&turma);
    printf("N1 DO ALUNO:\n");
    scanf(" %f",&n1);
    printf("N2 DO ALUNO:\n");
    scanf(" %f",&n2);
    printf("N3 DO ALUNO:\n");
    scanf(" %f",&n3);
    printf("N4 DO ALUNO:\n");
    scanf(" %f",&n4);

    file = fopen("teste.txt","at");

    fputs(nome,file);
    char buffer [150];
    sprintf (buffer,"\n%d %c %.2f %.2f %.2f %.2f\n\n",mat,turma,n1,n2,n3,n4);
    fputs(buffer,file);

    fclose(file);
  }


}


int main (){


  int controlador = 5;

  while(1){
    FILE*file = fopen("teste.txt","rt");

    printf("DIGITE 0 : SAIR\n");
    printf("DIGITE 1 : buscar\n");
    printf("DIGITE 2 : inserir\n");
    printf("DIGITE 3 : modificar\n");
    printf("DIGITE 4 : excluir\n");
    scanf(" %d",&controlador);
    if(controlador == 0){
      fclose(file);
      exit(0);
    }else if(controlador == 1){
      buscar(file);
    }else if(controlador == 2){
      inserir(file);
    }else if(controlador == 3){
      modificar(file);
    }else if(controlador == 4){
      //excluir();
    }else{
      printf("\nOPÇÃO INVALIDA! tente novamente...\n\n");
    }
  }

  return 0;
}
