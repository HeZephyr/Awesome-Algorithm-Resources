/**
  *@filename:自描述序列
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 12:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

ll n,g[maxn];
//在g数组中有g[i]个i。利用这个求前缀和就可以达到目的。
void init(){
    g[1]=1,g[2]=2;
    for(int i=2,j=2;i<maxn;i++){
        for(int k=0;k<g[i]&&j<maxn;k++)g[j++]=i;
    }
}
void solve(){
    ll s,t;
    s=t=0;
    for(ll i=1;;i++){
        s+=i*g[i];//过渡完直接跳到下一个。
        if(s>=n){
            //说明当前已经过了n。
            s-=i*g[i];//先减掉当前加过头的。
            cout<<t+(n-s+i-1)/i<<endl;//t为当前开头的值。
            break;
        }
        t+=g[i];//t获取的就是每次出现的值。
    }
}
int main(){
    init();
    while(cin>>n)
        solve();
    return 0;
}