#include <bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&dp){
    if(dp[node]!=-1){
        return dp[node];
    }
    int ans=0;
    for(int neigh:adj[node]){
        ans=max(ans,1+dfs(neigh,adj,dp));
        
    }
    return dp[node]=ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int>dp(n+1,-1);
    int longest=0;
    for(int i=1;i<=n;i++){
       longest=max(longest,dfs(i,adj,dp));
    }
    cout<<longest<<endl;
    return 0;
}