#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int a, b, c;
    double area;
} tgl;

static bool sort_by_area(const tgl &t1, const tgl &t2)
{
    return t1.area < t2.area;
}

double set_area (int a, int b, int c)
{
    double p = ((double)(a + b + c)) / 2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <tgl> t(n);

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        t[i].a = a;
        t[i].b = b;
        t[i].c = c;
        t[i].area = set_area(a, b, c);
    }
    
    sort(t.begin(), t.end(), sort_by_area);

    for (auto ti: t)
        cout << ti.a << " " << ti.b << " " << ti.c << endl;

    return 0;
}