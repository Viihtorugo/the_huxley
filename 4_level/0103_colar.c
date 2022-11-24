#include <stdio.h>

int count_ball(int n, int *i, int init, char string[])
{
    int next_w = 1, count = 0;

    int rigth = init, left = init - 1;

    if (left < 0)
        left += n;

    if (string[init] == 'w')
    {
        (*i)++;
        next_w = 0;

        while (string[rigth % n] == 'w')
        {
            rigth += 1;
            count += 1;

            if (rigth % n == init)
                break;
        }
    }

    char c = string[rigth];

    if (c == 'b' || c == 'r')
    {

        while (string[rigth % n] == c || string[rigth % n] == 'w')
        {
            rigth += 1;
            count += 1;

            if (next_w && string[*i] == 'w')
            {
                (*i)++;
                next_w = 0;
            }

            if (rigth % n == init)
                return count;
        }

        if (string[left] == 'w')
        {
            while (string[left] == 'w')
            {
                count += 1;

                if (left == rigth % n)
                    break;

                left -= 1;
            }
        }

        if (string[left] != c)
        {
            c = string[left];

            while (string[left] == c || string[left] == 'w')
            {
                count += 1;

                if (left == rigth % n)
                    break;

                left -= 1;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    char string[n];
    scanf(" %[^\n]s", string);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int aux = count_ball(n, &i, i, string);

        if (aux > count)
            count = aux;
    }

    printf("%d\n", count);

    return 0;
}