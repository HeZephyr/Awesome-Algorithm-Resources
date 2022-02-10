/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 10:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,a[N];
ll pre_even[N],pre_odd[N];
void solve(){
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        if(pre_odd[i - 1] + pre_even[n] - pre_even[i] == pre_even[i - 1] + pre_odd[n] - pre_odd[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        if(i & 1){
            pre_odd[i] = pre_odd[i - 1] + a[i];
            pre_even[i] = pre_even[i - 1];
        }
        else{
            pre_odd[i] = pre_odd[i - 1];
            pre_even[i] = pre_even[i - 1] + a[i];
        }
    }
    solve();
    return 0;
}