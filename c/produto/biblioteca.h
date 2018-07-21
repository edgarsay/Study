#ifndef BIBLIOTECA_INCLUDED
#define BIBLIOTECA_INCLUDED

typedef struct produto
{
    int id;
    char nome[50];
    float preco;
    int quantidade;
    struct produto *prox;
} produto;

void menu();

#endif //BIBLIOTECA_INCLUDED
