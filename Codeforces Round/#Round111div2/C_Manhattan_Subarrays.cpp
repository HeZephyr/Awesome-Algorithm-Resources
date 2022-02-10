/**
  *@filename:C_Manhattan_Subarrays
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 21:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
bool check(int l,int r){
    for(int i = l; i <= r; ++ i){
        for(int j = i + 1; j <= r; ++ j){
            for(int k = j + 1; k <= r; ++ k){
                if((a[i] <= a[j] && a[j] <= a[k]) || (a[i] >= a[j] && a[j] >= a[k])){
                    return false;
                }
            }
        }
    }
    return true;
}
void solve(){
    ll ans = 0;
    //枚举区间[l,r]，判断[l,r]是不是递增或者递减的，
    for(int l = 1; l <= n; ++ l){
        if(l + 1 <= n)ans += 2;//因为长度为1和2的子数组也算是good。
        else ans += 1;
        for(int len = 3; len + l <= n + 1; ++ len){
            if(check(l,l + len - 1))ans ++;
            else{
                break;//不符合，那么接下来再怎么样也不符合，直接退出。
            }
        }
    }
    printf("%lld\n", ans);
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