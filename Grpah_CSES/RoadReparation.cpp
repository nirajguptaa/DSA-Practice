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
        adj[b].push_back({a,c});
    }

    vector<int>vis(n+1,0);
    long long total=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    int cnt=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        total+=cost;
        cnt++;
        for(auto &neigh:adj[node]){
            int adjNode=neigh.first;
            int wt=neigh.second;
            if(!vis[adjNode]){
                
                pq.push({wt,adjNode});
            }
        }

    }
    if(cnt!=n){
        cout<<"IMPOSSIBLE\n";
    }else{

        cout<<total<<endl;  
    }
    return 0;
    
}