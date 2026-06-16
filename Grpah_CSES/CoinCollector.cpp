#include <bits/stdc++.h>
using namespace std;
void dfs1(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs1(it,adj,vis,st);
        }
    }
    st.push(node);
}
void dfs2(int node,vector<int>revAdj[],vector<int>&vis,vector<int>&comp,int id){
    vis[node]=1;
    comp[node]=id;
    for(auto it:revAdj[node]){
        if(!vis[it]){
            dfs2(it,revAdj,vis,comp,id);
        }
    }
}
long long solve(int node,vector<int>dag[],vector<long long>&dp,vector<long long>&sccCoins){
        if(dp[node]!=-1){
            return dp[node];
        }
        dp[node]=sccCoins[node];
        for(auto it:dag[node]){
            dp[node]=max(dp[node],sccCoins[node]+solve(it,dag,dp,sccCoins));
        }
        return dp[node];
            
    }
int main() {
    int n,m;
    cin>>n>>m;
    vector<long long>coins(n+1);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    vector<int>adj[n+1];
    vector<int>revAdj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }
    vector<int>vis(n+1);
    stack<int>st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i,adj,vis,st);
        }
    }
    fill(vis.begin(),vis.end(),0);
    vector<int>comp(n+1);
    int sccCount=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            sccCount++;
            dfs2(node,revAdj,vis,comp,sccCount);
        }
    }
    vector<long long>sccCoins(sccCount+1);
    for(int i=1;i<=n;i++){
        sccCoins[comp[i]]+=coins[i];
    }
    vector<int>dag[sccCount+1];
    for(int u=1;u<=n;u++){
        for(auto v:adj[u]){
            if(comp[u]!=comp[v]){
                dag[comp[u]].push_back(comp[v]);
            }
        }
    }
    vector<long long> dp(sccCount + 1, -1);
    long long ans = 0;
    
    for (int i = 1; i <= sccCount; i++) {

        ans = max(ans, solve(i,dag,dp,sccCoins));

    }
    cout << ans << "\n";
    return 0;
    
}