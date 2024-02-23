#include <stdio.h>
#include <locale.h>

int verification (int c1[256], int c2[256])
{
    for (int i = 0; i < 256; i++)
        if (c1[i] != c2[i])
            return 0;
    
    return 1;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese_Brasil");

    unsigned char s1[1000000], s2[1000000];
    scanf("%[^\n]s", s1);
    scanf(" %[^\n]s", s2);

    int c1[256] = {0}, c2[256] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] != ' ' && s1[i] != ',' && s1[i] != '.' && s1[i] != '!' && s1[i] != '?')
        {
            if (s1[i] >= 'A' && s1[i] <= 'Z')
                s1[i] = (unsigned char)((int)s1[i] + 32);

            c1[(int) s1[i]]++;
        }

    }

    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] != ' ' && s2[i] != ',' && s2[i] != '.' && s2[i] != '!' && s2[i] != '?')
        {
            if (s2[i] >= 'A' && s2[i] <= 'Z')
                s2[i] = (unsigned char)((int)s2[i] + 32);

            c2[(int) s2[i]]++;
        }
    }

    if (verification(c1, c2))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}