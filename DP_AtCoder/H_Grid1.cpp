#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
    int H,W;
    cin>>H>>W;
    vector<vector<char>>mat(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>mat[i][j];
        }
    }
    if(mat[0][0]=='#' || mat[H-1][W-1]=='#'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>>dp(H,vector<int>(W,0));
    if(mat[0][0]=='.')dp[0][0]=1;
    for(int i=1;i<H;i++){
        if(mat[i][0]=='.'){
            dp[i][0]=dp[i-1][0];
            
        }
    }
    for(int j=1;j<W;j++){
        if(mat[0][j]=='.'){
            
            dp[0][j]=dp[0][j-1];
        }
    }
  
    for(int i=1;i<H;i++){
        for(int j=1;j<W;j++){
            if(mat[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[H-1][W-1]<<endl;
    return 0;;
}