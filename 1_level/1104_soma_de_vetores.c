#include <stdio.h>

void set_array (int i, int n, int array[])
{
    if (i >= n)
        return;
        
    scanf("%d", &array[i]);
    
    return set_array(i + 1, n, array);
}

void print_array_sum (int array1[], int array2[], int i, int n)
{
    if (i >= n)
        return;
        
    printf("%d", array1[i] + array2[i]);
    
    if (i + 1 != n)
    {
        printf(" ");
    }
    else
    {
        printf("\n");
    }
    
    return print_array_sum(array1, array2, i + 1, n);
}

int main() 
{
    int array1[10];
    int array2[10];
    
    set_array(0, 10, array1);
    set_array(0, 10, array2);
    
    print_array_sum(array1, array2, 0, 10);
    
	return 0;
}