/**
  *@filename:整除序列
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 18:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n;
ll a[maxn];
void solve(){
    int index=0;
    while(n>0){
        a[index++]=n;
        n/=2;
    }
    for(int i=0;i<index;i++){
        cout<<a[i];
        i==index-1?cout<<endl:cout<<" ";
    }
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}