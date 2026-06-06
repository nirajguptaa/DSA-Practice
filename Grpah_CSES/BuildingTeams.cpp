
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
    vector<int>col(n+1,-1);
    for(int i=1;i<=n;i++){
        queue<int> q;
        if(col[i]==-1){
            q.push(i);
            col[i]=1;
        while(!q.empty()){
            int node=q.front();
            int colNode=col[node];
            q.pop();
            for(int neigh:adj[node]){
                if(col[neigh]==-1){
                    col[neigh]=!colNode;
                    q.push(neigh);
                
                }else if(col[neigh]==colNode){
                    cout<<"IMPOSSIBLE";
                    return 0;
                }
            }
        }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            cout<<2<<" ";
        }else{
            cout<<1<<" ";
        }
    }
    
   
    
   
    
    return 0;
}