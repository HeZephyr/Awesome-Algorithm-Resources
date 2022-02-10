/**
  *@filename:B_Array_Reodering
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 22:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    vector<int> result;
    result.push_back(0);
    for(int i = 1; i <=  n; ++ i){
        if(a[i] % 2 == 0)result.push_back(a[i]);
    }
    for(int i = 1; i <=  n; ++ i){
        if(a[i] & 1)result.push_back(a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            if(__gcd(result[i],2 * result[j]) > 1){
                ans ++ ;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}