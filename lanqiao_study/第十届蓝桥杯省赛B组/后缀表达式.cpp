/**
  *@filename:后缀表达式
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 00:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int n,m,len;
ll a[maxn];
void solve(){
    ll sum=0;
    if(m==0){
        for(int i=0;i<len;i++){
            sum+=a[i];
        }
        cout<<sum<<endl;
        return;
    }
    sort(a,a+len);
    sum+=a[len-1],sum-=a[0];
    for(int i=1;i<len-1;i++){
        sum+=abs(a[i]);
    }
    cout<<sum<<endl;
}
int main(){
    while(cin>>n>>m){
        len=n+m+1;
        for(int i=0;i<len;i++){
            cin>>a[i];
        }
        solve();
    }
    return 0;
}