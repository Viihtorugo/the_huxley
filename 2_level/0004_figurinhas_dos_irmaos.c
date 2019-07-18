#include<stdio.h>

void setArray(int array[], int i, int n)
{
    if (i < n)
    {
        scanf("%d", &array[i]);
        setArray(array, i+1, n);
    }
}

int countPairs (int array[], int i, int n)
{
    if (i < n)
    {
        if (array[i] % 2 == 0)
            return 1 + countPairs(array, i+1, n);
        
        return countPairs(array, i+1, n);
    }
    
    return 0;
}

int countOdds (int array[], int i, int n)
{
    if (i < n)
    {
        if (array[i] % 2 != 0)
            return 1 + countOdds(array, i+1, n);
            
        return countOdds(array, i+1, n);
    }
    
    return 0;
}

int repeatedCard (int array[], int i, int id)
{
    if (i >= 0)
    {
        if(array[id] == array[i])
            return 0;
        
        return repeatedCard(array, i-1, id);
    }
    
    return 1;
}

int sumOfPairs (int array[], int i, int n)
{
    if (i < n)
    {
        if (array[i] % 2 == 0)
            if(repeatedCard(array, i-1, i))
                return array[i] + sumOfPairs(array, i+1, n);
                
        return sumOfPairs(array, i+1, n);
    }
    
    return 0;
}

int sumOfOdds (int array[], int i, int n)
{
    if (i < n)
    {
        if (array[i] % 2 != 0)
            if(repeatedCard(array, i-1, i))
                return array[i] + sumOfOdds(array, i+1, n);
                
        return sumOfOdds(array, i+1, n);
    }
    
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int array[n];
    setArray(array, 0, n);
    
    printf("%d\n%d\n", countPairs(array, 0, n), countOdds(array, 0, n));
    
    int sumPairs = sumOfPairs(array, 0, n);
    int sumOdds  = sumOfOdds(array, 0, n);
    
    if (sumPairs > sumOdds)
    {
        printf("%d\n", sumPairs);
    }
    else
    {
        printf("%d\n", sumOdds);
    }
    
    return 0;
}
