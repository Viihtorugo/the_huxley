#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
    int elem;
    struct binary_tree *right;
    struct binary_tree *left;
}bt;

short is_empty (bt *root)
{
    return (short) (root == NULL);
}

void print_pre_order (bt *root)
{
    
    if (!is_empty(root))
    {
        printf(" (");
        printf(" %d ", root->elem);
        print_pre_order (root->left);
        print_pre_order (root->right);
        printf(") ");
    }
    else
    {
        printf(" () ");
    }
}

bt *insert (bt *root, int elem)
{
    if (is_empty(root))
    {
        bt *new_root = (bt *) malloc(sizeof(bt));
        new_root->elem = elem;
        return new_root;
    }
    
    if (elem >= root->elem)
    {
        root->right = insert(root->right, elem);
    }
    else
    {
        root->left = insert(root->left, elem);
    }
    
    return root;
}

void loop(bt *root)
{
    int elem;
    printf("----\n");
    if (scanf("%d", &elem) != EOF)
    {
        root = insert(root, elem);
        printf("Adicionando %d\n  ", elem);
		print_pre_order(root);
		printf("\n");;
        loop(root);
    }
}

int main() 
{
    loop(NULL);
	return 0;
}