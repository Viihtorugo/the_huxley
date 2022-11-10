#include <stdio.h>

void swap (int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void shell_sort (int i, int j, int array[], int n)
{
    int shell = (n - j)/2;
    
    if (shell != 0)
    {
        if (i + shell < n)
        {
            if (array[i] > array[shell + i])
                swap(&array[i], &array[i + shell]);
            
            shell_sort(i + 1, j, array, n);
        }
        else
        {
            shell_sort(0, j + 1, array, n);
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    int array[n], i;
    
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    shell_sort(0, 0, array, n);
    
    for (i = 0; i < n; i++)
    {   
        if (i + 1 == n)
        {
            printf("%d\n", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
	}
	
	return 0;
}