/**
  *@filename:递增三元组双指针
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 11:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int a[maxn],b[maxn],c[maxn];
int pre_cnta[maxn],pre_cntc[maxn];
void solve(){
    for(int i=1;i<maxn;i++){
        pre_cnta[i]=pre_cnta[i-1]+pre_cnta[i];
    }
    for(int i=1;i<maxn;i++){
        pre_cntc[i]=pre_cntc[i-1]+pre_cntc[i];
    }
    ll ans=0;
    //pre_cntc[i]表示的是小于等于i的所有数。
    for(int i=0;i<n;i++){
        ans+=(ll)pre_cnta[b[i]-1]*(pre_cntc[maxn-1]-pre_cntc[b[i]]);
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        memset(pre_cnta,0,sizeof(pre_cnta));
        memset(pre_cntc,0,sizeof(pre_cntc)); 
        for(int i=0;i<n;i++){
            cin>>a[i];
            //统计a[i]出现的次数。
            pre_cnta[a[i]]++;
        }
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++){
            cin>>c[i];
            //统计c[i]出现的次数。
            pre_cntc[c[i]]++;
        }
        solve();
    }
    return 0;
}