/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-19 13:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,flag[100];
//3位数以上的一定满足。
ll l,r;
bool check(string x){
    if(x.size() == 1){
        if((x[0] - '0') % 3 == 0){
            return true;
        }
        return false;
    }
    else{
        if((x[0] - '0') % 3 == 0 || (x[1] - '0') % 3 == 0 || ((x[0] - '0') * 10 + (x[1] - '0')) % 3 == 0){
            return true;
        }
        return false;
    }
}
void init(){
    for(int i = 1; i < 100; ++ i){
        if(check(to_string(i))){
            flag[i] = true;
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> l >> r;
        ll ans = 0;
        if(l >= 100){
            ans += r - l + 1;
        }
        else if(r >= 100){
            ans += r - 99;
        }
        for(int i = l; i <= r && i < 100; ++ i){
            if(flag[i])ans ++;
        }
        cout << ans << endl;
    }
    //solve();
    return 0;
}