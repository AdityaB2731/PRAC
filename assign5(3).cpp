#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cout<<"enter number of vertices:";
    cin>>n;
    cout<<"enter number of edges:";
    cin>>e;
    vector<vector<pair<int,int>>>adj(n);
    cout<<"enter edges(source,destination,weight):"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    cout<<"enter source:";
    cin>>source;
    vector<int>dist(n,1e9);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto neighbour:adj[node]){
            int adjnode = neighbour.first;
            int edgewt = neighbour.second;
            if(distance+edgewt<dist[adjnode]){
                dist[adjnode]=distance+edgewt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    cout<<"shortest distances from source "<<source<<":"<<endl;
    for(int i=0;i<n;i++){
        cout<<"to node "<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}