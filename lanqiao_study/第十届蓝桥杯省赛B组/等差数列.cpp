/**
  *@filename:等差数列
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 00:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;
const int inf=0x3f3f3f3f;

int n;
ll a[maxn];
void solve(){
    sort(a,a+n);
    ll minn=inf;
    for(int i=0;i<n-1;i++){
        minn=min(minn,a[i+1]-a[i]);
    }
    if(minn==0){
        //特判为0的时候。
        cout<<n<<endl;
        return;
    }
    //根据公式a1+(n-1)*d=a[n-1]
    cout<<(a[n-1]-a[0])/minn+1<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        solve();
    }
    return 0;
}