#ifndef AGENDA_INCLUDED
#define AGENDA_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct no
{
    int id;
    char nome[25];
    char sobrenome[65];
    char rua[50];
    char bairro[20];
    char numero[20];
    char complemento[20];
    char cidade[50];
    char estado[25];
    char fone1[15];
    char fone2[15];
    struct no *next;
} no;

int id = 1;

void divisoria()
{
    printf("==================================================================================================================\n");
}

int quantas_vezes_um_char_aparece_em(char *linha, char c)
{
    size_t size = strlen(linha);
    int cont = 0;
    for (int i = 0; i < size; i++)
    {
        if (linha[i] == c)
        {
            if (c == ';')
            {
                if(linha[i + 1] == ',')
                    return -7;
                if(linha[i + 1] == ';')
                        return ((cont+2)*-1);
            }
            cont++;
        }
    }
    return cont;
}

void inserir_novo_contato_ordenado_em(no **head, char nome[25], char sobrenome[65], char rua[40], char numero[20], char complemento[20], char bairro[20], char cidade[50], char estado[25], char fone1[15], char fone2[15], int idAutoIcremento)
{
    no *new = (no *)malloc(sizeof(no));
    if (idAutoIcremento == 0)
    {
        new->id = id;
        id++;
    }
    else
    {
        new->id = idAutoIcremento;
    }
    strcpy(new->nome, nome);
    strcpy(new->sobrenome, sobrenome);
    strcpy(new->rua, rua);
    strcpy(new->bairro, bairro);
    strcpy(new->numero, numero);
    strcpy(new->complemento, complemento);
    strcpy(new->cidade, cidade);
    strcpy(new->estado, estado);
    strcpy(new->fone1, fone1);
    strcpy(new->fone2, fone2);

    if ((*head) == NULL)
    {
        (*head) = new;
        new->next = NULL;
    }
    else
    {
        no *previous = NULL;
        no *tmp = *head;
        while (tmp != NULL && strcmp(tmp->nome, nome) < 0)
        {
            previous = tmp;
            tmp = tmp->next;
        }
        if (previous == NULL)
        {
            new->next = *head;
            *head = new;
        }
        else
        {
            new->next = previous->next;
            previous->next = new;
        }
    }
}

void inserir_novo_contato_em(no **head, char nome[25], char sobrenome[65], char rua[40], char numero[20], char complemento[20], char bairro[20], char cidade[50], char estado[25], char fone1[15], char fone2[15], int idAutoIcremento)
{
    no *new = (no *)malloc(sizeof(no));
    if (idAutoIcremento == 0)
    {
        new->id = id;
        id++;
    }
    else
    {
        new->id = idAutoIcremento;
    }

    strcpy(new->nome, nome);
    strcpy(new->sobrenome, sobrenome);
    strcpy(new->rua, rua);
    strcpy(new->bairro, bairro);
    strcpy(new->numero, numero);
    strcpy(new->complemento, complemento);
    strcpy(new->cidade, cidade);
    strcpy(new->estado, estado);
    strcpy(new->fone1, fone1);
    strcpy(new->fone2, fone2);

    if ((*head) == NULL)
    {
        (*head) = new;
        new->next = NULL;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
}

void mostrar_todos_elementos_em(no *list)
{
    divisoria();
    while (list)
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", list->id, "NOME:", list->nome, "SOBRENOME:", list->sobrenome, "RUA:", list->rua, "BAIRRO:", list->bairro, "NUMERO:", list->numero, "COMPLEMENTO:", list->complemento, "CIDADE:", list->cidade, "ESTADO:", list->estado, "FONE1:", list->fone1, "FONE2:", list->fone2);
        divisoria();
        list = list->next;
    }
}

int buscar_mostrar_elementos_em(no *head)
{
    if (head == NULL)
        return 0;
    no *tmp = head;
    no *tmpList = NULL;
    int flag = 0;
    char opcao = ' ';
    printf("BUSCAR POR :\n");
    printf("|'1' = nome|'2' = sobrenome|'3' = rua|'4' = bairro|'5' = numero|'6' = complemento|'7' = cidade|'8' = estado|'9' = fone|'0' = sair|\n");
    scanf(" %c", &opcao);
    divisoria();
    if (opcao == '1')
    {
        char nome[25] = "";
        printf("EXEMPLO DE BUSCA: Gina\n");
        printf("NOME:");
        scanf(" %25[^\n]", nome);

        divisoria();
        while (tmp)
        {
            if (strcmp(tmp->nome, nome) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '2')
    {
        char sobrenome[65];
        printf("EXEMPLO DE BUSCA: Corrêa Abel\n");
        printf("SOBRENOME:");
        scanf(" %65[^\n]", sobrenome);

        while (tmp)
        {
            if (strcmp(tmp->sobrenome, sobrenome) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '3')
    {
        char rua[40] = "";
        printf("EXEMPLO DE BUSCA: Rua Portugal Collares\n");
        printf("RUA:");
        scanf(" %40[^\n]", rua);

        while (tmp)
        {
            if (strcmp(tmp->rua, rua) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '4')
    {
        char bairro[20] = "";
        printf("EXEMPLO DE BUSCA: Mônica Dinis\n");
        printf("BAIRRO:");
        scanf(" %20[^\n]", bairro);

        while (tmp)
        {
            if (strcmp(tmp->bairro, bairro) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '5')
    {
        char numero[20] = "";
        printf("EXEMPLO DE BUSCA: 35963\n");
        printf("NUMERO:");
        scanf(" %20[^\n]", numero);

        while (tmp)
        {
            if (strcmp(tmp->numero, numero) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '6')
    {
        char complemento[20] = "";
        printf("EXEMPLO DE BUSCA: Apt 734\n");
        printf("COMPLEMENTO:");
        scanf(" %20[^\n]", complemento);

        while (tmp)
        {
            if (strcmp(tmp->complemento, complemento) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '7')
    {
        char cidade[50] = "";
        printf("EXEMPLO DE BUSCA: Jaguaruana\n");
        printf("CIDADE:");
        scanf(" %50[^\n]", cidade);

        while (tmp)
        {
            if (strcmp(tmp->cidade, cidade) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '8')
    {
        char estado[25] = "";
        printf("EXEMPLO DE BUSCA: SP\n");
        printf("ESTADO:");
        scanf(" %25[^\n]", estado);

        while (tmp)
        {
            if (strcmp(tmp->estado, estado) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '9')
    {
        char fone[15] = "";
        printf("EXEMPLO DE BUSCA: (55)975784696\n");
        printf("FONE:");
        scanf(" %15[^\n]", fone);

        while (tmp)
        {
            if (strcmp(tmp->fone1, fone) == 0 || strcmp(tmp->fone2, fone) == 0)
            {
                inserir_novo_contato_ordenado_em(&tmpList, tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2, tmp->id);
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
    else if (opcao == '0')
    {
        return 0;
    }
    else
    {
        printf("OPÇÃO INVALIDA\n");
    }

    if (flag == 0)
    {
        printf("NÃO ENCONTRADO\n");
    }
    else
    {
        mostrar_todos_elementos_em(tmpList);
        tmpList = NULL;
    }
}

void lendo_contatos_em(char *NomeDoArquivo, no **head)
{
    FILE *file = fopen(NomeDoArquivo, "r");
    char linha[160] = "";
    while (fscanf(file, " %[^\n]s ", linha) != EOF)
    {
        char nome[25] = "";
        char sobrenome[65] = "";
        char rua[40] = "";
        char bairro[20] = "";
        char numero[20] = "";
        char complemento[20] = "";
        char cidade[50] = "";
        char estado[25] = "";
        char fone1[15] = "";
        char fone2[15] = "";
        int quantidade = quantas_vezes_um_char_aparece_em(linha, ';');
        int quantidadeFone = quantas_vezes_um_char_aparece_em(linha, '\(');

        if (quantidade == 5)
        {
            sscanf(linha, " %[^' '] %[^;]; %[^;]; %[^;]; %[^;]; %[^,], %[^;]; %[^.].", nome, sobrenome, rua, numero, bairro, cidade, estado, fone1);
            inserir_novo_contato_em(head, nome, sobrenome, rua, numero, "", bairro, cidade, estado, fone1, "", 0);
        }
        else if (quantidade == 6 && quantidadeFone == 1)
        {
            sscanf(linha, " %[^' '] %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^,], %[^;]; %[^.].", nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1);
            inserir_novo_contato_em(head, nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, "", 0);
        }
        else if (quantidade == 6 && quantidadeFone == 2)
        {
            sscanf(linha, " %[^' '] %[^;]; %[^;]; %[^;]; %[^;]; %[^,], %[^;]; %[^;]; %[^.].", nome, sobrenome, rua, numero, bairro, cidade, estado, fone1, fone2);
            inserir_novo_contato_em(head, nome, sobrenome, rua, numero, "", bairro, cidade, estado, fone1, fone2, 0);
        }
        else if (quantidade == 7)
        {
            sscanf(linha, " %[^' '] %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^,], %[^;]; %[^;]; %[^.].", nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, fone2);
            inserir_novo_contato_em(head, nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, fone2, 0);
        }
        else if (quantidade == -7)
        {
            char opcao = ' ';
            printf("Na linha %d o contato não possui Cidade!\n", id);
            printf("digite '1' para ignorar ou qualquer outro caracter para fechar o programa\n");
            scanf(" %c", &opcao);
            if( opcao != '1')
                exit(1);
            sscanf(linha, " %[^' '] %[^;]; %[^;]; %[^;]; %[^;];  %[^,], %[^;]; %[^;]; %[^.].", nome, sobrenome, rua, numero, complemento, bairro, estado, fone1, fone2);
            inserir_novo_contato_em(head, nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, fone2, 0);
        }
        else
        {
            printf("REGISTRO INCORRETO, NÃO LIDO!\n");
            printf("linha: %d\n", id);
            exit(1);
            //break;
        }
    }
    fclose(file);
}

void criar_novo_contato(no **head)
{
    char b;
    char nome[25] = "";
    char sobrenome[65] = "";
    char rua[40] = "";
    char bairro[20] = "";
    char numero[20] = "";
    char complemento[20] = "";
    char cidade[50] = "";
    char estado[25] = "";
    char fone1[15] = "";
    char fone2[15] = "";

    printf("NOME:");
    scanf(" %25[^\n]", nome);
    printf("SOBRENOME:");
    scanf(" %65[^\n]", sobrenome);
    printf("RUA:");
    scanf(" %40[^\n]", rua);
    printf("BAIRRO:");
    scanf(" %20[^\n]", bairro);
    printf("NUMERO:");
    scanf(" %20[^\n]", numero);
    printf("COMPLEMENTO? 's' = sim 'n' = não\n");
    scanf(" %c", &b);
    if (b == 's')
    {
        printf("COMPLEMENTO:");
        scanf(" %20[^\n]", complemento);
    }
    else if (b != 'n')
    {
        printf("OPCAO INVALIDA!\n");
        criar_novo_contato(head);
    }
    printf("CIDADE:");
    scanf(" %50[^\n]", cidade);
    printf("ESTADO:");
    scanf(" %25[^\n]", estado);
    printf("FONE1:");
    scanf(" %15[^\n]", fone1);
    printf("Fone2? 's' = sim 'n' = não\n");
    b = ' ';
    scanf(" %c", &b);
    if (b == 's')
    {
        printf("FONE2:");
        scanf(" %[^\n]", fone2);
    }
    else if (b != 'n')
    {
        printf("OPCAO INVALIDA!\n");
        criar_novo_contato(head);
    }
    inserir_novo_contato_em(head, nome, sobrenome, rua, numero, complemento, bairro, cidade, estado, fone1, fone2, 0);
}

void remover_contato_em(no **head, int id)
{
    no *previous = NULL;
    no *tmp = *head;
    while (tmp)
    {
        if (tmp->id == id)
        {
            if (previous == NULL)
            {
                *head = tmp->next;
                free(tmp);
                return;
            }
            previous->next = tmp->next;
            free(tmp);
            return;
        }
        previous = tmp;
        tmp = tmp->next;
    }

    printf("NÃO ENCONTRADO!\n");
    return;
}

no *retorna_contato_por_ip(no **head, int id)
{
    no *tmp = *head;
    while (tmp)
    {
        if (tmp->id == id)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void modificar_contato_por_id(no **head, int id)
{
    no *tmp = retorna_contato_por_ip(head, id);
    if (tmp == NULL)
    {
        printf("NÃO ENCONTRADO!\n");
        return;
    }
    char opcao = ' ';
    printf("MODIFICAR :\n");
    printf("|'0' = nome|'1' = sobrenome|'2' = rua|'3' = bairro|'4' = numero|'5' = complemento|'6' = cidade|'7' = estado|'8' = fone1|'9' = fone2|\n");
    scanf(" %c", &opcao);
    divisoria();
    if (opcao == '0')
    {

        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[25] = "";
        printf("NOVO NOME:");
        scanf(" %25[^\n]", buffer);
        divisoria();
        strcpy(tmp->nome, buffer);
    }
    else if (opcao == '1')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[65] = "";
        printf("NOVO SOBRENOME:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->sobrenome, buffer);
    }
    else if (opcao == '2')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[50] = "";
        printf("NOVO RUA:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->rua, buffer);
    }
    else if (opcao == '3')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[20] = "";
        printf("NOVO BAIRRO:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->bairro, buffer);
    }
    else if (opcao == '4')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[20] = "";
        printf("NOVO NUMERO");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->numero, buffer);
    }
    else if (opcao == '5')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[20] = "";
        printf("COMPLEMENTO");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->complemento, buffer);
    }
    else if (opcao == '6')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[50] = "";
        printf("NOVA CIDADE:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->cidade, buffer);
    }
    else if (opcao == '7')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[25] = "";
        printf("NOVO ESTADO:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->estado, buffer);
    }
    else if (opcao == '8')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[15] = "";
        printf("NOVO FONE1:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->fone1, buffer);
    }
    else if (opcao == '9')
    {
        printf("%12s %d \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n%12s %s \n", "ID:", tmp->id, "NOME:", tmp->nome, "SOBRENOME:", tmp->sobrenome, "RUA:", tmp->rua, "BAIRRO:", tmp->bairro, "NUMERO:", tmp->numero, "COMPLEMENTO:", tmp->complemento, "CIDADE:", tmp->cidade, "ESTADO:", tmp->estado, "FONE1:", tmp->fone1, "FONE2:", tmp->fone2);
        divisoria();
        char buffer[15] = "";
        printf("NOVO FONE 2:");
        scanf(" %[^\n]", buffer);
        divisoria();
        strcpy(tmp->fone2, buffer);
    }
    else
    {
        printf("OPÇÃO INVALIDA\n");
    }
}

void escrever_contatos_em(char *NomeDoArquivo,no **head)
{
    FILE *file = fopen(NomeDoArquivo, "w");
    if (*head == NULL)
        return;
    no *tmp = *head;
    while (tmp)
    {
        if (strcmp(tmp->complemento, "") == 0 && strcmp(tmp->fone2, "") == 0)
        { //caso não tenha complemento e fone2
            fprintf(file, "%s %s; %s; %s; %s; %s,%s; %s.\n", tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1);
            tmp = tmp->next;
            continue;
        }
        if (strcmp(tmp->fone2, "") == 0)
        { //não tenha fone2

            fprintf(file, "%s %s; %s; %s; %s; %s; %s,%s; %s.\n", tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1);
            tmp = tmp->next;
            continue;
        }
        if (strcmp(tmp->complemento, "") == 0)
        { //não tenha complemento
            fprintf(file, "%s %s; %s; %s; %s; %s,%s; %s; %s.\n", tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2);
            tmp = tmp->next;
            continue;
        }
        // caso tenha complemento e fone2
        fprintf(file, "%s %s; %s; %s; %s; %s; %s,%s; %s; %s.\n", tmp->nome, tmp->sobrenome, tmp->rua, tmp->numero, tmp->complemento, tmp->bairro, tmp->cidade, tmp->estado, tmp->fone1, tmp->fone2);
        tmp = tmp->next;
    }
    fclose(file);
}

void menu()
{
    no *head = NULL;
    lendo_contatos_em("agenda.dat",&head);
    char opcao = '-';
    while (opcao != 's')
    {

        divisoria();
        printf("DIGITE UM CARACTER:\n");
        printf("|'1' = inserir|'2' = modificar|'3' = excluir|'4' = buscar|'0' = sair|\n");
        divisoria();
        scanf(" %c", &opcao);
        divisoria();
        if (opcao == '1') // inserir
        {
            system("clear");
            criar_novo_contato(&head);
            escrever_contatos_em("agenda.dat",&head);
        }
        else if (opcao == '2') // modificar
        {
            system("clear");
            buscar_mostrar_elementos_em(head);
            char inteiro[12];
            printf("ID QUE VOCÊ DESEJA MODIFICAR:");
            scanf(" %12s", inteiro);
            modificar_contato_por_id(&head, atoi(inteiro));
            escrever_contatos_em("agenda.dat",&head);
        }
        else if (opcao == '3') // excluir
        {
            system("clear");
            if (buscar_mostrar_elementos_em(head) != 0)
            {
                char inteiro[12];
                printf("ID QUE VOCÊ DESEJA DELETAR:");
                scanf(" %12s", inteiro);
                remover_contato_em(&head, atoi(inteiro));
            }
            escrever_contatos_em("agenda.dat",&head);
        }
        else if (opcao == '4') // buscar
        {
            system("clear");
            buscar_mostrar_elementos_em(head);
        }
        else if (opcao == '0') // sair
        {
            escrever_contatos_em("agenda.dat",&head);
            exit(0);
        }
        else
        {
            system("clear");
            printf("OPÇÃO INVALIDA\n");
        }
    }
    divisoria();
}

#endif //AGENDA_INCLUDED
