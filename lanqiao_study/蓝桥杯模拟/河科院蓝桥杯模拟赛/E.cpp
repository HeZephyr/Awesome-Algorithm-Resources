#include<iostream>

using namespace std;

typedef long long ll;
const int maxn=20210411+10;
const ll mod=1e9+7;
//n层大等边三角形所含有的等边三角形为：n*(n+1)*(n+2)*(n+3)/24，利用Python解决。
ll n=20210411;
ll dao[maxn];
void init(){
    //维护到三角形的个数。
    dao[1]=0,dao[2]=1;
    for(int i=3;i<=n;i++){
        dao[i]=(dao[i-2]+i-1)%mod;
    }
}
int main(){
    init();
    ll ans=0;
    for(ll i=1;i<=n;i++){
        //先计算正三角形的贡献。
        ans=(ans+(i+1)*i/2)%mod;
        //再计算倒三角形的贡献。
        ans=(ans+dao[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}