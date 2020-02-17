#include <stdio.h>
#include <stdlib.h>


struct binary_tree 
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
};

int is_empty (struct binary_tree *bt)
{
	return (bt == NULL);
}

struct binary_tree *create_empty_binary_tree()
{
	return NULL;
}

struct binary_tree *create_binary_tree (int item, struct binary_tree *left, struct binary_tree *right)
{
	struct binary_tree *new = (struct binary_tree *) malloc(sizeof(struct binary_tree));
	new->item = item;
	new->left = left;
	new->right = right;

	return new;
}

void print_pre_order (struct binary_tree *bt)
{
    
	printf(" (");
	if (!is_empty(bt))
	{
		printf(" %d ", bt->item);
		print_pre_order(bt->left);
		print_pre_order(bt->right);
	}
	printf(") ");
}

void print_post_order (struct binary_tree *bt)
{
	printf(" ( ");
	if (!is_empty(bt))
	{
		print_post_order(bt->left);
		print_post_order(bt->right);
		printf("%d ", bt->item);
	}
	printf(" ) ");
}

void print_is_order (struct binary_tree *bt)
{
	printf(" ( ");
	if (!is_empty(bt))
	{
		print_is_order(bt->left);
		printf("%d ", bt->item);
		print_is_order(bt->right);
	}
	printf(" ) ");
}

struct binary_tree *search (struct binary_tree *bt, int item)
{
	if ((bt == NULL) || (bt->item == item)) 
	{
		return bt;
	}

	struct binary_tree *previous = bt;

	if (!is_empty(bt->left))
		bt = search(bt->left, item);
	
	if (!is_empty(bt->right))
		bt = search(bt->right, item);
	

	return previous;
}

/*
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


struct binary_tree *input_with_string(int i, char *string, struct binary_tree *bt)
{

	while (string[i] != '\0')
	{
		if (string[i] == '(')
		{
			bt = create_empty_binary_tree();
		}
		else if (is_number(string[i])) 
		{
			int item = create_number(string, &i);
			
			bt = create_binary_tree(item, create_empty_binary_tree(), create_empty_binary_tree());

			if (string[i] == ')')
			{
				bt = input_with_string(i + 1, string, bt->right);
				break;
			}
			else
			{
				bt->left = input_with_string(i + 1, string, bt->left);
				break;
			}

		}

		i += 1;
	}

	return bt;
}

struct binary_tree *create_new_matriz (struct binary_tree *matrix, struct binary_tree *bt)
{	
	struct binary_tree *new_bt = create_empty_binary_tree();

	if (!is_empty(matrix->left) || !is_empty(matrix->right))
	{
		new_bt = create_binary_tree(matrix->item, create_empty_binary_tree(), create_empty_binary_tree());

		if (matrix->item == bt->item)
			return create_new_matriz(bt, matrix);

		if (!is_empty(matrix->left))
		{
			new_bt->left = create_new_matriz(matrix->left, bt);
			return new_bt;
		}
		else
		{
			if (!is_empty(matrix->right))
			{
				new_bt->right = create_new_matriz(matrix->right, bt);
				return new_bt;
			}
		}
	}

	return new_bt;
}

struct binary_tree *merge (struct binary_tree *matrix, struct binary_tree *new_bt)
{
	struct binary_tree *new_matrix = searche(matrix, new_bt->item);

	if (is_empty (new_matrix))
	{
		return matrix;
	}
	else
	{
		return create_new_matriz(matrix, new_bt);
	}

}

void flush_in() {
    int c;
    do {
        c = fgetc(stdin);
    } while (c != EOF && c != '\n');
}

struct binary_tree *loop(struct binary_tree *matrix)
{
	char *string = (char *) malloc(200 * sizeof(char));
	scanf("%[^\n]s", string);
	flush_in();

	if ( (string[0] == '(') && (string[1] == ')' ) )
		return matrix;

	if (is_empty(matrix))
	{
		struct binary_tree *new_bt = input_with_string(0, string, create_empty_binary_tree());
		return  loop(new_bt);
	}
	else
	{
	
		struct binary_tree *new_bt = input_with_string(0, string, create_empty_binary_tree());
		
		matrix = merge(matrix, new_bt);
		printf("merge: ");
		print_pre_order(matrix);
		printf("\n");
	}

	return  loop(matrix);
	
}
*/

struct binary_tree *add_node (struct binary_tree *bt, int item)
{
    if (bt == NULL)
    {
        bt = create_binary_tree(item, create_empty_binary_tree(), create_empty_binary_tree());
        return bt;
    }

    if (item >= bt->item)
    {
        bt->right = add_node(bt->right, item);
    }
    else
    {
        bt->left = add_node(bt->left, item);
    }

	return bt;
}

void loop (struct binary_tree *bt)
{
    int item;
    
	printf("----\n");
    if (scanf("%d", &item) != EOF)
    {
        bt = add_node(bt, item);
		
		printf("Adicionando %d\n  ", item);
		print_pre_order(bt);
		printf("\n");

        loop(bt);
    }
}

int main ()
{
	//struct binary_tree *matrix = loop(matrix);
    
    struct binary_tree *bt = create_empty_binary_tree();
    loop(bt);

	return 0;
}