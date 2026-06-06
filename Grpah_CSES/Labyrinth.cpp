// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
   int n,m;
   cin>>n>>m;
   vector<vector<char>>rooms(n,vector<char>(m));
   int sx,sy,ex,ey;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>rooms[i][j];
           if(rooms[i][j]=='A'){
               sx=i;
               sy=j;
           }
           if(rooms[i][j]=='B'){
               ex=i;
               ey=j;
           }
       }
   }
   queue<pair<int,int>>q;
   vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
   vector<vector<char>>moveTaken(n,vector<char>(m));
   
   vector<vector<int>>vis(n,vector<int>(m,0));
   q.push({sx,sy});
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    char dir[4]={'U','D','L','R'};
   vis[sx][sy]=1;
   while(!q.empty()){
       int r=q.front().first;
       int c=q.front().second;
       q.pop();
       for(int i=0;i<4;i++){
          int nr=r+row[i];
          int nc=c+col[i];
          if(nr>=0 && nc>=0 &&nr<n && nc<m && rooms[nr][nc]!='#' && vis[nr][nc]==0){
              vis[nr][nc]=1;
              q.push({nr,nc});
              parent[nr][nc]={r,c};
              moveTaken[nr][nc]=dir[i];
              
          }
       }
   }
   if(vis[ex][ey]==0){
       cout<<"NO"<<endl;
       return 0;
   }
   string path="";
   int r=ex,c=ey;
   while(!(r==sx && c==sy)){
       path+=moveTaken[r][c];
       int pr=parent[r][c].first;
       int pc=parent[r][c].second;
       r=pr;
       c=pc;
   }
   reverse(path.begin(),path.end());
  
   cout<<"YES"<<endl;
   cout<<path.size()<<endl;
    cout<<path<<endl;
   
   
    return 0;
}