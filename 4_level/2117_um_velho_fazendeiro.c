#include <stdio.h>

void set_matrix (int i, int n, int m, int matrix[][m])
{
    if (i < n * m)
    {
        scanf("%d", &matrix[i / m][i % m]);
        set_matrix(i + 1, n, m, matrix);
    }
}

void print_matrix(int i, int n, int m, int matrix[][m])
{
    if (i < n * m)
    {
            printf("%d", matrix[i / m][i % m]);
            
            if (i % m != m -1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
            
            print_matrix(i + 1, n, m, matrix);
    }
}

void temporada(int i, int n, int m, int matrix[][m], int *inseticida)
{
    if (i < n * m)
    {
        if (matrix[i / m][i % m] == 1)
        {
            *inseticida += 2;
            matrix[i / m][i % m] += 1;
        }
        else if(matrix[i / m][i % m] == 2)
        {
            matrix[i / m][i % m] += 1;
        }
        
        temporada (i + 1, n, m, matrix, inseticida);
    }
}

void colher(int i, int n, int m, int matrix[][m], int *colheita)
{
    if (i < n * m)
    {
        if (matrix[i / m][i % m] == 3)
        {
            *colheita += 1;
            matrix[i / m][i % m] = 0;
        }
        
        colher(i + 1, n, m, matrix, colheita);
    }
}

void plantar (int i, int j, int m, int matrix[][m], int *inseticida)
{
    if (j < m)
    {
        if(matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            *inseticida += 2;
        }
        
        plantar(i, j + 1, m, matrix, inseticida);
    }
}

void plantio(int m, int matrix[][m], int *inseticida)
{
    int n;
    char c;
    
    scanf("%d%c", &n, &c);
    
    plantar(n, 0, m, matrix, inseticida);
    
    if (c != '\n')
    {
        return plantio(m, matrix, inseticida);
    }
    else
    {
	return;
    }
}

void ataque(int m, int matrix[][m])
{
    int i, j;
    scanf("%d %d", &i, &j);
      
    matrix[i][j] = -1;
}

void comandos (int n, int m, int matrix[][m], int *colheita, int *inseticida)
{
    char comando[10];
    
    if (scanf("%s", comando) != EOF)
    {
        
        switch (comando[0])
        {
            case 'T':
            
                temporada(0, n, m, matrix, inseticida);
                break;
                
            case 'C':
                
                colher(0, n, m, matrix, colheita);
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

int main ()
{
    int n, m, colheita = 0, inseticida = 0;
    scanf("%d %d", &n, &m);
    
    int matrix[n][m];
    set_matrix(0, n, m, matrix);
    
    comandos(n, m, matrix, &colheita, &inseticida);
    
    print_matrix(0, n, m, matrix);
    printf("\nForam colhidos %d morangos.\n", colheita);
    printf("Foram utilizados %dml de inseticida.\n", inseticida);
    
    return 0;
}
