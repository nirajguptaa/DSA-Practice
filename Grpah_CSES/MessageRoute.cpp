
#include <bits/stdc++.h>
using namespace std;

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
    queue<int>q;
    q.push(1);
    vis[1]=1;
    par[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &neigh:adj[node]){
            if(!vis[neigh]){
                q.push(neigh);
                vis[neigh]=1;
                par[neigh]=node;
            }
        }
    }
   if(vis[n]==0){
       cout<<"IMPOSSIBLE"<<endl;
       return 0;
   }
   vector<int>ans;
   ans.push_back(n);
   while(par[n]!=n){
       ans.push_back(par[n]);
       n=par[n];
   }
   cout<<ans.size()<<endl;
   for(int i=ans.size()-1;i>=0;i--){
       cout<<ans[i]<<" ";
   }
    return 0;
}