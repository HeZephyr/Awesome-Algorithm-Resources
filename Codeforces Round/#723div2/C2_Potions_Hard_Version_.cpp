/**
  *@filename:C1_Potions_Easy_Version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 22:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,a[N];
priority_queue<int,vector<int>,greater<int> > q;
void solve(){
    int res = 0;
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        if(ans + a[i] < 0){
            if(q.empty() || a[i] <= q.top()){
                continue;
            }
            else{
                ans = ans - q.top() + a[i];
                q.pop();
                q.push(a[i]);
            }
        }
        else{
            res ++;
            ans += a[i];
            if(a[i] < 0){
                q.push(a[i]);
            }
        }
    }
    printf("%d\n",res);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}