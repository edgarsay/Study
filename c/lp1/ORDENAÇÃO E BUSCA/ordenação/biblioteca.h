#ifndef BIBLIOTECA_INCLUDED
#define BIBLIOTECA_INCLUDED

struct aluno {
	int info;
  struct aluno* prox;
}typedef aluno, aluno;

void bolha(int n,int *v);

void bolhaR(int n, int *v);

void bolha_gen(int n,void *v, int tam, int(*cmp)(void*,void*));

void *acessa(void *v, int i, int tam);

int compara(void * a, void *b);

void troca (void *p1, void *p2, int tam);

#endif //BIBLIOTECA_INCLUDED
