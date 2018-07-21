#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include <string.h>
#include <time.h>
#include "biblioteca.h"

aluno *head = NULL; // inicio da arvore binaria

void divisoria(){
    printf("============================\n");
}

void delay_sec(int segundos){

    int tempo_espera = segundos * 1000; // afunção clock trabalha em milisegundos, 1 segundo == 1000 milisegundos

    clock_t tempo_atual = clock(); // clock é uma função que retorna o numero de milisegundos decoridos dez de inicio do programa

    while(clock() < tempo_atual + tempo_espera);

}

void apresentacao(){

    // Equipe
    char *equipe_membro[5];
    equipe_membro[0] =       "RENATO ALVES DE OLIVEIRA  ";
    equipe_membro[1] =       "VINICIUS NUNES BARBOSA    ";
    equipe_membro[2] =       "RUAN DOS SANTOS GONDIM    ";
    equipe_membro[3] =       "EDGAR DOS SANTOS OLIVEIRA ";
    equipe_membro[4] =       "                          ";
    char *nome_programa =    "         PROGRAMA         ";
    char *nome_instituicao = "           IFCE           ";
    divisoria();
    for(int i=0;i<5;i++){
        printf("%s\n",equipe_membro[i]);
    }
    divisoria();
    printf("%s\n",nome_programa);
    divisoria();
    printf("%s\n",nome_instituicao);
    divisoria();

    delay_sec(5);   //delay de 5 segundos

}

void print_aluno(aluno *aluno){
    printf("\nMATRICULA:");   printf(" %d\n",aluno->matricula);
    printf("NOME:");        printf(" %s\n",aluno->nome);
    printf("E-MAIL:");    printf(" %s\n",aluno->email);
    printf("TELEFONE:");    printf(" %d\n",aluno->telefone);
    printf("TURMA:");       printf(" %c\n",aluno->turma);
    printf("CURSO:");       printf(" %s\n",aluno->curso);
    printf("N1:");          printf(" %.2f\n",aluno->nota[0]);
    printf("N2:");          printf(" %.2f\n",aluno->nota[1]);
    printf("N3:");          printf(" %.2f\n",aluno->nota[2]);
    printf("N4:");          printf(" %.2f\n",aluno->nota[3]);
    printf("MEDIA:");          printf(" %.2f\n",aluno->media);
}

aluno* buscar(int matricula){
    if(head == NULL){
        return NULL;
    }
    aluno* tmp = head;
    while(tmp->prox != NULL){
        if(matricula == tmp->matricula){
            return tmp;
        }
        tmp = tmp->prox;
    }
    if(matricula == tmp->matricula){
        return tmp;
    }
    return NULL;

}

void print_list(){
    aluno *tmp = head;

    while(tmp){
        printf("%d ",tmp->matricula);   printf("%s\n",tmp->nome);
        tmp = tmp->prox;
    }

}

void trocar_nos(int mat1,int mat2){
    //encontrando no 1
    aluno* previous1 = NULL;
    aluno* tmp1 = head;
    while(tmp1){
        if(mat1 == tmp1->matricula){
            break;
        }
        previous1 = tmp1;
        tmp1 = tmp1->prox;
    }
    //encontrando no 2
    aluno* previous2 = NULL;
    aluno* tmp2 = head;
    while(tmp2){
        if(mat2 == tmp2->matricula){
            break;
        }
        previous2 = tmp2;
        tmp2 = tmp2->prox;
    }

    aluno *buffer = NULL;

    if(previous1 == NULL){//caso o no 1 seja o primeiro no
        head = tmp2;
        previous2->prox = tmp1;
        buffer = tmp1->prox;
        tmp1->prox = tmp2->prox;
        tmp2->prox = buffer;
    }else if(previous2 == NULL){ //caso o no 2 seja o primeiro no
        head = tmp1;
        previous1->prox = tmp2;
        buffer = tmp1->prox;
        tmp1->prox = tmp2->prox;
        tmp2->prox = buffer;
    }else{
        previous1->prox = tmp2;
        previous2->prox = tmp1;
        buffer = tmp1->prox;
        tmp1->prox = tmp2->prox;
        tmp2->prox = buffer;
    }
}

void organiza_lista(){
    aluno * previous = head;
    aluno *tmp = head;
    while(tmp->prox != NULL){
        previous = tmp;
        tmp = tmp->prox;
        if(tmp->matricula < previous->matricula){
            trocar_nos(tmp->matricula,previous->matricula);
            organiza_lista();
        }
    }
}

int inserir(int matricula,int telefone,char *nome,char *email,char *curso,char turma,float *nota){
    if(buscar(matricula) != NULL){
        return 1;
    }
    aluno* new = (aluno*)malloc(sizeof(aluno));

    strcpy(new->nome,nome);
    strcpy(new->email,email);
    strcpy(new->curso,curso);
    new->matricula  = matricula;
    new->telefone   = telefone;
    new->turma      = turma;
    new->nota[0]    = nota[0];
    new->nota[1]    = nota[1];
    new->nota[2]    = nota[2];
    new->nota[3]    = nota[3];
    new->media      = (2*(nota[0]+nota[1])+3*(nota[2]+nota[3]))/10;

    aluno *tmp = head;

    if(head == NULL){
        head = new;
        new->prox = NULL;
    }else{
        while(tmp->prox != 0){
            tmp = tmp->prox;
        }
        tmp->prox = new;
        new->prox = NULL;
    }

    return 0;
}

int cadastrado(){
    int  matricula  = -666,
        telefone    = 0;
    char nome[50]   = "none",
        email[30]   = "none",
        curso[50]   = "none",
        turma       = 'n';
    float nota[4]   = {0,0,0,0};
    do{
        printf("MATRICULA DO NOVO ALUNO:\n");   scanf(" %d",&matricula);
        if(matricula == -666) printf("A MATRICULA É UM CAMPO OBRIGATORIO\n");
    }while(matricula == -666);
        printf("NOME DO NOVO ALUNO:\n");        scanf ( " %50[^\n]",nome);
        printf("E-MAIL DO NOVO ALUNO:\n");      scanf ( " %20[^\n]",email);
        printf("TELEFONE DO NOVO ALUNO:\n");    scanf(" %d",&telefone);
        printf("TURMA NOVO ALUNO:\n");          scanf(" %c",&turma);
        printf("CURSO DO NOVO ALUNO:\n");       scanf ( " %50[^\n]",curso);
        printf("N1 DO NOVO ALUNO:\n");          scanf(" %f",&nota[0]);
        printf("N2 DO NOVO ALUNO:\n");          scanf(" %f",&nota[1]);
        printf("N3 DO NOVO ALUNO:\n");          scanf(" %f",&nota[2]);
        printf("N4 DO NOVO ALUNO:\n");          scanf(" %f",&nota[3]);

    int i = inserir(matricula,telefone,nome,email,curso,turma,nota);
    organiza_lista();
    return i;
}

void modificar(int matricula){
    aluno *alun = buscar(matricula);
    if(alun != NULL){
        char opcao_escolhida = 'i';
        while(opcao_escolhida != 's'){
            print_aluno(alun);
            divisoria();
            printf(" '0' SAIR");    printf(" '1' NOME");
            printf(" '2' EMAIL");   printf(" '3' TELEFONE");
            printf(" '4' TURMA\n"); printf(" '5' CURSO");
            printf(" '6' N1");      printf(" '7' N2");
            printf(" '8' N3");      printf(" '9' N4\n");
            printf("ESCOLHA O QUE VOCÊ QUER MODIFICAR:");

            scanf(" %c",&opcao_escolhida);

            divisoria();
            if(opcao_escolhida == '1'){
                char nome[50];  printf("NOVO NOME DO ALUNO:\n");        scanf(" %s",nome);
                strcpy(alun->nome,nome);
            }else if(opcao_escolhida == '2'){
                char email[20]; printf("NOVO E-MAIL DO ALUNO:\n");      scanf(" %s",email);
                strcpy(alun->email,email);
            }else if(opcao_escolhida == '3'){
                int telefone;   printf("NOVO TELEFONE DO ALUNO:\n");    scanf(" %d",&telefone);
                alun->telefone = telefone;
            }else if(opcao_escolhida == '4'){
                char turma;     printf("NOVa TURMA DO ALUNO:\n");       scanf(" %c",&turma);
                alun->turma = turma;
            }else if(opcao_escolhida == '5'){
                char curso[50]; printf("NOVO CURSO DO ALUNO:\n");       scanf(" %s",curso);
                strcpy(alun->curso,curso);
            }else if(opcao_escolhida == '6'){
                float N;        printf("NOVA N1 DO ALUNO:\n");          scanf(" %f",&N);
                alun->nota[0] = N;
                //re calculando a media
                alun->media = (2*(alun->nota[0]+alun->nota[1])+3*(alun->nota[2]+alun->nota[3]))/10;
            }else if(opcao_escolhida == '7'){
                float N;        printf("NOVA N2 DO ALUNO:\n");          scanf(" %f",&N);
                alun->nota[1] = N;
                //re calculando a media
                alun->media = (2*(alun->nota[0]+alun->nota[1])+3*(alun->nota[2]+alun->nota[3]))/10;
            }else if(opcao_escolhida == '8'){
                float N;        printf("NOVA N3 DO ALUNO:\n");          scanf(" %f",&N);
                alun->nota[2] = N;
                //re calculando a media
                alun->media = (2*(alun->nota[0]+alun->nota[1])+3*(alun->nota[2]+alun->nota[3]))/10;
            }else if(opcao_escolhida == '9'){
                float N;        printf("NOVA N4 DO ALUNO:\n");          scanf(" %f",&N);
                alun->nota[3] = N;
                //re calculando a media
                alun->media = (2*(alun->nota[0]+alun->nota[1])+3*(alun->nota[2]+alun->nota[3]))/10;
            }else if(opcao_escolhida == '0'){
                return;
            }else{
                printf("OPÇÃO INVALIDA\n");
            }
        }

    }else{
        printf("MATRICULA NÃO ENCONTRADA!\n");
    }
}

void excluir(int mat){
    if(buscar(mat)){ // verificando se o aluno esta cadastrado
        aluno *previous = NULL;
        aluno *tmp = head;
        while(tmp->prox){ // buscando aluno
            if(tmp->matricula == mat){
                break;
            }
            previous = tmp;
            tmp = tmp->prox;
        }
        if(previous == NULL){ // caso ele seja o primeiro no da lista
            head = tmp->prox;
                printf("MATRICULA %d EXCLUIDA\n",mat);
            return;
        }
        previous->prox = tmp->prox;
            printf("MATRICULA %d EXCLUIDA\n",mat);
        return;
    }
    printf("MATRICULA NÃO ENCONTRADA\n");
}

void salvar(){
    FILE *file = fopen("cadastros.txt","w");

    if(head){
        aluno *tmp = head;
        while(tmp){// inserindo cada aluno dastrano no arquivo cadastros
            char buffer[50];
            fputs(tmp->nome,file);      fputs("\n",file);
            fputs(tmp->email,file);     fputs("\n",file);
            fputs(tmp->curso,file);     fputs("\n",file);

            snprintf( buffer,50,"%d",tmp->matricula);// intero em string
            fputs(buffer,file);         fputs(" ",file);
            snprintf( buffer,50,"%d",tmp->telefone);// intero em string
            fputs(buffer,file);         fputs(" ",file);
            fputc(tmp->turma,file);     fputs(" ",file);
            snprintf( buffer, 50,"%.2f",tmp->nota[0]);// float em string
            fputs(buffer,file);         fputs(" ",file);
            snprintf( buffer, 50,"%.2f",tmp->nota[1]);// float em string
            fputs(buffer,file);         fputs(" ",file);
            snprintf( buffer, 50,"%.2f",tmp->nota[2]);// float em string
            fputs(buffer,file);         fputs(" ",file);
            snprintf( buffer, 50,"%.2f",tmp->nota[3]);// float em string
            fputs(buffer,file);         fputs("\n",file);
            tmp = tmp->prox;
        }

        fclose(file);
        printf("SALVO\n");
        divisoria();
        exit(0);
    }
}

void limpando_string(char *input){
    size_t len;
    len = strlen(input); //pegando o tamanho da string
    if (input[len - 1] == '\n') //removendo '\n'
        input[--len] = 0;
}

void lendo_cadastros(){
    if(fopen("cadastros.txt","r")){
        FILE *file = fopen("cadastros.txt","r");
        char buffer[150];
        int vazio;
        while(fgets(buffer,150,file)!=0){
            int  matricula  = 0,
            telefone        = 0;
            char nome[50]   = "none",
            email[30]       = "none",
            curso[20]       = "none",
            turma           = 'n';
            float nota[4]   = {0,0,0,0};

            strcpy(nome,buffer);
            limpando_string(nome); // removedo '\n'
            fgets(buffer,150,file);
            strcpy(email,buffer);
            limpando_string(email); // removedo '\n'
            fgets(buffer,150,file);
            strcpy(curso,buffer);
            limpando_string(curso); // removedo '\n'
            fgets(buffer,150,file);
            sscanf(buffer," %d %d %c %f %f %f %f",&matricula,&telefone,&turma,&nota[0],&nota[1],&nota[2],&nota[3]);

            inserir(matricula,telefone,nome,email,curso,turma,nota);
        }
    }
}

void processando_opcao(char opcao_escolhida){
    if(opcao_escolhida == 'r'){// caso a opção "relatorio" seja escolhida

        print_list(); //printando todos os alunos cadastrados

    }else if(opcao_escolhida == 'i'){// caso a opção "inserir" seja escolhida

        cadastrado() == 0 ? printf("NOVO REGISTRO INSERIDO\n"):printf("MATRICULA JA EXISTENTE\n");

    }else if(opcao_escolhida == 'm'){// caso a opção "modificar" seja escolhida
        int mat;
        printf("MATRICULA: "); scanf(" %d",&mat);

        modificar(mat);

    }else if(opcao_escolhida == 'e'){// caso a opção "excluir" seja escolhida

        int mat;
        printf("MATRICULA: "); scanf(" %d",&mat);

        excluir(mat);

    }else if(opcao_escolhida == 'b'){// caso a opção "buscar" seja escolhida

        int mat;
        printf("MATRICULA: "); scanf(" %d",&mat);
        divisoria();
        buscar(mat) ? print_aluno(buscar(mat)) : printf("MATRICULA NÃO CADASTRADA\n");

    }else if(opcao_escolhida == 's'){// caso a opção "buscar" seja escolhida

    salvar();

    }else{//caso a opção escolhida seja invalida
        printf("OPÇÃO INVALIDA\n");
    }
}

void menu(){
    lendo_cadastros();

    char opcao_escolhida;
    divisoria();
    printf("\n'r' = relatorio | 'i' = inserir | 'm' = modificar | 'e' = excluir |'b' =  buscar|'s' = sair e salvar| \nDIGITE 1 CARACTER:\n");
    scanf(" %c", &opcao_escolhida); // recebendo opção escolhida
    divisoria();

    processando_opcao(opcao_escolhida);// processando escolha

    return menu(); //criando um loop para o programa
}
