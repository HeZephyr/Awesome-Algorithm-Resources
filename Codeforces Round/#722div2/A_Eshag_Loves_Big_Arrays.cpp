/**
  *@filename:A_Eshag_Loves_Big_Arrays
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
int a[N];
int x;
void solve(){
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(a,0,sizeof(a));
        for(int i = 1;i <= n; i++){
            cin >> x;
            a[x]++;
        }
        for(int i = 1; i <= 100 ;i++){
            if(a[i]){
                cout << n - a[i] << endl;
                break;
            }
        }
    }
    solve();
    return 0;
}