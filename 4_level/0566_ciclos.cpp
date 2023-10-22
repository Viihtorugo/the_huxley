#include <bits/stdc++.h>

using namespace std;

int dfs (vector <vector <int>> graph, vector <int> &visited, int begin)
{
    visited[begin] = 1;
    int aux = 0;

    for (auto v: graph[begin])
    {
        if (!visited[v])
        {
            aux = dfs(graph, visited, v);
        }
        else
        {
            aux = 1;
            break;
        }
    }

    return aux;
}

int main ()
{
    int n, m;
    vector <int> has_cycle;
    
    while (cin >> n >> m)
    {
        vector <vector <int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
        }
        
        int cycle = 0;

        for (int i = 0; i < n && !cycle; i++)
        {
            vector <int> visited (n, 0);
            cycle = dfs(graph, visited, i);
        }

        has_cycle.push_back(cycle);
    }
    
    for (int i = 0; i < has_cycle.size(); i++)
        cout << i + 1 << " " << has_cycle[i] << endl;

    return 0;
}