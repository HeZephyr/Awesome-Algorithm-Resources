/**
  *@filename:A_Nezzar_and_Colorful_Balls
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-27 13:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    int maxx = 0;
    int pre = -1;
    int cnt = 1;
    for(int i = 1; i <= n; ++ i){
        if(a[i] == pre){
            cnt ++;
        }
        else{
            maxx = max(maxx,cnt);
            cnt = 1;
            pre = a[i];
        }
    }
    maxx = max(maxx,cnt);
    cout << maxx << endl;
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