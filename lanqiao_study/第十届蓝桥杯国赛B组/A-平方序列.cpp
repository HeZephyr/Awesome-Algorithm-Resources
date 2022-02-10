/**
  *@filename:A-平方序列
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 16:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

ll x,y;
void solve(){
}
int main(){
    ll i = 2020;
    while(true){
        ll temp = 2 * i * i - 2019 * 2019;
        if(sqrt(temp) * sqrt(temp) ==  temp){
            printf("%lld\n",int(sqrt(temp)) + i);//4040
            break;
        }
    }
    solve();
    return 0;
}