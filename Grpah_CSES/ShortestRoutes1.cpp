
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long>dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        long long wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dist[node]<wt)continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWeight=it.second;
            if( wt+adjWeight < dist[adjNode]){
                dist[adjNode]=wt+adjWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
    
}