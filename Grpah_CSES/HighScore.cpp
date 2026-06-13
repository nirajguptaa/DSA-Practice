#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
    int u,v,w;
};
signed main() {
    int n,m;
    cin>>n>>m;
    vector<Edge>edges;
    vector<int>rev[n+1];
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        edges.push_back({a,b,-x});
        rev[b].push_back(a);
        
    }
    const long long INF=4e18;

    vector<int>dist(n+1,INF);
    
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(auto &e:edges){
            if(dist[e.u]==INF)continue;
            if(dist[e.u]+e.w<dist[e.v]){
                dist[e.v]=dist[e.u]+e.w;
            }
        }
    }
    vector<int>reach(n+1,0);
    queue<int>q;
    q.push(n);
    reach[n]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int par:rev[node]){
            if(!reach[par]){
                reach[par]=1;
                q.push(par);
            }
        }
    }
    for(auto &e:edges){
        if(dist[e.u]==INF)continue;
        if(dist[e.u]+e.w<dist[e.v]){
            if(reach[e.v]){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    cout<<-dist[n]<<endl;
    return 0;
    
}