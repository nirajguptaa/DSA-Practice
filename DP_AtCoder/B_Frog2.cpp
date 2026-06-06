#include <bits/stdc++.h>
using namespace std;
int main() {
   int N,K;
   
   cin>>N>>K;
   vector<int>ele(N);
   for(int i=0;i<N;i++){
       cin>>ele[i];
   }
  
   vector<int>dp(N,INT_MAX);
   dp[0]=0;
    for(int i=1;i<N;i++){
        int minCost=INT_MAX;
        for(int j=i-1,cnt=1;j>=0 && cnt<=K;j--,cnt++){
            minCost=min(minCost,dp[j]+abs(ele[i]-ele[j]));
            
        }
        dp[i]=minCost;
    }
    cout<<dp[N-1]<<endl;
    return 0;
}