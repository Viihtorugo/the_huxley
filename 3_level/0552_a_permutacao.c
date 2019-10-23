#include <stdio.h>

int length_string(int i, char string[])
{
		return (string[i] == '\0') ? i: length_string(i + 1, string);
}

int id_less(int i, int n, char string[], int id)
{
	if (i < n)
	{
		if ((int) string[i] < (int) string[id])
			id = i;

		return id_less(i + 1, n, string, id);
	}

	return id;
}

void swap (char *l1, char *l2)
{
	char aux = *l1;
	*l1	 = *l2;
	*l2 	 = aux;
}

void order_dec (int n, char string[])
{
	if (n != 0)
	{
		int id = id_less(0, n, string, 1);
		
		if ((int) string[id] < (int) string[n])
			swap(&string[id], &string[n]);

		order_dec(n - 1, string);
	}
}

void loop (int i, int n)
{
	if (i < n)
	{
		char string[100];
		scanf("%s", string);

		order_dec(length_string(0, string) - 1, string);

		printf("Caso %d: %s\n", i + 1, string);

		loop(i + 1, n);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	loop(0, n);	

	return 0;
}
