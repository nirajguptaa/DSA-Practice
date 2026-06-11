#include <bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;
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
    vector<long long>ways(n+1,0);
    vector<int>minFlight(n+1,INT_MAX);
    vector<int>maxFlight(n+1);
    dist[1]=0;
    ways[1]=1;
    minFlight[1]=0,maxFlight[1]=0;
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
                ways[adjNode]=ways[node];
                minFlight[adjNode]=minFlight[node]+1;
                maxFlight[adjNode]=maxFlight[node]+1;
                pq.push({dist[adjNode],adjNode});
            }
            else if( wt+adjWeight == dist[adjNode]){
                
                
                ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                minFlight[adjNode]=min(minFlight[adjNode],minFlight[node]+1);
                maxFlight[adjNode]=max(maxFlight[adjNode],maxFlight[node]+1);
                
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<minFlight[n]<<" "<<maxFlight[n];
    return 0;
    
}