#ifndef LINKED_LIST_INCLUDED
#define LINKED_LIST_INCLUDED

struct node{
    int info;
    struct node* next;
}typedef node, node;

void push(node **head,int info);

void delete_info(node **head,int info);

void delete_position(node **head,int position);

void print_list(node *head);

int length_list(node **head);

int search_elemente(node **head,int info);

void swap_nodes(node **head,int info1,int info2);

void middle(node **head);

void pushs(node **head,int info);

void clear_list(node **head);

int count(node **head,int info);

void reverse(node **head);

int detectLoop(node **head);

node* sortedMerge(node **head1,node **head2);

#endif // LINKED_LIST_INCLUDED