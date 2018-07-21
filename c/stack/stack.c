#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void push(node **head,int info){
    node *new = (node*)malloc(sizeof(node));
    new->next = *head;
    new->info = info;
    *head = new;
}

void pop(node **head){
    if(*head == NULL)
        printf("EMPYT")
        return;
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

void print_list(node **head){
    node *temp = *head;
    printf("\n");
    while(temp != NULL){
        printf(" %d ",temp->info);
        temp = temp->next;
    }
     printf("\n\n");
}

void loop(node **head){
    node *faster = *head;
    node *slower = *head;

    while(faster && slower){
        if(faster->next->next){
             printf("\nThere's no Loop\n");
             return;
        }
        faster = faster->next->next;
        slower = slower->next;
        if(faster == slower){
            printf("\nloop!\n");
            return;
        }
    }
    printf("\nThere's no Loop\n");
}

