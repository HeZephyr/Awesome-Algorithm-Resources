/**
  *@filename:烽火传递
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-03 20:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,m,a[N];
int f[N];//f[i]表示前i座符合条件，且第i座已经点燃了的最小代价。
//则我们知道在前i座中，该点管控的范围我们不清楚，
//但我们知道的是，在i - m 到 i - 1中，至少有一座已经点燃了，设为j。
//所以我们状态转移方程为f[i] = min(f[j]) + a[i];//i - m <= j <= i - 1;
int st,ed,q[N];
void solve(){
    st = 0,ed = -1;
    f[++ ed] = 0;//第0座的代价为0.
    for(int i = 1; i <= n; ++ i){
        //剔除过期元素。
        while(st <= ed && i - m > q[st])st ++;
        f[i] = f[q[st]] + a[i];
        //维护单调队列。
        while(st <= ed && f[q[ed]] >= f[i])ed --;
        q[++ed] = i;
    }
    int minn = 0x3f3f3f3f;
    for(int i = n - m + 1; i <= n; ++ i){
        //答案在这里产出。
        minn = min(minn,f[i]);
    }
    printf("%d\n",minn);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}