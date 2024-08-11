#include <stdio.h>

void super(int n, int e)
{
    if (e < 0)
        return;

    for (int i = 0; i < e/2; i++)
    {
        printf("  ");
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
        {
            printf("*\n");
        }
        else
        {
            printf("* ");
        }
    }

    super(n + 2, e - 2);
}

void infe(int n, int e)
{
    if (n <= 0)
        return;

    for (int i = 0; i < e/2; i++)
    {
        printf("  ");
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
        {
            printf("*\n");
        }
        else
        {
            printf("* ");
        }
    }

    infe(n - 2, e + 2);
}

int main ()
{
    int n;
    char c;
    
    scanf("%d %c", &n, &c);
    if (c == 'T')
    {
        super(1,  2 * n - 1);
        infe(2 * n - 1, 0);
    }
    else if (c == 'I')
    {
        infe(2 * n - 1, 0);
    }
    else
    {
        super(1,  2 * n - 1);
    }
    

}