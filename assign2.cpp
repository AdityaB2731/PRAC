#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node
{
    int vertex;
    int g; // actual cost
    int h; // heuristic cost
    bool operator<(const Node &other) const
    {
        return (g + h) > (other.g + other.h);
    }
};
int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter edges (source destination cost):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }
    vector<int> h(n);
    cout << "Enter heuristic values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int start, goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;
    priority_queue<Node> pq;
    vector<bool> visited(n, false);
    pq.push({start, 0, h[start]});
    cout << "\nA* Traversal Path:\n";
    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        if (visited[current.vertex])
            continue;
        visited[current.vertex] = true;
        cout << current.vertex << " ";
        if (current.vertex == goal)
        {
            cout << "\nGoal Reached!\n";
            cout << "Total Cost = " << current.g;
            break;
        }
        for (auto neighbour : adj[current.vertex])
        {
            int nextVertex = neighbour.first;
            int edgeCost = neighbour.second;
            if (!visited[nextVertex])
            {
                pq.push({nextVertex, current.g + edgeCost, h[nextVertex]});
            }
            // pq.push({nextVertex,current.g + edgeCost,h[nextVertex]});
        }
    }
    return 0;
}