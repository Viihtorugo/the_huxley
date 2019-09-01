#include<stdio.h>

struct node {
	int data;
	int node_left;
	int node_right;
};

void set_tree(int i, int n, struct node tree[])
{
	if (i < n)
	{
		scanf("%d %d %d", &tree[i].data, &tree[i].node_left, &tree[i].node_right);
		set_tree(i + 1, n, tree);
	}
}

void read_level (int i, int n, struct node tree[], int *id_less, int *id_great)
{
	if (i < n)
	{
		if (tree[i].data < tree[*id_less].data)
		{
			*id_less = i;
		}
		else if (tree[i].data > tree[*id_great].data)
		{
			*id_great = i;
		}
		
		return read_level(i + 1, n, tree, id_less, id_great);
	}
}

void query_tree(int i, int n, struct node tree[], int level)
{
	if (i < n)
	{
		int id_less = i, id_great = i;
		
		if ((i*2) + 1 <= n)
		{
			read_level(i, (i*2) + 1, tree, &id_less, &id_great);	
		}
		else
		{
			read_level(i, n, tree, &id_less, &id_great);
		}

		printf("Nivel %d: Maior = %d, Menor = %d\n", level, tree[id_great].data, tree[id_less].data);
		
		query_tree((i*2) + 1, n, tree, level + 1);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	struct node tree[n];	
	set_tree(0, n, tree);
		
	query_tree(0, n, tree, 1);
	
	return 0;
}
