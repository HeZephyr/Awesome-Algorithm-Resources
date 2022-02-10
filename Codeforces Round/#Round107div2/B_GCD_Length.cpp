/**
  *@filename:B_GCD_Length
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 13:59
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,a,b,c;
void solve(){
    ll x=1,y=0;
    for(int i=1;i<a;i++){
        x*=10;//构造x。
    }
    for(int i=1;i<=b-c+1;i++){
        y=y*10+1;
    }
    for(int i=1;i<=c-1;i++){
        y*=10;
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        solve();
    }
    return 0;
}