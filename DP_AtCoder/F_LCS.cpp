#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int lens=s.size(),lent=t.size();
    vector<vector<int>>dp(lens+1,vector<int>(lent+1));
    
    for(int i=1;i<=lens;i++){
        for(int j=1;j<=lent;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
               
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string lcs="";
    int i=lens,j=lent;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs+=s[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<endl;
    // cout<<dp[lens][lent]<<endl;
}