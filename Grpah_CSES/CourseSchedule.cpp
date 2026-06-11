
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>&state,stack<int>&st,vector<int>adj[]){
    state[node]=1;
    for(int neigh:adj[node]){
        if(state[neigh]==1){
            return true;
        }
        if(state[neigh]==0){
            if(dfs(neigh,state,st,adj)){
                return true;
            }
        }
    }
    state[node]=2;
    st.push(node);
    return false;
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
    vector<int>state(n+1,0);
    stack<int>st;
    for(int i=1;i<=n;i++){
        if(state[i]==0){
            if(dfs(i,state,st,adj)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}