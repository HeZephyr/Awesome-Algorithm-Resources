/**
  *@filename:约瑟夫环
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-08 16:33
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

int n,k;
int f[maxn];
void solve(){
    f[1]=0;
    for(int i=2;i<=n;i++){
        f[i]=(f[i-1]+k)%i;
    }
    cout<<f[n]+1<<endl;
}
int main(){
    cin>>n>>k;
    solve();
    return 0;
}