/**
  *@filename:修剪草坪
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 12:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,k,st,ed;
ll sum[N],f[N];//我们知道在前面的题目中，都是选，而这里则是不选，那么我们则可以定义
//f[i]表示前i个奶牛符合条件，且不选第i只奶牛的最大效率，由于不能安排超过k只连续的奶牛，
//所以在i - m到i - 1之间必有一只奶牛没有选择，则f[i] = min(f[j]) + sum[i - 1] - sum[j];i - m <= j <=  i - 1;
ll q[N];//单调队列。
void solve(){
    //由于是求最大值，所以我们是维护一个单调递减队列。
    st = 0,ed = -1;
    q[++ ed] = 0;
    for(int i = 1; i <= n + 1; ++ i){
        //注意，这里我们延申到n + 1，这样最大效率就是f[n + 1];
        //剔除过期元素。
        while(st <= ed && i - k - 1> q[st])st ++;
        f[i] = f[q[st]] + sum[i - 1] - sum[q[st]];
        //维护单调递减队列。
        while(st <= ed && f[q[ed]]  + sum[i] - sum[q[ed]] <= f[i])ed --;//注意这里更新还需要考虑到后者。
        q[++ ed] = i;
    }
    printf("%lld", f[n + 1]);
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    solve();
    return 0;
}