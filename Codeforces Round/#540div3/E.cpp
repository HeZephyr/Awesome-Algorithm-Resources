/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 18:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,k;
void solve(){
    ll ans = 1LL * k * (k - 1);
    if(ans < n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        int idx = 1,cnt = 0;
        while(true){
            for(int i = idx + 1; i <= k; ++ i){
                if(cnt < n){
                    cout << idx << " " << i << endl;
                    cnt ++;
                }
                if(cnt < n){
                    cout << i << " " << idx << endl;
                    cnt ++;
                }
                if(cnt == n)break;
            }
            idx ++;
            if(cnt == n){
                break;
            }
        }
    }
}
int main(){
    cin >> n >> k;
    solve();
    return 0;
}