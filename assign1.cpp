#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS Function
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, adj, visited);
        }
    }
}

// BFS Function
void BFS(int start, vector<vector<int>> &adj,int n)
{
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    cout << "\nDFS Traversal: ";
    DFS(0, adj, visited);

    cout << "\nBFS Traversal: ";
    BFS(0, adj,n);

    return 0;
}
