
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>indegree(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int neigh:adj[node]){

            indegree[neigh]--;
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }
    vector<int>dp(n+1,INT_MIN);
    vector<int>parent(n+1,-1);
    dp[1]=1;
    for(int node:topo){
        if(dp[node]==INT_MIN){
            continue;
        }
        for(int neigh:adj[node]){
            if(dp[node]+1>dp[neigh]){
                dp[neigh]=dp[node]+1;
                parent[neigh]=node;
            }
        }
    }
    if(dp[n]==INT_MIN){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>path;
    int curr=n;
    while(curr!=-1){
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(int p:path){
        cout<<p<<" ";
    }
    return 0;
}