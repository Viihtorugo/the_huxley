#include <bits/stdc++.h>

using namespace std;

long long int prim (vector <vector <pair<int,int>>> g, int init, int n)
{
    vector <int> weight (n, INT_MAX);
    vector <bool> visited (n, false);
    priority_queue <pair<int, int>> pq;
    pq.push({0, init});
    weight[init] = 0;

    while (!pq.empty())
    {
        pair<int, int> edge = pq.top();
        pq.pop();

        int p = -edge.first;
        int v = edge.second;

        visited[v] = true;

        for (pair<int, int> edges : g[v])
        {
            int u = edges.first;
            int p_curr = edges.second;

            if (!visited[u] && p_curr < weight[u])
            {
                weight[u] = p_curr;
                pq.push({-p_curr, u});
            }
        }
    }

    long long int sum = 0;

    for (int w: weight)
        sum += w;

    return sum;
}

long long int solve()
{
    int n;
    cin >> n;

    vector <pair <int, int>> vertices;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        vertices.push_back({x,y});
    }
    
    vector <vector <pair<int,int>>> graph (n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = vertices[i].first - vertices[j].first;
            int y = vertices[i].second - vertices[j].second;

            if (x < 0)
                x *= -1;

            if (y < 0)
                y *= -1;

            int p = x + y;

            graph[i].push_back({j, p});
            graph[j].push_back({i, p});
        }
        
    }

    return prim(graph, 0, n);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        cout << i << ": " << solve() << endl;

    return 0;
}