#include <stdio.h>

void set_array (int array[], int n, int i, int count)
{
    if (i < n)
    {
        if (n % 2 != 0)
        {
            if (i <= (n/2))
            {
                count += 1;
                set_array(array, n, i + 1, count);
            }
            else
            {
                count -= 1;
                set_array(array, n, i + 1, count);
            }
        }
        else
        {
            if (i < (n/2))
            {
                count += 1;
                set_array(array, n, i + 1, count);
            }
            else
            {
                set_array(array, n, i + 1, count - 1);
            }
        }
        
        array[i] = count;
    }
}

int check_values_equals (int array[], int i, int n)
{
    if (i < n)
    {
        if (array[n] == array[i])
            return 0;
            
        return check_values_equals(array, i + 1, n);
    }
    
    return 1;
}

int count_points(int number_rounds, int targets[], int n, int i, int array[])
{
    if (i < number_rounds)
    {
        scanf("%d", &array[i]);
        
        array[i] -= 1;
        
        if ((array[i] < n && array[i] >= 0) && (check_values_equals(array, 0, i)))
        {
            return targets[array[i]] + count_points(number_rounds, targets, n, i + 1, array);
        }
        else
        {
            return count_points(number_rounds, targets, n, i + 1, array);
        }
    }
    
    return 0;
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    int targets[n];
    set_array(targets, n, 0, 0);
    
    int number_rounds;
    scanf("%d", &number_rounds);
    
    int values_sasuke[number_rounds];
    int values_itachi[number_rounds];
    
    int sasuke = count_points(number_rounds, targets, n, 0, values_sasuke);
    int itachi = count_points(number_rounds, targets, n, 0, values_itachi);
    
    printf("Sasuke: %d\n", sasuke);
    printf("Itachi: %d\n", itachi);
    
    if (sasuke > itachi)
    {
        printf("Sasuke Uchiha\n");
        
        if (itachi == 0)
            printf("Um genjutsu desse nivel nao funciona em mim\n");
    }
    else if (sasuke < itachi)
    {
        printf("Itachi Uchiha\n");
        
        if (sasuke == 0)
            printf("Voce e fraco, lhe falta odio\n");
    }
    else
    {
        if (sasuke == 0 && itachi == 0)
        {
            printf("Os Uchihas nem sao tao bons mesmo\n");
        }
        else
        {
            printf("O empate nunca existiu, voce esta preso num genjutsu\n");
        }
    }
    
	return 0;
}