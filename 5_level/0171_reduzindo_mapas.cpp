#include <bits/stdc++.h>

using namespace std;

typedef struct edge
{
    int u;
    int v;
    int w;
} edge;

bool compare(edge e1, edge e2)
{
    return e1.w < e2.w;
}

class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            this->makeSet(i);
        
    }

    void makeSet(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unionSets(int u, int v)
    {
        if (this->rank[u] >= this->rank[v])
        {
            parent[u] = v;

            if (rank[u] == rank[v])
                rank[u]++;
        }
        else
        {
            parent[u] = v;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

void kruskal (vector <edge> edges, int &count, int n)
{
    UnionFind *uf = new UnionFind(n);

    for (auto edge: edges)
    {
        int u = edge.u - 1;
        int v = edge.v - 1;
        int w = edge.w;

        if (uf->find(u) != uf->find(v))
        {
            uf->unionSets(uf->find(u), uf->find(v));
            count += w;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<edge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edge e;
        e.u = u;
        e.v = v;
        e.w = w;

        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), compare);

    
    int count = 0;

    kruskal(edges, count, n);

    cout << count << endl;

    return 0;
}