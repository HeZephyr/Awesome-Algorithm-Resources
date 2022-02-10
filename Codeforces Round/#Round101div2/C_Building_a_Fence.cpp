/**
  *@filename:C_Building_a_Fence
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 18:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,k,h[N];
void solve(){
    bool flag = true;
    int l = h[1],r = h[1];
    for(int i = 2; i <= n; ++ i){
        l = max(l - k + 1,h[i]);//最低。最大下界。
        r = min(r + k - 1,h[i] + k - 1);//最小上界。
        if(l > r){
            flag = false;
            break;
        }
    }
    if(h[n] < l || h[n] >r){
        flag = false;
    }
    printf("%s\n",flag ? "YES" : "NO");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &h[i]);
        }
        solve();
    }
    return 0;
}