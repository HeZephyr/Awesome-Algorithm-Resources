/**
  *@filename:B_New_Year_s_Number
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 09:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    //假设n = a * 2021 + b * 2020，我们可以去枚举a 和 b。
    for(int i = 0; i * 2021 <= n; ++ i){
        int j = n - i * 2021;
        if(j % 2020 == 0){
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}