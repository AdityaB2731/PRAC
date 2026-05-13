#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
int main(){
    int n,e;
    cout<<"enter number of vertices:";
    cin>>n;
    cout<<"enter number of edges:";
    cin>>e;
    vector<pair<int,pair<int,int>>>edges;
    cout<<"enter edges(source,destination,cost):"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(n);
    int mst_weight=0;
    cout<<"edges in the mst"<<endl;
    for(auto edge:edges){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(ds.findUpar(u)!=ds.findUpar(v)){
            cout<<u<<"-"<<v<<":"<<w<<endl;
            mst_weight+=w;
            ds.unionbysize(u,v);
        }
    }
    cout<<"final cost"<<":"<<mst_weight<<endl;
    return 0;
}