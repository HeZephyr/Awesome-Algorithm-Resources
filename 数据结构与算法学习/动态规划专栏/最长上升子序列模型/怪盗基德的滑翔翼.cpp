#include<bits/stdc++.h>

using namespace std;

const int maxn=110;

int t,n,h[maxn];
int dp[maxn];
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=1;i<=n;i++)cin>>h[i];
            int maxx=0;
            //可以选择方向，我们可以逆着dp。
            for(int i=1;i<=n;i++){
                dp[i]=1;
                for(int j=1;j<i;j++){
                    if(h[i]<h[j]){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
                maxx=max(maxx,dp[i]);
            }
            for(int i=n;i>=1;i--){
                dp[i]=1;
                for(int j=n;j>i;j--){
                    if(h[i]<h[j]){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
                maxx=max(dp[i],maxx);
            }
            cout<<maxx<<endl;
        }
    }
    return 0;
}