#ifndef TREE_INCLUDED
#define TREE_INCLUDED

typedef struct no
{
    int id;
    struct no *right;
    struct no *left;
} no;


void inserir(int key, no **root)
{
    if ((*root) == NULL)
    {
        *root = (no *)malloc(sizeof(no));
        (*root)->id = key;
        (*root)->right = NULL;
        (*root)->left = NULL;
    }
    else if (key < (*root)->id)
    {
        inserir(key, &(*root)->left);
    }
    else if (key > (*root)->id)
    {
        inserir(key, &(*root)->right);
    }
}

void print(no *root)
{
    if (root == NULL)
        return;
    print(root->left);
    printf("%d\n", root->id);
    print(root->right);
}

void clear(no **root)
{
    *root = NULL;
}

void excluir(int k, no **root) // incompleto
{
    no *previous = NULL;
    no *tmp = *root;
    while (tmp)
    {
        if (tmp->id == k)
        {
            break;
        }
        else if (k > tmp->id)
        {
            previous = tmp;
            tmp = tmp->right;
        }
        else if (k < tmp->id)
        {
            previous = tmp;
            tmp = tmp->left;
        }
    }
    if (previous == NULL)
    {
    }
}

#endif //TREE_INCLUDED