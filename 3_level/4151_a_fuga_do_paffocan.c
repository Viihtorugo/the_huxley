#include <stdio.h>

char decrypt(char c, int key)
{
    if (c >= 'A' && c <= 'Z')
    {
        int value = ((int)c) - key;

        if (value < 'A')
            value += 26;

        return (char) value;
    }

    if (c >= 'a' && c <= 'z')
    {
        int value = ((int)c) - key;

        if (value < 'a')
            value += 26;

        return (char) value;
    }

    return c;
}

int main ()
{
    int n;
    scanf("%d", &n);

    char matrix[12][12];

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            matrix[i][j] = 'o';

    for (int i = 0; i < n; i++)
    {
        int index;
        char msg[100000];

        scanf("%d %[^\n]s", &index, msg);
        int k, j;
        scanf("%d %d", &k, &j);
        
        for (int j = 0; msg[j] != '\0'; j++)
                msg[j] = decrypt(msg[j], index);
        
        printf("%s\n", msg);

        matrix[j - 1][k - 1] = 'x';

    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%c ", matrix[i][j]);
        }
               
        printf("\n");
    }

    return 0;
}