#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(node** head,int info){
    node* new = (node*)malloc(sizeof(node));
    new->info = info;
    new->next = (*head);
    (*head) = new;
}

void delete_info(node** head,int info){
    //1 - criar um ponteiro atual e um anterior
    node* temp = *head;
    node* previous;
    //2 - se o elemento que vai ser apagar é o primerio "0"
    if(temp != NULL && temp->info == info){
        *head = temp->next;
        free(temp);
        return;
    }
    //3 - se não for o primeiro precorre a lista ate encontrar com o anterior atraz;
    while(temp != NULL && temp->info != info){
        previous = temp;
        temp = temp->next;
    }
    //4 - caso não encontre
    if(temp == NULL){
        return;
    }
    //5 - caso enconter o anterior->proximo recerbe o proximo do atual
    previous->next = temp->next;
    free(temp);
}

void delete_position(node** head,int position){
    node* temp = *head;
    node* previous;
    if(position == 0 && temp != NULL){
        *head = temp->next;
        free(temp);
        printf("apagado\n");
        return;
    }
    int i;
    for(i = 0;i < position && temp != NULL;i++){
        if(temp == NULL){
            printf("This position doesn't exist!\n");
            return;
        }
        
        previous = temp;
        temp = temp->next;

        if(temp == NULL){
            printf("This position doesn't exist!\n");
            return;
        }
    }
    previous->next = temp->next;
    free(temp);
    printf("apagado\n");
    return;
}

void print_list(node *head){
    node* temp;
    temp = head;
    while(temp != NULL){
        printf("%d\n",temp->info);
        temp = temp->next;
    }
}

int length_list(node** head){
    node* temp = *head;
    int cont = 0;
    while(temp != NULL){
        cont ++;
        temp = temp->next;
    }
    return cont;
}

int search_elemente(node** head,int info){
    node* temp = *head;
    while(temp != NULL){
        if(temp->info == info){
            return 1;
        }
    temp = temp->next;
    }

    if(temp == NULL){
        return 0;
    }
}

void swap_nodes(node** head,int info1,int info2){
    if(info1 == info2){// verifica se as variaveis são diferentes
        return;
    }
    //devlarando ponteiros
    node* temp1 = *head;
    node* prev1 = NULL;
    node* temp2 = *head;
    node* prev2 = NULL;

    //find node 1
    while(temp1 != NULL && temp1->info != info1){
        prev1 = temp1;
        temp1 = temp1->next;
    }
    //find node 2
    while(temp2 != NULL && temp2->info != info2){
        prev2 = temp2;
        temp2 = temp2->next;
    }
    //caso as nodes não forem encontradas
    if(temp1 == NULL || temp2 == NULL){
        printf("UMA DO VALORES NÃO FOI ENCONTRADO!");
        return;
    }
    //caso node1 não seja o primeiro elemento da lista
    if(prev1 != NULL){
        prev1->next = temp2;
    }else{//caso node1 seja o primeiro elemento da lista
        *head = temp2;
    }
    //caso node2 não seja o primeiro elemento da lista
    if(prev2 != NULL){
        prev2->next = temp1;
    }else{//caso node2 seja o primeiro elemento da lista
        *head = temp1;
    }

    //mofdificando ultimos ponteiros
    node *temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;
}

void middle(node** head){// BUGS!
    node *temp1 = *head,*temp2 = *head;
    int cont = 0;
    while(temp1 != NULL){
        temp1 = temp1->next;
        cont++;
    }
    if(cont%2 == 0){
        int i;
    for(i=0;i<cont/2;i++){
        temp2 = temp2->next;
    }
        temp2 = temp2->next;
    printf("MIDDLE: %d\n\n",temp2->info);
    }else{
        int i;
        for(i=0;i<cont/2;i++){
        temp2 = temp2->next;
    }
    printf("MIDDLE: %d\n\n",temp2->info);
    }
    
}

void pushs(node **head,int info){
    int i, infoi;
    for(i = 0;i < info; i++){
        printf("%d: ",i);
        scanf(" %d",&infoi);
        printf("\n");
        push(head,infoi);
    }
}

void clear_list(node **head){
    node *temp = *head;
    node *previous;

    while(temp !=NULL){
        previous = temp;
        free(previous);
        temp = temp->next;
    }

    *head = NULL;
}

int count(node** head,int info){
    node *temp = *head;
    int count = 0;
    while(temp != NULL){
        if(temp->info == info){
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void reverse(node** head){
    node *temphead = *head;
    node *previous = NULL,*now = NULL,*temp = *head;
    while(temp->next !=NULL){
        previous = now;
        now = temp;
        temp = temp->next;
        
        now->next = previous;
          
    }
        temp->next = now;
        *head = temp;

}

int detectLoop(node **head){
    node* slower = *head;
    node* faster = *head;

    while(slower && faster && faster->next){
        slower = slower->next;
        faster = faster->next->next;
        if(faster == slower){
            return 1;
        }
    }

    return 0;
}

node* sortedMerge(node **head1,node **head2){
    node* temp1 = *head1;

    // merge the two lists
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = *head2;
    
    print_list(*head1);

    printf("\n listas unidas\n");

    //sort the new list
    node* temp2 = *head1;
    int anterior = temp2->info;
    int atual = temp2->info;
    while(temp2 != NULL){
        if(atual < anterior){
            swap_nodes(head1,anterior,atual);
        }else{
            anterior = atual;
            atual = temp2->info;
        }
        
        temp2= temp2->next;   
    }
    //return
    return *head1;
}
