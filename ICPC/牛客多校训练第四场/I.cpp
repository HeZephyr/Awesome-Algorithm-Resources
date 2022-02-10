/**
  *@filename:I
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-26 13:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,a[N],b[N],c[N];
ll sum;//统计逆序对个数。
//利用树状数组统计逆序对。
int lowbit(int x){
    return x & (-x);
}
void add(int x){
    for(int i = x; i <= n; i += lowbit(i)){
        c[i] ++;
    }
}
int query(int x){
    int res = 0;
    for(int i = x; i >= 1; i -= lowbit(i)){
        res += c[i];
    }
    return res;
}
void solve(){
    sum = 1LL * n * (n - 1) / 2 - sum;//应有的逆序对。
    int idx = 1;
    while(idx < n){
        if(b[idx] > b[idx + 1])sum --,idx += 2;
        else idx ++;
    }
    printf("%lld\n", sum);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        sum += query(a[i]);
        add(a[i]);
        b[a[i]] = i;//记录其位置。
    }
    solve();
    return 0;
}