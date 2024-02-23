#include <stdio.h>

int main()
{
    int array[20], n = 0;

    while (scanf("%d", &array[n]) != EOF)
        n++;

    int invert[n];
    printf("Invert: "); // 1 1 -1 -1
    for (int i = n - 1, j = 0; i >= 0; i--, j++)
    {
        invert[j] = array[i];
        printf("%d", array[i]);

        if (i != 0)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    
    printf("ParImp: "); //-1 1 -1 1
    int par_imp[n], j = 0;

    for (int i = 0; i < n; i += 2)
    {
        par_imp[j] = array[i];
        j++;
    }

    for (int i = 1; i < n; i += 2)
    {
        par_imp[j] = array[i];
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", par_imp[i]);

        if (i + 1 != n)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    

    printf("Soma: ");   // 0 2 -2 0

    for (int i = 0; i < n; i++)
    {
        printf("%d", par_imp[i] + invert[i]);

        if (i + 1 != n)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    
    return 0;
}