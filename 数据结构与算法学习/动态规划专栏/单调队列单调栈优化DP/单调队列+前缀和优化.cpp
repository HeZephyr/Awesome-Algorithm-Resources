/**
  *@filename:单调栈+前缀和优化
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-03 08:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,s[N],q[N];//维护一个单调递增的前缀和队列。
void solve(){
    int res = -0x3f3f3f3f,st = 0,ed = -1,l,r;
    q[++ ed] = 0;
    for(int i = 1;i <= n; ++ i){
        int sum = s[i] - s[q[st]];
        if(sum > res){
            res = sum;
            l = q[st] + 1;
            r = i;
        }
        while(st <= ed &s[q[ed]] > s[i]){
            ed --;
        }
        q[++ ed] = i;
    }
    if(res < 0){
        res = 0,l = 1,r = n;
    }
    printf("%d %d %d\n",res,s[l] - s[l - 1],s[r] - s[r - 1]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    solve();
    return 0;
}