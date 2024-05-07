#include <vector>
#include <iostream>
using namespace std;

struct ppair
{
    char c; 
    int v;
};

bool conv(char color)
{
    if (color == 'O')
        return false;
    else
        return true;
}

int main()
{
    int num;
    cin>>num;

    for (int i = 0; i < num; ++i)
    {
        int cur_s[2] = {0};
        int cur_p[2] = {1,1};
        
        int n = 0;
        cin>>n;

        vector<ppair> q;

        for (int j = 0; j < n; ++j)
        {
            ppair v;
            cin >> v.c >> v.v;
            q.push_back(v);
        }

        for (int j = 0; j < n; ++j)
        {
            auto &v = q[j];
            int &c = cur_p[conv(v.c)];
            int r = abs(c - v.v) + 1;
            cur_s[conv(v.c)] += r;
            c = v.v;
            if (j+1 < n)
            {
                auto &next = q[j+1];
                if (conv(v.c) != conv(next.c))
                {
                    int &cc = cur_p[conv(next.c)];
                    int rr = abs(cc - next.v) + 1;
                    if (rr < r)
                        rr += r - rr + 1;
                    cur_s[conv(next.c)] += rr;
                    cc = next.v;
                    j += 1;
                }
            }
            
        }

        cout << "Caso #" << i+1 << ": " << max(cur_s[0], cur_s[1]) << '\n';
    }

    return 0;
}