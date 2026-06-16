#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<long long>>dp(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;
            dp[l][r]=max(arr[l]-dp[l+1][r],
            arr[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}

//dp[l][r] = maximum score difference (current player − other player).