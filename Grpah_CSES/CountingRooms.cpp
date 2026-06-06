#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&house){
    int n=house.size();
    int m=house[0].size();
    house[i][j]='#';
    int row[4]={-1,0,1,0};
    int col[4]={0,-1,0,1};
    for(int x=0;x<4;x++){
        int r=i+row[x];
        int c=j+col[x];
        if(r>=0 && c>=0 && r<n && c<m && house[r][c]=='.' ){
            dfs(r,c,house);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>house(n,vector<char>(m));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>house[i][j];
       }
   }
   int count=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(house[i][j]=='.'){
               count++;
               dfs(i,j,house);
           }
       }
   }
    cout<< count<<endl;
  
}