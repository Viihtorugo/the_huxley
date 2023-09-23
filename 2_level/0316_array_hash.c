#include <stdio.h>

int solved()
{
    int sum = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char string[51];
        scanf(" %s", string);

        for (int j = 0; string[j] != '\0'; j++)
            sum += j + (int)(string[j]%(int)'A') + i;
    }

    return sum;
}

int main ()
{
    int t;
    scanf("%d", &t);

    while (t--)
        printf("%d\n", solved());
    
}