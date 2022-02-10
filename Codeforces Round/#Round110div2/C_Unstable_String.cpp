/**
  *@filename:C_Unstable_String
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 22:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
void solve(){
    //bef0表示无法满足奇数位是1，偶数位是0的前一个位置。bef1则相反。
    int bef0 = -1,bef1 = -1;
    ll ans = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '?'){
            ans += max(i - bef0,i - bef1);
        }
        else if(s[i] - '0' == i % 2){
            //说明不满足bef0.则上一个位置 + 1到i这里可以构成奇数位为1，偶数位为0的漂亮串。
            ans += i - bef0;
            bef1 = i;
        }
        else{
            //说明不能满足bef1.
            ans += i - bef1;
            bef0 = i;
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}