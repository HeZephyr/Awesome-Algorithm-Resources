#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;

int n;
int a[maxn],dp[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int maxx=0;
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx<<endl;
    return 0;
}
