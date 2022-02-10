/**
  *@filename:B_Napoleon_Cake
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-11 10:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
int st[N],sum[N];//对于区间需改，我们利用差分数组能够有利的实现。c[i] = sum[i]  - sum[i - 1];
void solve(){
    memset(st,0,sizeof(st));
    memset(sum,0,sizeof(sum));
    int l,r;
    for(int i = 1; i <= n; ++ i){
        r = i,l = i - a[i] + 1;
        if(l < 1){
            l = 1;
        }
        st[l] ++,st[r + 1] --;
    }
    for(int i = 1; i <= n; ++ i){
        sum[i] = sum[i - 1] + st[i];
        printf("%d ",sum[i] != 0 ? 1 : 0);
    }
    printf("\n");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}