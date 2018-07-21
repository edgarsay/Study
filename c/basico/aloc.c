#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
 int matricula;
 struct node *next;
}typedef node, aluno;


void inserir(aluno**head,int matricula){
  aluno*novo = (aluno*)malloc(sizeof(aluno));
  novo->matricula = matricula;
  novo->next = *head;
  *head = novo;
}


void mostar(aluno *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->matricula);
     node = node->next;
  }
}

void buscar(aluno*node,int matricula){
  int cont = 0;
  while (node != NULL) {
    if(matricula == node->matricula){
      printf("MATRICULA: %d encontrada\n",node->matricula);
      break;
    }
    node = node->next;
    cont++;
  }
  printf("%d\n",cont);

  if(node == NULL){
    printf("MATRICULA NÃO CADASTRADA!\n");
  }
}

void deleteNode(aluno **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == NULL)
      return;

   // Store head node
   struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    aluno *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}


int main (){
  aluno* head = NULL;
  int controlador;
  while (1) {
    printf("digite\n0 para SAIR\n1 para INSERIR\n2 para BUSCAR\n3 para MODIFICAR\n4 para EXCLUIR\n");
    scanf(" %d",&controlador);
    if(controlador == 0){
      exit(0);
    }else if(controlador == 1){
      int matricula;
      printf("digite:\n");
      scanf(" %d",&matricula);
      inserir(&head,matricula);

      /*
      head é um ponteiro de ponteiro, logo
      para passalo para um função tenho que
      usar '&' e para recebelo '**'
      */
    }else if(controlador == 2){
      int matricula;
      printf("BUSCAR:\n");
      scanf(" %d",&matricula);
      buscar(head,matricula);
    }else if(controlador == 3){
      //MODIFICAR
    }else if(controlador == 4){
      int position;
      scanf("%d",position);
      deleteNode(&head_ref,position);
      }
      printf("%d\n",cont);
    }else{
      printf("OPCÃO INVALIDA!\n");
    }
  }





  return 0;
}
