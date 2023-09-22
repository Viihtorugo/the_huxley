#include <stdio.h>

int len (char string[], int i)
{
    if (string[i] != '\0')
        return 1 + len(string, i + 1);
    
    return 0;
}

int main ()
{
    char string[51];
    scanf("%[^\n]s", string);

    printf("%d\n", len(string, 0));
}