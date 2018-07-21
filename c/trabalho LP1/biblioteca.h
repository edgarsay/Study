#ifndef BIBLIOTECA_INCLUDED
#define BIBLIOTECA_INCLUDED

struct aluno{
    // dados do aluno
    int matricula;
    char nome[50];
    char email[50];
    int telefone;
    char turma;
    char curso[50];
    float nota[4];
    float media;

    //ponteiro
    struct aluno *prox ;
} typedef aluno, aluno;

void divisoria();

void delay_sec(int segundos);

void apresentacao();

void menu();

#endif //BIBLIOTECA_INCLUDED
