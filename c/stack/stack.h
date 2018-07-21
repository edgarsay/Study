#ifndef STACK_INCLUDED
#define STACK_INCLUDED

struct node{
    int info;
    struct node *next;
}typedef node, node;

void push(node **head,int info);

void pop(node **head);

void print_list(node **head);

void loop(node **head);

#endif //LINKED_LIST_INCLUDED
