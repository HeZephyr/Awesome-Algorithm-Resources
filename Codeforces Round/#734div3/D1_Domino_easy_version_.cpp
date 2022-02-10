/**
  *@filename:D1_Domino_easy_version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 23:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,m,k;
void solve(){
    if(n & 1)swap(n,m);
    if(k == 0){
        cout << "YES" << endl;
        return;
    }
    cout << n << " " << m << endl;
    if(n % 2 == 0){
        int temp = k / (m / 2);
        if(m % 2 && temp != n){
            cout << "NO" << endl;
        }
        else{
            if((n - temp) % 2){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> m >> k;
        solve();
    }
    return 0;
}