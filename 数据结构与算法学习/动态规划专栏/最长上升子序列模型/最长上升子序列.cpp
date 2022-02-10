#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;
int n;
int a[maxn];
int dp[maxn];//dp[i]表示的就是在前i个数中以a[i]作为结尾的的最长上升子序列
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;//仅以自己作为子序列，自然为1.
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        //搜索完之后更新maxx.
        maxx=max(dp[i],maxx);
    }
    cout<<maxx<<endl;
    return 0;
}