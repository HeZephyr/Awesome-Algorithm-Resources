/**
  *@filename:F_Interesting_Function
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 23:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
int l,r;
void solve(){
    ll cnt0 = 0,cnt1 = 0;
    string temp1 = to_string(l);
    int k = 1;
    for(int i = 0; i < temp1.size(); ++ i){
        cnt0 += l / k;
        k *= 10;
    }
    temp1 = to_string(r);
    k = 1;
    for(int i = 0; i < temp1.size(); ++ i){
        cnt1 += r / k; 
        k *= 10;
    }
    printf("%lld\n",cnt1 - cnt0);
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> l >> r;
        solve();
    }
    return 0;
}