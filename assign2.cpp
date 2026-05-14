#include<bits/stdc++.h>
using namespace std;
struct Node{
    int vertex;
    int g;
    int h;
    bool operator<(const Node&other) const{
        return (g+h)>(other.g+other.h);
    }
};
int main(){
    int n, e;
    cout << "enter the number of vertices:";
    cin >> n;
    cout << "enter the number of edges:";
    cin >> e;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cout << "enter now(source,destination,cost):";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cout << "enter the heuristics for each vertex:";
        cin >> h[i];
    }
    int start, goal;
    cout << "enter the start node:";
    cin >> start;
    cout << "enter the goal node:";
    cin >> goal;
    priority_queue<Node>pq;
    vector<bool>visited(n,false);
    vector<int>g(n,1e9);
    g[start]=0;
    pq.push({start,0,h[start]});
    cout<<"A* STAR PATH"<<endl;
    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();
        if(visited[current.vertex]) continue;
        visited[current.vertex]=true;
        cout<<current.vertex<<"-";
        if(current.vertex==goal){
            cout<<endl;
            cout<<"GOAL REACHED"<<endl;
            cout<<"COST:"<<current.g<<endl;
            break;
        }
        for(auto x:adj[current.vertex]){
            int next = x.first;
            int wt = x.second;
            int newval = wt+current.g;
            if(g[next] >newval){
                g[next]=newval;
                pq.push({next,newval,h[next]});
            }
        }
    }
    return 0;
}