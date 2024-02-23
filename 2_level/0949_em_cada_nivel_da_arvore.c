#include <stdio.h>
#include <limits.h>

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

void set_array(int i, int n, int array[][2], struct node tree[], int depth)
{
	if (i != -1 && i < n)
	{
		if (array[depth][0] < tree[i].data)
			array[depth][0] = tree[i].data;

		if (array[depth][1] > tree[i].data)
			array[depth][1] = tree[i].data;
		
		set_array(tree[i].node_left, n, array, tree, depth + 1);
		set_array(tree[i].node_right, n, array, tree, depth + 1);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	struct node tree[n];	
	set_tree(0, n, tree);

	int array[n][2];

	for(int i = 0; i < n; i++)
	{
		array[i][0] = INT_MIN;
		array[i][1] = INT_MAX;
	}

	set_array(0, n, array, tree, 0);

	for (int i = 0; i < n; i++)
		if (array[i][0] != INT_MIN && array[i][0] != INT_MAX)
			printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, array[i][0], array[i][1]);
	

	return 0;
}