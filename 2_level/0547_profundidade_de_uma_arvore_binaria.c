#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int elem;
    struct tree *right;
    struct tree *left;
} tree;

short is_number (char c)
{
    return (short) ((short) c >= 48) && ((short) c <= 57);
}

void print_pre_order (tree *root)
{
    if (root != NULL)
    {
        printf("(");
        printf("%d", root->elem);
        print_pre_order(root->left);
        print_pre_order(root->right);
        printf(")");
    }
    else
    {
        printf("()");
    }
    
}

int create_number_with_string (int *i, char *string)
{
    int number = 0;
    
    while (string[*i] != '\0' && is_number(string[*i]))
    {
        
        number = (number * 10) + (((short) string[*i]) % 48);
        
        *(i) += 1;
    }
    
    return number;
}

tree *create_tree_with_string (int *i, char *string, tree *root)
{
    while (string[*i] != '\0')
    {
        if (string[*i] == '(')
        {
            *(i) += 1;
            
            if (is_number(string[*i]))
            {
                int elem = create_number_with_string(i, string);
                
                root = (tree *) malloc(sizeof(tree));
                root->elem = elem;
                
                root->left = create_tree_with_string(i, string, root->left);
                root->right = create_tree_with_string(i, string, root->right);
                return root;
            }
            else if (string[*i] == ')')
            {
                return root;
            }
        }
        
        *(i) += 1;
    }
    
    return root;
}

int search_tree (tree *root, int elem, short *equal)
{
    if (root != NULL)
    {
        int depth = 0;
        
        if (root->elem == elem)
        {
            *equal = 1;
            return 0;
        }
        else
        {
            depth = 1 + search_tree (root->right, elem, equal);
            depth = 1 + search_tree (root->left, elem, equal);
        }
        
        return depth;
    }
    
    return 0;
}

int main() 
{
    char *string = (char *) malloc(70 * sizeof(char));
    scanf("%[^\n]s", string);
    
    int elem, i = 0;
    scanf("%d", &elem);
    
    tree *root = create_tree_with_string(&i, string, NULL);
    
    short check = -1;
    int depth = search_tree(root, elem, &check);
    
    if (check == 1)
    {
        printf("ESTA NA ARVORE\n");
        printf("%d\n", depth);
    }
    else
    {
        printf("NAO ESTA NA ARVORE\n-1\n");
    }
    
	return 0;
}