
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
    vector<vector<long long>>dist(n+1,vector<long long>(2,LLONG_MAX));
    dist[1][0]=0;
    
    priority_queue<pair<long long,pair<long long,int>>,vector<pair<long long,pair<long long,int>>>,greater<pair<long long,pair<long long,int>>>>pq;
    
    pq.push({0,{1,0}});
    
    while(!pq.empty()){
        long long wt=pq.top().first;
        int node=pq.top().second.first;
        int used=pq.top().second.second;
        pq.pop();
        if(dist[node][used]<wt)continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWeight=it.second;
            if( wt+adjWeight < dist[adjNode][used]){
                dist[adjNode][used]=wt+adjWeight;
                
                pq.push({dist[adjNode][used],{adjNode,used}});
            }
            if(used==0){
                if( wt+adjWeight/2 < dist[adjNode][1]){
                dist[adjNode][1]=wt+adjWeight/2;
                
                pq.push({dist[adjNode][1],{adjNode,1}});
            }
            }

                
        }
    }
    
    cout<<dist[n][1];
    
    return 0;
    
}