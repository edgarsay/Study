#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    //inicio da lista
    node* head = NULL;
    int control;

    while(1){
        printf("[1/Push][2/Delete_info]\n");
        printf("[3/Delete_position][4/Print_list]\n");
        printf("[5/Length_list][6/Search_elemente]\n");
        printf("[7/Swap][8/Middle]\n");
        printf("[9/Pushs][10/Clear List]\n");
        printf("[11/Count][12/Reverse]\n");
        printf("[13/Detectloop][14/sortedMerge]\n");
         printf("[15/reverseSize]\n");
        
        scanf(" %d",&control);
        printf("\n");
        if(control == 1){
            int info;
            printf("PUSH: ");
            scanf(" %i",&info);
            push(&head,info);
        }else if(control == 2){
            int info;
            printf("INFO: ");
            scanf(" %i",&info);
            delete_info(&head,info);
        }else if(control == 3){
            int info;
            printf("POSITION:");
            scanf(" %i",&info);
            delete_position(&head,info);
        }else if(control == 4){
            print_list(head);
            printf("\n");
        }else if(control == 5){
            int info;
            info = length_list(&head);
            printf("Length of list: %i\n",info);
        }else if(control == 6){
            int info;
            printf("Search:");
            scanf(" %i",&info);
            if(search_elemente(&head,info)){
                printf("ENCONTRADO\n");
            }else{
                printf("NÃO ENCONTRADO!\n");
            }
        }else if(control == 7){
            int info1;
            printf("Info1:\n");
            scanf(" %i", &info1);
            int info2;
            printf("Info2:\n");
            scanf(" %i", &info2);
            swap_nodes(&head,info1,info2);
        }else if(control == 8){
            middle(&head);
        }else if(control == 9){
            int info ;
            printf("QUANTOS ? \n");
            scanf(" %d",&info);
            pushs(&head,info);
        }else if(control == 10){
            printf("\nLIST DELETED!\n\n");
            clear_list(&head);
        }else if(control == 11){
            int info;
            printf("INFO:");
            scanf(" %i",&info);
            int c = count(&head,info);
            printf("COUNT :%i\n",c);
        }else if(control == 12){
            reverse(&head);
        }else if(control == 13){
            int i = detectLoop(&head);
            if(i == 1){
                printf("LOOP DETECTED!\n");
            }else{
                printf("There is no loop\n");
            }
        }else if(control == 14){
            node *head2 = NULL;
            head = sortedMerge(&head,&head2);
        }else{
            printf("OPÇÃO INVALIDA!\n");
        }

    }
    return 0;
}