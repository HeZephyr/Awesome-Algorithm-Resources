/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 20:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n,k;
map<ll,int> p;
void solve(){
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            p[i*i+i+j*j+j]++;
        }
    }
    ll ans=0;
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            ans+=p[(i*i+i+j*j+j)*k];
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        p.clear();
        solve();
    }
    return 0;
}