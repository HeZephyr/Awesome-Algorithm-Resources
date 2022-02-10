/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 08:25
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,h,w,n;
void solve(){
    int cnt = 1;
    while(w % 2 == 0){
        cnt *= 2;
        w /= 2;
    }
    while(h % 2 == 0){
        cnt *= 2;
        h /= 2;
    }
    //cout << cnt << endl;
    if(cnt >= n){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> w >> h >> n;
        solve();
    }
    return 0;
}