/**
  *@filename:1011
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 10:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
const int P = 998244353;
const ll INF = 1e9 + 10;

int t,n;
ll a[N],b[N];//存储最小的值
ll A[N],B[N];//存储最大的值。
void solve(){
    int m = 1;
    while(m < n){
        m <<= 1;
    }
    for(int i = n; i < m; ++ i){
        A[i] = B[i] = -INF;
        a[i] = b[i] = INF;
    }
    for(int i = 1; i < m; i <<= 1){
        for(int k = 0; k < n; ++ k){
            if(!(i & k)){
                //说明k的第i位不是0.
                A[k] = max(A[k], A[i ^ k]);
                B[k] = max(B[k], B[i ^ k]);
                a[k] = min(a[k], a[i ^ k]);
                b[k] = min(b[k], b[i ^ k]);
            }
        }
    }
    ll maxx = -1e18,ans = 0;
    for(int i = n - 1; i >= 0; -- i){
        maxx = max(maxx,A[i] * B[i]);
        maxx = max(maxx,A[i] * b[i]);
        maxx = max(maxx,a[i] * B[i]);
        maxx = max(maxx,a[i] * b[i]);
        ans = (ans + maxx % P) % P; 
    } 
    ans = (ans + P) % P;
    printf("%lld\n", ans);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 0; i < n; ++ i){
            scanf("%lld", &a[i]);
            A[i] = a[i];
        }
        for(int i = 0; i < n; ++ i){
            scanf("%lld", &b[i]);
            B[i] = b[i];
        }
        solve();
    }
    return 0;
}