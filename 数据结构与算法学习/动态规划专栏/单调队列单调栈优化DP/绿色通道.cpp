/**
  *@filename:绿色通道
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 10:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50000 + 5;
const int P = 1e9+7;

int n,t,a[N];
int st,ed,q[N],f[N];//q为我们的单调队列，f[i]表示前i题符合条件且第i题完全做完。
bool check(int x){
    //x表示做题空缺的最小长度段，意味这在i前面的m段中至少有一题要做完。则状态转移方程为：
    //f[i] = min(f[j]) + a[i]; i - m <= j <= i - 1;
    memset(f,0,sizeof(f));
    st = 0,ed = -1;
    q[++ ed] = 0;
    for(int i  = 1; i <= n + 1; ++ i){
        //剔除过期元素。
        while(st <= ed && i - x - 1 > q[st])st ++;//注意这里是需要-x -1的，因为x代表间隔段。
        f[i] = f[q[st]] + a[i];
        //维护一个单调递增队列。
        while(st <= ed && f[q[ed]] >= f[i])ed --;
        q[++ ed] = i;
    }
    return f[n + 1] <= t;
}
void solve(){
    int l = 0,r = n,mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d\n",l);
}
int main(){
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}