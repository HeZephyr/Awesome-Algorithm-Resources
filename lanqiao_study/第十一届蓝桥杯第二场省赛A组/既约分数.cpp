/**
  *@filename:既约分数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 12:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int gcd(int n,int m){
    return n%m?gcd(m,n%m):m;
}
void solve(){
    ll ans=0;
    for(int i=1;i<=2020;i++){
        for(int j=1;j<=2020;j++){
            if(gcd(i,j)==1)ans++;
        }
    }
    cout<<ans<<endl;//2481215
}
int main(){
    solve();
    return 0;
}