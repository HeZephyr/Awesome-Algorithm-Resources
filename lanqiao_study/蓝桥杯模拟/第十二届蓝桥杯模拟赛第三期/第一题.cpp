/**
  *@filename:第一题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 14:01
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
    int ans=0;
    for(int i=1;i<=2020;i++){
        if(gcd(i,2020)==1)ans++;
    }
    cout<<ans<<endl;//800
}
int main(){
    solve();
    return 0;
}