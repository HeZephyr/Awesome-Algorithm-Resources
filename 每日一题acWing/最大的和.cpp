/**
  *@filename:最大的和
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-11 19:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k;
int a[maxn],b[maxn];
void solve(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(b[i])ans+=a[i],a[i]=0;
    }
    //对于不可选的，我们枚举我们需要的即可。
    int l=1,r=1;
    ll res=0,maxx=0;
    while(l<=n){
        while(r-l<k&&r<=n)res+=a[r],r++;
        if(r-l==k){
            maxx=max(maxx,res);
        }
        res-=a[l];
        l++;
    }
    cout<<ans+maxx<<endl;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    solve();
    return 0;
}