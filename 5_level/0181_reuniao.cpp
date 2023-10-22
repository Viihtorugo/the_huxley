#include <bits/stdc++.h>

using namespace std;

int floyd_warshall (int n, vector< vector <int>> &graph)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    
    vector <int> values_max (n, INT_MIN);

    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            values_max[j] = max(values_max[j], graph[j][i]);
    
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
        ans = min(ans, values_max[i]);

    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph;

    for (int i = 0; i < n; i++)
    {
        vector<int> list (n, 100);
        graph.push_back(list);
    }
        
    for (int i = 0; i < m; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;

        graph[u][v] = p;
        graph[v][u] = p;
    }

    cout << floyd_warshall(n, graph) << endl;
    
    return 0;
}