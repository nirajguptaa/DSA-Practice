
#include <bits/stdc++.h>
using namespace std;
// The meaning of dp[v] is:
// Minimum weight needed to achieve value v

int main() {
    int N,W;
    cin>>N>>W;
    
    vector<pair<int,int>>arr(N);
    int totalVal=0;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
        totalVal+=arr[i].second;
    }
    vector<long long>dp(totalVal+1,INT_MAX);
    dp[0]=0;//achieve val 0 we need 0 wt
    for(int i=0;i<N;i++){
        int wt=arr[i].first;
        int val=arr[i].second;
        for(int v=totalVal;v>=val;v--){
            if(dp[v-val]!=INT_MAX){
                
                dp[v]=min(dp[v],wt+dp[v-val]);
            }
        }
        
    }
    int ans=0;
    for(int i=0;i<=totalVal;i++){
        if(dp[i]<=W){
            ans=i;
        }
    }
    cout<<ans<<endl;
   
    return 0;
}