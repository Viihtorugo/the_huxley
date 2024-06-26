#include <stdio.h>

int char_to_int(int i, int *j, char matrix[][100])
{
    int num = 0;

    while (matrix[i][*j] != '\0' && (matrix[i][*j] >= '0' && matrix[i][*j] <= '9'))
    {
        num = num * 10 + (matrix[i][*j] % '0');
        *j += 1;
    }

    return num;
}

int main()
{
    char matrix[30][100];

    int n = 0;
    while (scanf(" %s", matrix[n]) != EOF)
    {
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; matrix[i][j] != '\0'; j++)
        {
            int num;

            if (matrix[i][j] >= '0' && matrix[i][j] <= '9')
            {
                num = char_to_int(i, &j, matrix);
            }

            for (int x = 0; x < num; x++)
            {
                if (matrix[i][j + 1] == '\0')
                {
                    if (x + 1 == num)
                    {
                        printf("%c\n", matrix[i][j]);
                    }
                    else
                    {
                        printf("%c ", matrix[i][j]);
                    }
                }
                else
                {
                    printf("%c ", matrix[i][j]);
                }
            }
        }
    }

    return 0;
}