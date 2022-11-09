#include <stdio.h>
#include <stdlib.h>

typedef struct tree tree;

struct tree
{
    int item;
    tree *right;
    tree *left;
};

void print_is_order (tree *root)
{
	if (root != NULL)
	{
		printf("(");
		printf(" %d ", root->item);
		print_is_order(root->left);
		print_is_order(root->right);
		printf(")");
	}
	else
	{
		printf("()");
	}
}

short is_number(char c)
{
	return ((int) c >=  48) && ((int) c <= 57);
}

int create_number (char string[], int *i)
{
	int number = 0;

	while (string[*i] != '\0' && is_number(string[*i]))
	{
		if (number)
		{
				number = (number * 10) + ((int) (string[*i] % 48));	
		}
		else
		{
				number = (int) (string[*i] % 48); 
		}

		*(i) = *(i) +  1;
	}

	return number;
}

tree *input_with_string(int *i, char *string, tree *root)
{

	while (string[*i] != '\0')
	{
		if (string[*i] == '(')
		{
			*(i) += 1;

			if (is_number(string[*i]))
			{
				int item = create_number(string, i);
			
				root = (tree *) malloc(sizeof(tree));
				root->item = item;

				root->left = input_with_string(i, string, root->left);
				root->right = input_with_string(i, string, root->right);
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

void is_binary_tree (tree *root, int *bt)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			if (root->left->item > root->item)
				*bt = 0;
		
		if (root->right != NULL)
			if (root->right->item < root->item)
				*bt = 0;
		
		is_binary_tree(root->left, bt);
		is_binary_tree(root->right, bt);
	}
}

int main ()
{
    char *string = (char *) malloc(200 * sizeof(char));
	scanf("%[^\n]s", string);

	int i = 0;

	tree *root = input_with_string(&i, string, NULL);
	
	int bt = 1;
	is_binary_tree(root, &bt);

	if (bt)
	{
		printf("VERDADEIRO\n");
	}
	else
	{
		printf("FALSO\n");
	}
	

    return 0;
}
