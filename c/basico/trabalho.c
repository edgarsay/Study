#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct aluno {
  int mat;
  char nome [81];
  char turma;
  float n[4];
  struct aluno* prox;
}typedef aluno, aluno;

#define N 1001
typedef aluno* Hash[N];//MDS! O QUE É ISSO?

static int hash(int mat){
  int h = mat%1000;
  return h;
}

aluno* hsh_busca(Hash tab, int mat){
  int h = hash(mat);
  aluno* a = tab[h];
  while(a != NULL){
    if(a->mat == mat){
      printf("\nNOME: %s",a->nome);
      printf("MATRICULA: %i\n",a->mat);
      printf("TURMA: %c\n",a->turma);
      printf("N1:%.2f N2:%.2f N3:%.2f N4:%.2f\n\n",a->n[0],a->n[1],a->n[2],a->n[3]);
      return a;
    }
    a = a->prox;
  }
  printf("\nMATRICULA NÃO CADASTRADA!\n");
  return NULL;
}

aluno* hsh_insere (Hash tab,int mat,char* nome,float* n,char t){
  int h = hash(mat);
  aluno* a = tab[h];
  while (a != NULL) {
    if(a->mat == mat){
      printf("\nERRO!\nMATRICULA JA CADASTRADA!\n\n");
      break;
    }
    a = a->prox;
  }
  if(a == NULL){//elemento não encontrado
    //inserindo
    a = (aluno*) malloc(sizeof(aluno));
    a->mat = mat;
    strcpy(a->nome,nome);
    a->n[0] = n[0];
    a->n[1] = n[1];
    a->n[2] = n[2];
    a->n[3] = n[3];
    a->turma = t;

    a->prox = tab[h];
    tab[h] = a;

    return a;
  }

}

aluno* hsh_modificar(Hash tab,int mat){
  int h = hash(mat);
  aluno* a = tab[h];
  while (a != NULL) {
    if(a->mat == mat){
      printf("\nMATRICULA CADASTRADA\n\n");
      //MODIFICANDO elemento
      char nome[81];
      char turma;
      float n[4];
      printf("NOME ATUAL: %s\n",a->nome);
      printf("NOVO NOME:\n");
      scanf(" %s",nome);
      printf("TURMA ATUAL: %c\n",a->turma);
      printf("TURMA NOVA:\n");
      scanf(" %c",&turma);
      printf("N1 ATUAL: %.2f\n",a->n[0]);
      printf("N1 NOVA:\n");
      scanf(" %f",&n[0]);
      printf("N2 ATUAL: %.2f\n",a->n[1]);
      printf("N2 NOVA:\n");
      scanf(" %f",&n[1]);
      printf("N3 ATUAL: %.2f\n",a->n[2]);
      printf("N3 NOVA:\n");
      scanf(" %f",&n[2]);
      printf("N4 ATUAL: %.2f\n",a->n[3]);
      printf("N4 NOVA:\n");
      scanf(" %f",&n[3]);

      strcpy(a->nome,nome);
      a->n[0] = n[0];
      a->n[1] = n[1];
      a->n[2] = n[2];
      a->n[3] = n[2];
      a->turma = turma;
      a->prox = tab[h];
      tab[h] = a;
      return a;
    }
    a = a->prox;
  }
  if(a == NULL){//elemento não encontrado
    printf("MATRICULA NÃO CADASTRADA!\n");
    return NULL;
  }

}

void hsh_excluir(Hash tab,int mat){
  int h = hash(mat);

  if(tab[h] == NULL){
    printf("\nMATRICULAÇÃO NÃO ENCONTRADA\n\n");
    return ;
  }
  aluno*temp = tab[h];

  int position = 0;//achando posição
  while(temp != NULL) {
    if(temp->mat == mat){
      break;
    }
    temp = temp->prox;
    position++;
  }

  if(position == 0){
    tab[h] = temp->prox;
    free(temp);
    printf("\nMATRICULA %d\n\n",mat);
    return ;
  }

  temp = tab[h];
  int i;
  for(i=0;temp != NULL && i<position-1;i++){
    temp = temp->prox;
  }

  if(temp == NULL || temp->prox == NULL){
    printf("\nATRICULA %d EXCLUIDA!\n\n",mat);
    return ;
  }

  aluno*next = temp->prox->prox;

  free(temp->prox);

  temp->prox = next;
  printf("\nMATRICULA %d EXCLUIDA!\n\n",mat);
}



int main (){

  Hash tab;//I ISSO?

  int mat;
  char nome[81];
  char turma;
  float n[4];
  int controlador;

  //lendo arquivo
  FILE* file = fopen("teste.txt","rt");
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
      scanf("%d",&mat);
      hsh_busca(tab,mat);
    }else if(controlador == 2){
      printf("MATRICULA:\n");
      scanf(" %d",&mat);
      printf("NOME:\n");
      scanf(" %s",nome);
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
      scanf("%d",&mat);
      hsh_modificar(tab,mat);
    }else if(controlador == 4){
      printf("MATRICULA\n");
      scanf("%d",&mat);
      hsh_excluir(tab,mat);
    }else{
      printf("\nOPÇÃO INVALIDA! tente novamente...\n\n");
    }
  }

  return 0;
}
