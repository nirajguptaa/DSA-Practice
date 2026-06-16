#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    vector<bool>dp(K+1,false);
    dp[0]=false;
    for(int stones=1;stones<=K;stones++){
       
        for(int move:arr){
            if((stones-move)>=0 && dp[stones-move]==false){
                dp[stones]=true;
            }
        }
    }
    if(dp[K]){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}