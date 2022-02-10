/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 20:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 998244353;

int quick_pow(int n,int q){
    int ans=1;
    while(q){
        if(q&1)ans=ans*n%mod;
        n=n*n%mod;
        q>>=1;
    }
    return ans;
}
int n,m;
int a[maxn];
int x[maxn];
void solve(){
    vector<int> result(m);
    for(int i=0;i<m;i++){
        int ans=0;
        for(int j=0;j<=n;j++){
            ans=(ans+a[j]*quick_pow(x[i],j))%mod;
        }
        result[i]=ans;
    }
    for(int i=0;i<m;i++){
        cout<<result[i];
        i==m-1?cout<<endl:cout<<" ";
    }
}
int main(){
    while(cin>>n){
        for(int i=0;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>x[i];
        }
        solve();
    }
    return 0;
}