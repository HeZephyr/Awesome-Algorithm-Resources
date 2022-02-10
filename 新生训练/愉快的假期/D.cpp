#include<bits/stdc++.h>

using namespace std;

int t,n;
int dp[42];
void init(){
    dp[1]=1;
    for(int i=2;i<=40;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}
int main(){
    init();
    while(cin>>t){
        while(cin>>n){
            cout<<dp[n]<<endl;
        }
    }
    return 0;
}