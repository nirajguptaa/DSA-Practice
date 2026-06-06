
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(3,0));
    for(int i=0;i<3;i++){
        dp[0][i]=mat[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                dp[i][0]=mat[i][0]+max(dp[i-1][1],dp[i-1][2]);
            }else if(j==1){
                 dp[i][1]=mat[i][1]+max(dp[i-1][0],dp[i-1][2]);
            }else{
                dp[i][2]=mat[i][2]+max(dp[i-1][0],dp[i-1][1]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}