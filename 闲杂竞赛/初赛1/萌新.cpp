/**
  *@filename:萌新
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 14:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll a,b;
void solve(){
    if(a == b){
        if(a == 1){
            cout << "-1 -1" << endl;
        }
        else{
            cout << 2 << " " << b << endl;
        }
        return;
    }
    ll temp = max(a,b) - min(a,b);
    ll maxx = temp;
    ll minn = maxx;
    ll temp1 = sqrt(temp) + 1;
    for(int i = 2; i <= temp1; ++ i){
        if(temp % i == 0){
            minn = i;
            break;
        }
    }
    if(maxx == 1){
        cout << "-1 -1" << endl;
    }
    else{
        cout << minn << " " << maxx << endl;
    }

}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b;
        solve();
    }
    return 0;
}