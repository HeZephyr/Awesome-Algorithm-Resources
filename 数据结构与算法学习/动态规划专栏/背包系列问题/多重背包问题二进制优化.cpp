#include<bits/stdc++.h>

using namespace std;

const int maxn=2e4+10;

//我们其实还是将多重背包转化为01背包问题，只不过如果我们用1个1个这样分的话就太浪费空间了。
//我们知道一个整数可以被分解为2的次方之和。所以我们可以对这个整数进行分解，这样我们总能确保这些状态都处理到。
//复杂度为O(N*log(S)*m)
int n,m;
int v[maxn],w[maxn],s[maxn];
int cnt;
int dp[maxn];
int main(){
    cin>>n>>m;
    cnt=1;
    int a,b,c;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        //分组处理。
        int s=1;
        while(s<=c){
            v[cnt]=s*a;
            w[cnt]=s*b;
            c-=s;
            s*=2;
            cnt++;
        }
        if(c>0){
            //将剩下的未分组的分组。
            v[cnt]=c*a;
            w[cnt]=c*b;
            cnt++;
        }
    }
    //处理完之后就可以利用01背包问题来写了。
    for(int i=1;i<=cnt;i++){
        for(int j=m;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}