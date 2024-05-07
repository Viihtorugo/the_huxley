#include <stdio.h>

int verification(int init, char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0' && s2[i + init] != '\0'; i++)
    {
        if(s1[i] != s2[i + init])
            return 0;
    }
    
    return 1;
}

int main ()
{
    char string1[21];
    char string2[101];

    while(scanf("%s", string1) != EOF)
    {
        scanf("%s", string2);

        int v = 1;

        for (int i = 0; string2[i] != '\0' && v; i++)
        {
            if(verification(i, string1, string2))
            {
                printf("I'm on the empire business.\n");
                v = 0;
            }
        }

        if(v == 1)
        {
            printf("HE CAN'T KEEP GETTING AWAY WITH IT!\n");
        }
    }

    
}