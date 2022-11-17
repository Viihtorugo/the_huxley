#include <stdio.h>

void print_array(int i, int n, int array[])
{
    if (i < n)
    {
        if (i == 0)
        {
            printf("[%d", array[i]);
        }
        else if (i + 1 == n)
        {
            printf(", %d]", array[i]);
        }
        else
        {
            printf(", %d", array[i]);
        }
        
        return print_array(i + 1, n, array);
    }
    
    return;
}

void binary_search (int n, int array[], int search)
{
    int i = -1, m = n, valid = 1;
	
	if (n % 2 == 0)
	    m -= 1;
	
	while (i < m - 1)
	{
	    int pivot = (i + m) / 2;
	    
	    if (search > array[pivot])
	    {
	        print_array(0, n, array);
	        printf("  ---->  %d\n", array[pivot]);
	        i = pivot;
	    }
	    else if (array[pivot] == search)
	    {
	        print_array(0, n, array);
	        printf("  ---->  %d\n", pivot);
	        valid = 0;
	        break;
	    }
	    else
	    {
	        print_array(0, n, array);
	        printf("  ---->  %d\n", array[pivot]);
	        m = pivot;
	    }
	}
	
	if (valid)
	{
	    print_array(0, n, array);
	    printf("  ---->  -1\n");
	}
}

int main() 
{
    int search, n;
    scanf("%d %d", &search, &n);
    
    int array[n];
    
    for(int i = 0; i < n; i++)
        scanf(" %d, ", &array[i]);
    
	binary_search(n, array, search);

	return 0;
}