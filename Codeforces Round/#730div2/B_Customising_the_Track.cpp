/**
  *@filename:B_Customising_the_Track
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-07 22:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
ll sum,ans;
void solve(){
    ll avg = sum / n;
    ll temp = sum % n;
    cout << (n - temp) * temp << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        sum = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        solve();
    }
    return 0;
}