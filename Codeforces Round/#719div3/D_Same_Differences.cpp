/**
  *@filename:D_Same_Differences
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 22:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int t,n,a[maxn];
map<int,int> p;
void solve(){
    ll ans=0;
    //aj-j=ai-i;
    for(int i=1;i<=n;i++){
        ans+=p[a[i]-i];
        p[a[i]-i]++;
    }
    cout<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        p.clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }
    return 0;
}