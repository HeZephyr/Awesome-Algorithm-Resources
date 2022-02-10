/**
  *@filename:A_Shifting_Stacks
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-04 19:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,h[N];
ll sum;
void solve(){
    ll temp = 0;
    bool flag = true;
    for(int i = 0 ; i < n; ++ i){
        sum += h[i];
        temp += i;
        if(sum < temp){
            flag = false;
            break;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        sum = 0;
        for(int i = 0; i < n; ++ i){
            cin >> h[i];
        }
        solve();
    }
    return 0;
}