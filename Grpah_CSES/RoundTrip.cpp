#include <bits/stdc++.h>
using namespace std;
vector<int>cycle;
bool found=false;
void dfs(int u,int p,vector<int>&vis,vector<int>&par,vector<int>adj[]){
    vis[u]=1;
    par[u]=p;
    for(int v:adj[u]){
        if(v==p)continue;
        if(!vis[v]){
            dfs(v,u,vis,par,adj);
            if(found)return;
        }else{
            found=true;
            cycle.push_back(v);
            int curr=u;
            while(curr!=v){
                cycle.push_back(curr);
                curr=par[curr];
            }
            cycle.push_back(v);
            reverse(cycle.begin(),cycle.end());
            return;
            
        }
    }
    
}
int main() {
    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n+1,0);
    vector<int>par(n+1,-1);
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,par,adj);
            if(found){
                cout<<cycle.size()<<endl;
                for(int x:cycle){
                    cout<<x<<" ";
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
        
    
    return 0;
}