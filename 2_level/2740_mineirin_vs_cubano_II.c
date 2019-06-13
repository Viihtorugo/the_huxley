#include<stdio.h>

void swap (int *a, int *b)
{
	
		int aux = *a;
		*a 	    = *b;
		*b 	    = aux;
}

void ordernar (int *n1, int *n2, int *n3, int *n4, int *n5)
{
	if(*n1 > *n2)
		swap(n1, n2);

	if(*n2 > *n3)
		swap(n2, n3);
	
	if(*n3 > *n4)
		swap(n3, n4);

	if(*n4 > *n5)
		swap(n4, n5);

	if(*n1 > *n2 || *n2 > *n3 || *n3 > *n4 || *n4 > *n5)
		ordernar(n1, n2, n3, n4, n5);
}

int isValid(int n1, int n2, int n3, int n4, int n5, int q)
{
	if(n1*q == n2)
		if(n2*q == n3)
			if(n3*q == n4)
				if(n4*q == n5)
					return 1;

	return 0;
}

int main ()
{
	int n1, n2, n3, n4, n5;

	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

	ordernar(&n1, &n2, &n3, &n4, &n5);
	
	int q = n2/n1;
	
	if(isValid(n1, n2, n3, n4, n5, q))
	{
		printf("S\n");
		printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);
		printf("%d\n", q);
	}
	else
	{
		printf("N\n");
	}
	
}
