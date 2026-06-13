#include <bits/stdc++.h>
using namespace std;

void dfs1(int idx,vector<int>adj[],vector<int>&vis,stack<int>&st){
    vis[idx]=1;
    for(auto it:adj[idx]){
        if(!vis[it]){
            dfs1(it,adj,vis,st);
        }
    }
    st.push(idx);
}

void dfs2(int node,vector<int>adj[],vector<int>&vis,int id,vector<int>&kingdom){
    vis[node]=1;
    kingdom[node]=id;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs2(it,adj,vis,id,kingdom);
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
    }
    vector<int>vis(n+1,0);
    stack<int>st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            
            dfs1(i,adj,vis,st);
        }
    }
    vector<int>revAdj[n+1];
    for(int i=1;i<=n;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            revAdj[it].push_back(i);
        }
    }
    int count=0;
    vector<int>kingdom(n+1);
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            count++;
            dfs2(node,revAdj,vis,count,kingdom);
        }
    }
    cout<<count<<endl;
    for(int i=1;i<=n;i++){
        cout<<kingdom[i]<<" ";
    }

    
    return 0;
    
}