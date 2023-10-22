#include <bits/stdc++.h>

using namespace std;

void dfs(vector <stack <int>> graph, vector <int> &visited, int begin, int n)
{
    if (visited[begin])
        return;

    visited[begin] = 1;
    stack <int> aux = graph[begin];

    while (!aux.empty())
    {
        int u = aux.top();
        aux.pop();
        
        if (!visited[u])
        {
            dfs(graph, visited, u, n);
            cout << u << endl;
        }   
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, begin;
    cin >> n >> begin;

    vector <stack <int>> graph (n);

    int u, v;

    while (cin >> u >> v)
        graph[u].push(v);
    
    vector <int> visited(n, 0);

    dfs(graph, visited, begin, n);
    cout << begin << endl;

    return 0;
}