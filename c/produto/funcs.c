#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"

produto *head = NULL;
produto *head2 = NULL;

void swap_nos(int id1, int id2)
{
    if (head == NULL)
        return;
    produto *tmp1 = head;
    produto *previous1 = NULL;
    while (tmp1)
    {
        if (tmp1->id == id1)
        {
            break;
        }
        previous1 = tmp1;
        tmp1 = tmp1->prox;
    }
    produto *tmp2 = head;
    produto *previous2 = NULL;
    while (tmp2)
    {
        if (tmp2->id == id2)
        {
            break;
        }
        previous2 = tmp2;
        tmp2 = tmp2->prox;
    }
    if (previous1 == NULL)
    {
        head = tmp2;
        previous2->prox = tmp1;
        produto *tmp_tmp = tmp1->prox;
        tmp1->prox = tmp2->prox;
        tmp2->prox = tmp_tmp;
        return;
    }
    if (previous2 == NULL)
    {
        head = tmp1;
        previous1->prox = tmp2;
        produto *tmp_tmp = tmp2->prox;
        tmp2->prox = tmp1->prox;
        tmp1->prox = tmp_tmp;
        return;
    }
    previous1->prox = tmp2;
    previous2->prox = tmp1;
    produto *tmp_tmp = tmp1->prox;
    tmp1->prox = tmp2->prox;
    tmp2->prox = tmp_tmp;
}

void ordena()
{
    if (head == NULL)
        return;
    produto *tmp = head;
    produto *previous = head;
    while (tmp)
    {
        if (strcmp(previous->nome, tmp->nome) > 0)
        {
            swap_nos(previous->id, tmp->id);
            ordena();
        }
        previous = tmp;
        tmp = tmp->prox;
    }
}

void divisoria()
{

    printf("====================================================================================\n");
}

produto *busca_estoque(int id_tmp)
{
    produto *tmp = head2;

    while (tmp)
    {
        if (tmp->id == id_tmp)
        {
            return tmp;
        }
        tmp = tmp->prox;
    }
    return NULL;
}

produto *busca_cotacao(int id)
{
    produto *tmp = head;

    while (tmp)
    {
        if (tmp->id == id)
        {
            return tmp;
        }
        tmp = tmp->prox;
    }
    return NULL;
}

void inserir(int id)
{
    produto *produto_estoque = busca_estoque(id);
    if (produto_estoque != NULL)
    {
        produto *new = busca_cotacao(id);
        if (new)
        {
            new->quantidade += 1;
            return;
        }
        new = (produto *)malloc(sizeof(produto));
        strcpy(new->nome, produto_estoque->nome);
        new->preco = produto_estoque->preco;
        new->id = id;
        new->quantidade = 1;
        if (head == NULL)
        {
            head = new;
            new->prox = NULL;
        }
        else
        {
            produto *tmp = head;
            new->prox = tmp;
            head = new;
        }
        return;
    }
    else
    {
        printf("PRODUTO NÃO LISTADO!\n");
    }
}

void gerar_cotacao()
{
    FILE *file = fopen("cotacao.txt", "w");

    produto *tmp = head;
    float total = 0;
    if (tmp != NULL)
    {
        while (tmp)
        {

            fprintf(file, "%20s %4.2f x %d|\n", tmp->nome, tmp->preco, tmp->quantidade);
            total += tmp->preco * tmp->quantidade;
            tmp = tmp->prox;
        }
        fprintf(file, "-------------------------------\n");
        fprintf(file, "%20s %4.2f %3c\n", "Total", total, '|');
        fprintf(file, "===============================\n");
    }
    fclose(file);
    system("notepad cotacao.txt");
}

void ler()
{
    FILE *file = fopen("dados.txt", "r");
    float total = 0;
    char nome[50];
    float preco;
    int id_marcador = 1;
    while (fscanf(file, " %[^\n]s", nome) != EOF)
    {
        fscanf(file, " %f", &preco);
        produto *new = (produto *)malloc(sizeof(produto));
        strcpy(new->nome, nome);
        new->preco = preco;
        new->id = id_marcador;
        id_marcador += 1;
        if (head2 == NULL)
        {
            head2 = new;
            new = NULL;
        }
        else
        {
            produto *tmp = head2;
            new->prox = tmp;
            head2 = new;
        }
    }
}

void print_dados()
{
    produto *tmp = head2;
    if (tmp != NULL)
    {
        while (tmp)
        {
            printf("%1d %20s %4.2f|\n", tmp->id, tmp->nome, tmp->preco);
            tmp = tmp->prox;
        }
    }
}

void print_list()
{
    produto *tmp = head;
    if (tmp != NULL)
    {
        while (tmp)
        {
            printf("%1d %20s %4.2f x %d|\n", tmp->id, tmp->nome, tmp->preco, tmp->quantidade);
            tmp = tmp->prox;
        }
    }
}

void modificar()
{
    char opcao = '.';
    printf("MODIFICAR 'p' = PRODUTOS OU 'l' = LISTA DE COMPRA\n");
    scanf(" %c", &opcao);
    produto *tmp = NULL;
    int id = -1;
    if (opcao == 'p')
    {
        print_dados();
        printf("ID:");
        scanf(" %d", &id);
        tmp = busca_estoque(id);
    }
    else if (opcao == 'l')
    {
        print_list();
        printf("ID:");
        scanf(" %d", &id);
        tmp = busca_cotacao(id);
    }
    else
    {
        printf("OPÇÃO INVALIDA!\n");
        modificar();
    }
    if (tmp == NULL)
    {
        printf("ID NÃO ENCONTRADO!\n");
        return;
    }
    opcao = '.';
    printf("O QUE VOCÊ QUER MODIFICAR 'n' = NOME OU 'p' = PRECO\n");
    scanf(" %c", &opcao);
    if (opcao == 'n')
    {
        char nome[50] = "";
        printf("NOVO NOME:");
        scanf(" %s", nome);
        strcpy(tmp->nome, nome);
        ordena();
        return;
    }
    else if (opcao == 'p')
    {
        float preco = 0;
        printf("NOVO PRECO:");
        scanf(" %f", &preco);
        tmp->preco = preco;
        return;
    }
    else
    {
        printf("OPÇÃO INVALIDA!\n");
        modificar();
    }
}

void excluir()
{
    int id = -1;
    print_list();
    printf("ID:");
    scanf(" %d", &id);
    produto *tmp = busca_cotacao(id);
    if (tmp == NULL)
    {
        printf("ID NÃO ENCONTRADO\n");
        return;
    }
    else if (tmp->quantidade > 1)
    {
        tmp->quantidade -= 1;
        return;
    }
    tmp = head;
    produto *previous = NULL;
    while (tmp)
    {
        if (tmp->id == id)
        {
            break;
        }
        previous = tmp;
        tmp = tmp->prox;
    }
    if (previous == NULL)
    {
        head = tmp->prox;
        free(tmp);
        return;
    }
    previous->prox = tmp->prox;
    free(tmp);
}

void processando_opcao(char opcao_escolhida)
{
    if (opcao_escolhida == 'a')
    { // "adicionar"
        int id;
        print_dados();
        printf("ID DO PRODUTO:\n");
        scanf(" %d", &id);
        inserir(id);
    }
    else if (opcao_escolhida == 'm')
    { // "modificar"
        modificar();
    }
    else if (opcao_escolhida == 'e')
    { // "excluir"
        excluir();
    }
    else if (opcao_escolhida == 'c')
    { // "gerar cotação"
        gerar_cotacao();
        printf("COTAÇÃO GERADA\n");
    }
    else if (opcao_escolhida == 'l')
    { // "lista de produtos"
        ordena();
        print_list();
    }
    else if (opcao_escolhida == 's')
    { // "sair"
        exit(0);
    }
    else
    { // "erro"
        printf("OPÇÃO INVALIDA!\n");
    }
}

void menu()
{
    ler();
    char opcao_escolhida;
    while (opcao_escolhida != 's')
    {
        divisoria();
        printf("DIGITE 1 CARACTER:\n|'a' ADICIONAR|'m' MODIFICAR|'e' EXCLUIR|'l' LISTA DE PRODUTOS|'c' COTAÇÃO|'s' SAIR|\n");
        scanf(" %c", &opcao_escolhida); // recebendo opção escolhida
        divisoria();
        processando_opcao(opcao_escolhida);
    }
}
