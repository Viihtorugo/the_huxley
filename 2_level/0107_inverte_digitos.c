#include <stdio.h>

define long long int lli;

void invert (lli)
{
    if (lli > 0)
    {
        cout << '[' << lli % 10 << ']';
        invert(lli/10);
    }
    else
    {
        cout << endl;
    }
}

int main ()
{
    while (1)
    {
        lli num;
        cin >> num;

        if (num == 0)
            break;

        invert(num);
    }
    
    return 0;
}