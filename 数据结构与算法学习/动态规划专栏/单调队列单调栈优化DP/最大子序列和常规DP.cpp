/**
  *@filename:最大子序列和常规DP
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-03 08:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n,a[N];
int f[N];//f[i]表示以i结尾的最大子序列和。
void solve(){
    int res = -0x3f3f3f3f,st,ed,pre = 1;
    for(int i = 1; i <= n; ++ i){
        f[i] = max(a[i],f[i - 1] + a[i]);
        if(f[i - 1] < 0){
            pre = i;
        }
        if(res < f[i]){
            res = f[i];
            st = pre,ed = i;
        }
    } 
    if(res < 0){
        res = 0,st = 1,ed = n;
    }
    printf("%d %d %d\n",res,a[st],a[ed]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}