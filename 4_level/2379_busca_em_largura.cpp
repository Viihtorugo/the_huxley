#include <bits/stdc++.h>

using namespace std;

void bfs(vector <stack <int>> graph, int begin, int n)
{
    vector <int> visited (n, 0);
    queue <int> q;
    q.push(begin);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        
        visited[v] = 1;
        cout << v << endl;

        stack <int> aux = graph[v];

        while (!aux.empty())
        {
            int u = aux.top();

            if (!visited[u])
            {
                visited[u] = 1;
                q.push(u);
            }

            aux.pop();
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
    
    bfs(graph, begin, n);

    return 0;
}