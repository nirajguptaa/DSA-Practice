
#include <bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>&vis,vector<int>adj[]){
    vis[i]=1;
    for(int neigh:adj[i]){
        if(!vis[neigh]){
            dfs(neigh,vis,adj);
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
    vector<int>vis(n+1);
   
    vector<int>reps;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            reps.push_back(i);
       
            dfs(i,vis,adj);
        }
        
    }
    cout<<reps.size()-1<<endl;
    for(int i=1;i<reps.size();i++){
        cout<<reps[i-1]<<" "<<reps[i]<<endl;
    }
    
   
    
    return 0;
}