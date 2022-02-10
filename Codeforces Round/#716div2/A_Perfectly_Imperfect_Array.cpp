/**
  *@filename:A_Perfectly_Imperfect_Array
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-19 21:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
int a[maxn];
void solve(){
    bool flag=false;
    for(int i=1;i<=n;i++){
        int temp=sqrt(a[i]);
        if(temp*temp!=a[i]){
            flag=true;
            break;
        }
    }
    if(flag)puts("YES");
    else puts("NO");
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        //若全是乘积的平方则不可能。
        solve();
    }
    return 0;
}