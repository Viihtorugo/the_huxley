#include <bits/stdc++.h>
typedef long long unsigned llu;

using namespace std;


int main ()
{   
    int magic, mod;
    cin >> magic >> mod;

    llu count = 0;

    string bits;
    cin >> bits;

    for (auto b: bits)
    {
        if (b == '1')
        {
            count = count + magic;
            count = count % mod; 
        }
        
        magic = (magic * magic) % mod;
    }
    
    cout << count << endl;

    return 0;
}