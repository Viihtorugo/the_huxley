#include <stdio.h>

void print(int n, int sum, int i)
{
    if (i <= n)
    {
        printf("%d\n", i);
        print(n, sum, i + sum);
    }
}

int main() 
{
    int n, sum, i;
    scanf("%d %d %d", &n, &sum, &i);
    
    print(n, sum, i);
	return 0;
}