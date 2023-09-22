#include <stdio.h>

void set_matrix(int i,  int j, int n, int m, int matrix[][m])
{
    if (i < n)
    {
        if (j < m)
        {
            scanf("%d", &matrix[i][j]);
            return set_matrix(i, j + 1, n, m, matrix);
        }

        set_matrix(i + 1, 0, n, m, matrix);
    }
}

void print_matrix(int i, int j, int n, int m, int matrix[][m])
{
    if (i < n)
    {
        if (j < m)
        {
            //printf("lin - %d e col = %d\n", i, j);
            printf("%d", matrix[i][j]);

            if (j + 1 != m)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }

            return print_matrix(i, j + 1, n, m, matrix);
        }

        return print_matrix(i + 1, 0, n, m, matrix);
    }
}

void temporada(int i, int j, int n, int m, int matrix[][m], int *inseticida)
{
    if (i < n)
    {
        if (j < m)
        {
            //printf("linha - %d e col - %d\n", i, j);
            if (matrix[i][j] == 1)
            {
                *inseticida += 2;
                matrix[i][j] += 1;
            }
            else if (matrix[i][j] == 2)
            {
                matrix[i][j] += 1;
            }

            return temporada(i, j + 1, n, m, matrix, inseticida);
        }

        temporada(i + 1, 0, n, m, matrix, inseticida);
    }
}

void colher(int i, int j, int n, int m, int matrix[][m], int *colheita)
{
    if (i < n)
    {
        if (j < m)
        {
            //printf("lin - %d e col = %d\n", i, j);
            if (matrix[i][j] == 3)
            {
                *colheita += 1;
                matrix[i][j] = 0;
            }

            return colher(i, j + 1, n, m, matrix, colheita);
        }

        return colher(i + 1, 0, n, m, matrix, colheita);
    }
}

void plantar(int i, int j, int m, int matrix[][m], int *inseticida)
{
    if (j < m)
    {
        //printf("test\n");
        if (matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            *inseticida += 2;
        }

        return plantar(i, j + 1, m, matrix, inseticida);
    }
}

int string_to_number (char string[], int *i)
{
    int num = 0;

    while ((int)string[*i] >= (int)'0' && (int) string[*i] <= (int)'9')
    {
        num = num * 10 + ((int)string[*i] % (int)'0');

        *i += 1;
    }

    return num;
}

void plantio(int m, int matrix[][m], int *inseticida)
{
    char string[10001];

    scanf(" %[^\n]s", string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        if ((int)string[i] >= (int)'0' && (int) string[i] <= (int)'9')
        {
            int n = string_to_number(string, &i);
            //printf("n = %d\n", n);
            plantar(n, 0, m, matrix, inseticida);
        }
    }    
}

void ataque(int m, int matrix[][m])
{
    int i, j;
    scanf("%d %d", &i, &j);

    matrix[i][j] = -1;
}

void comandos(int n, int m, int matrix[][m], int *colheita, int *inseticida)
{
    char comando[10];

    if (scanf("%s", comando) != EOF)
    {

        switch (comando[0])
        {
        case 'T':

            temporada(0, 0, n, m, matrix, inseticida);
            break;

        case 'C':

            colher(0, 0, n, m, matrix, colheita);
            break;

        case 'A':

            ataque(m, matrix);
            break;

        case 'P':

            plantio(m, matrix, inseticida);
            break;
        }

        comandos(n, m, matrix, colheita, inseticida);
    }
}

int main()
{
    int n, m, colheita = 0, inseticida = 0;
    scanf("%d %d", &n, &m);

    int matrix[n][m];
    set_matrix(0, 0, n, m, matrix);

    comandos(n, m, matrix, &colheita, &inseticida);

    print_matrix(0, 0, n, m, matrix);
    printf("\nForam colhidos %d morangos.\n", colheita);
    printf("Foram utilizados %dml de inseticida.\n", inseticida);

    return 0;
}
