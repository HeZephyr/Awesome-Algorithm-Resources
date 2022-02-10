/**
  *@filename:B_The_Great_Hero
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-01 16:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
ll A,B,a[N],b[N];
ll maxx;
void solve(){
    bool flag = false;
    for(int i = 1; i <= n; ++ i){
        int temp = b[i] / A + (b[i] % A != 0);
        B -= a[i] * temp;
    }
    B += maxx;
    if(B <= 0)flag = true;
    printf("%s\n",flag ? "NO" : "YES");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        maxx = 0;
        scanf("%lld%lld%d", &A, &B, &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &a[i]);
            maxx = max(a[i],maxx);//存储其中的最大伤害。
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &b[i]);
        }
        solve();
    }
    return 0;
}