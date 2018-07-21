#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void main (){

    node *head = NULL;

    int controle = 0;
    while(1){
        printf("1/push  2/pop   3/print_list    4/loop\n");
        scanf(" %d",&controle);
        if(controle == 1){
            int info;printf("INFO:");scanf(" %d",&info);
            push(&head,info);
        }else if(controle == 2){
            pop(&head);
        }else if(controle == 3){
            print_list(&head);
        }else if(controle == 4){
            loop(&head);
        }else{
            printf("\nINVALID OPTION\n\n");
        }
    }


}