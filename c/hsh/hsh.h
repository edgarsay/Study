#ifndef HSH_H_INCLUDED
#define HSH_H_INCLUDED

struct aluno {
  int mat;
  char nome [81];
  char turma;
  float n[4];
  struct aluno* prox;
}typedef aluno, aluno;

#define N 1001
typedef aluno* Hash[N];//MDS! O QUE É ISSO?

static int hash(int mat);

aluno* hsh_busca(Hash tab, int mat);

aluno* hsh_modificar(Hash tab,int mat);

aluno* hsh_insere (Hash tab,int mat,char* nome,float* n,char t);

void hsh_excluir(Hash tab,int mat);


#endif//HSH_H_INCLUDED
