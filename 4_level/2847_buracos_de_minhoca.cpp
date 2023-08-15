#include <bits/stdc++.h>

using namespace std;

bool count(vector<vector<int>> graph, vector<int> visited, int o, vector<vector<int>> pesos)
{
    vector<bool> v(graph.size(), true);
    int count = 0;

    //cout << "antes count - " << count << endl;

    while (visited[o] != -1 && v[visited[o]])
    {
        v[visited[o]] = false;
        o = visited[o];
        
        if (visited[o] != -1)
            count += pesos[visited[o]][o];

        //cout << "durante count - " << count << endl;
    }
    
    //cout << "depois count - " << count << endl;

    if (count < 0)
        return true;

    return false;
}

bool dfs(vector<vector<int>> graph, vector<int> &visited, vector<vector<int>> pesos, int o)
{
    for (auto edge : graph[o])
    {
        if (visited[edge] == -1)
        {
            visited[edge] = o;
            return dfs(graph, visited, pesos, edge);
        }
        else
        {
            if (count(graph, visited, edge, pesos))
            {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> visited(n, -1);
    vector<vector<int>> pesos(n);

    for (int i = 0; i < n; i++)
        pesos[i] = vector<int>(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pesos[i][j] = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        int v1, v2, p;
        cin >> v1 >> v2 >> p;

        graph[v1].push_back(v2);
        pesos[v1][v2] = p;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[j] = -1;
        
        if (dfs(graph, visited, pesos, i))
        {
            cout << "possible" << endl;
            return;            
        }
        else
        {
            /*for (int k = 0; k < n; k++)
                cout << k << ":" << visited[k] << " ";

            cout << endl;*/
            
            if (count(graph, visited, i, pesos))
            {
                cout << "possible" << endl;
                return;
            }
        }
    }
    

    cout << "not possible" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}