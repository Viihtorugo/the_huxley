#include <stdio.h>

void set_matrix (int i, int e, int p, int matrix[][p])
{
    if (i < e * p)
    {
        scanf("%d", &matrix[i / p][i % p]);
        set_matrix(i + 1, e, p, matrix);
    }
}

int count_votos (int i, int column, int e, int p, int votacao[][p])
{
    if (i < e)
    {
        if (votacao[i][column])
            return 1 + count_votos (i + 1, column, e, p, votacao);
        
        return count_votos (i + 1, column, e, p, votacao);
    }
    
    return 0;
}

void resultado (int i, int e, int p, int votacao[][p])
{
    if (i < p)
    {
        printf("Princesa %d: %d voto(s)\n", i + 1, count_votos(0, i, e, p, votacao));
        resultado (i + 1, e, p, votacao);
    }
}

int main() 
{
    int p, e;
    scanf("%d %d", &p, &e);
    
    int votacao[e][p];
    set_matrix(0, e, p, votacao);

    resultado(0, e, p, votacao);
    
	return 0;
}