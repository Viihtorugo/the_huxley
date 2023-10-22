#include <bits/stdc++.h>

using namespace std;

void swap (int &x, int &y)
{
    int aux = x;
    x = y;
    y = aux;
}

void selection_sort (int array[4])
{
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        int l = i;
        
        for (int j = i + 1; j < 4; j++)
        {
            if (array[j] < array[l])
            {
                l = j;
            }
            else if (array[j] == array[l])
            {
                l = j;
            }

        }

        if (l != i && array[l] != array[i])
        {
            swap(array[l], array[i]);
            count++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (i + 1 != 4)
        {
            cout << array[i] << " ";
        }
        else
        {
            cout << array[i] << endl;
        }
    }
    

    cout << count << endl;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int array[4];
    
    for (int &elem : array)
        cin >> elem;
    
    selection_sort(array);

    return 0;
}
