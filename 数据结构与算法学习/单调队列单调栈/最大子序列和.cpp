/**
  *@filename:最大子序列和
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-02 17:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n,a[N];
void solve(){
    int sum = 0,res = - 0x3f3f3f3f,st,ed,pre = 1;
    for(int i = 1; i <= n; ++ i){
        sum += a[i];
        if(sum > res){
            res = sum,ed = i,st = pre;
        }
        if(sum < 0){
            sum = 0,pre = i + 1;
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