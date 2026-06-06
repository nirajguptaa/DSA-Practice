
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,W;
    cin>>N>>W;
    
    vector<pair<int,int>>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    vector<long long>dp(W+1,0);
    for(int i=0;i<N;i++){
        int wt=arr[i].first;
        int val=arr[i].second;
        for(int w=W;w>=wt;w--){
            dp[w]=max(dp[w],val+dp[w-wt]);
        }
    }
    cout<<dp[W]<<endl;
   
    return 0;
}