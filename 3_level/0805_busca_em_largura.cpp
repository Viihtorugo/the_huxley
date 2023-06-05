#include <bits/stdc++.h>

using namespace std;

void print_path (vector <int> visited, int o, int d)
{
    if (visited[d] == o)
        return;

    print_path(visited, o, visited[d]);
    cout << " => " << visited[d];
}

void bfs (vector< vector<int> > graph, vector<int> &visited, vector<int> &count, int o)
{
    if(graph.empty())
        return;

    queue <int> q;
    q.push(o);

    visited[o] = o;
    count[o] = 0;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << "Iniciando busca em largura a partir de " << u << endl;

        for (int i = 0; i < graph[u].size(); i++)
        {
            if (visited[graph[u][i]] == -1)
            {
                visited[graph[u][i]] = u;
                count[graph[u][i]] = count[u] + 1;

                q.push(graph[u][i]); 
            }
        }
    }
    
    cout << endl;
}

int main ()
{
    int n, m, e;
    cin >> n >> m >> e;

    vector< vector<int> > graph (n);

    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
    }
    
    for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    cout << "--------" << endl;

    for (int i = 0; i < e; i++)
    {
        vector <int> visited (n, -1);
        vector <int> count (n, -1);

        int o, d;
        cin >> o >> d;

        cout << endl << "Caso de Teste #" << i + 1 << " - BFS(" << o << ")" << endl << endl;

        bfs(graph, visited, count, o);

        for (int j = 0; j < n; j++)
        {
            cout << j << " | ";

            if (count[j] == -1)
            {
                cout << "-";
            }
            else
            {
                cout << count[j];
            }

            cout << " | ";

            if (visited[j] == -1 || visited[j] == j)
            {
                cout << "-";
            }
            else
            {
                cout << visited[j];
            }

            cout << endl;
        }

        cout << endl;

        if (visited[d] == -1)
        {
            cout << "Sem caminho entre " << o << " e " << d << endl;
        }
        else
        {
            cout << "Caminho entre " << o << " e " << d << ": " << o;

            print_path(visited, o, d);

            cout << " => " << d << endl;
        }
        
        cout << endl << "--------" << endl;
    }
    

    return 0;
}