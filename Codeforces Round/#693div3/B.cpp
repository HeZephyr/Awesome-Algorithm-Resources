/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 08:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[110];
int sum;
void solve(){
    if(sum & 1){
        puts("NO");
    }
    else{
        sum /= 2;
        sort(a + 1,a + 1 + n);
        for(int i = n; i >= 1; -- i){
            if(sum < a[i])break;
            sum -= a[i];
        }
        if(sum > 0 && sum != a[1]){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        sum = 0;
        for(int i = 1;i <= n; ++ i){
            cin >> a[i];
            sum += a[i];
        }
        solve();
    }
    return 0;
}