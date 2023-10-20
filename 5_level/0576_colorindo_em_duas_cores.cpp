#include <bits/stdc++.h>

using namespace std;

void bfs (vector <vector <int>> g, vector <int> &w, vector <int> &b, int n)
{
    vector <int> visited (n, 0);
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue <pair<int, char>> q;
            q.push({i, 0});
            
            while (!q.empty())
            {
                auto vert = q.front();
                int v = vert.first;
                int color = vert.second;
                q.pop();
                
                visited[v] = 1;
                
                if (color)
                    b[v]++;
                else
                    w[v]++;
                
                int new_color;
                
                if (color)
                    new_color = 0;
                else
                    new_color = 1;
                
                for (auto u :g[v])
                {
                    if (!visited[u])
                    {
                        q.push({u, new_color});
                    }
                    else
                    {
                        if (color)
                        {
                            w[u]++;
                        }
                        else
                        {
                            b[u]++;
                        }
                    }
                }
            }
        }
    }
    
    
    
}

bool solve (int n)
{
    vector <vector <int>> graph (n);
    vector <int> w(n, 0), b(n, 0);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        
        graph[v].push_back(u);
    }
    
    bfs(graph, w, b, n);
    
    for (int i = 0; i < n; i++)
        if (w[i] != 0 && b[i] != 0)
            return false;
    
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while (1)
    {
        int n;
        cin >> n;
        
        if (n == 0)
            break;
        
        if (solve(n))
        {
            cout << "BICOLORABLE.\n";
        }
        else
        {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    
	return 0;
}