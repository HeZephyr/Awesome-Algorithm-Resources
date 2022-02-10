#include<bits/stdc++.h>
#define fi first
#define se second
#define S s
#define debug cout<<"I AM HERE"<<endl;
using namespace std;
typedef long long ll;
const int maxn=1e7+5,inf=0x3f3f3f3f,mod=998244353;
int n;
ll fac[40];
ll dp[maxn][2];
signed main(){
    fac[0]=fac[1]=1;
    for(int i=2;i<=35;i++){
        fac[i]=fac[i-1]+fac[i-2];
    }
    dp[0][0]=1;
    int id=1;
    for(int i=1;i<=1e7;i++){
        if(i>=fac[id+1]){
            id++;
        }
        if(i-fac[id-1]>=fac[id-1]){
            dp[i][0]=fac[id-1]*dp[i-fac[id-1]][0]%mod;
        }else{
            dp[i][0]=(fac[id-1]*dp[i-fac[id-1]][0]+fac[id-1]*dp[i-fac[id-1]][1])%mod;
        }

        if(i-fac[id]>=fac[id]){
            dp[i][1]=fac[id]*dp[i-fac[id]][0]%mod;
        }else{
            dp[i][1]=(fac[id]*dp[i-fac[id]][0]+fac[id]*dp[i-fac[id]][1])%mod;
        }
    }
    int _;scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        printf("%lld\n",(dp[n][0]+dp[n][1])%mod);
    }
    return 0;
}