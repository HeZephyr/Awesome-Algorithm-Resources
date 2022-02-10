/**
  *@filename:A_Odd_Set
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 21:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        int odd = 0;
        for(int i = 1; i <= 2 * n; ++ i){
            cin >> a[i];
            if(a[i] & 1){
                odd ++;
            }
        }
        if(odd == n){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    solve();
    return 0;
}