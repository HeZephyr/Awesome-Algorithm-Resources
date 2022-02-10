/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 09:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 998244353;

int n,a[N];
ll quick_pow(ll n,ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    //计算有多少块。
    //我们可以先记录在每个下标中出现的最后位置。
    map<int,int> p;
    int last[N];//last[i]表示在第i个元素中出现的最后位置。
    for(int i = n; i >= 1; -- i){
        if(!p[a[i]]){
            p[a[i]] = i;
        }
        last[i] = p[a[i]];
    }
    //然后我们计算有多少个块。
    int ans = 0,st = 1;
    while(st <= n){
        int ed = last[st];
        ans ++;
        //更新下一个块。
        for(int i = st; i <= last[ed] && i <= n; ++ i){
            //当跳出循环时，说明块中的最后一个元素就是最后一个元素。即块中出现的元素不会在下一个块中出现。
            ed = max(ed,last[i]);
        }
        st = ed + 1;
    }
    printf("%lld\n", quick_pow(2,ans - 1));
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}