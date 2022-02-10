/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 08:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll p,q;
//x是p的因子，q不是x的倍数。
void solve(){
    //将q的质因子提取出来即可。
    vector<int> num;
    ll temp = q;
    for(int i = 2; i * i <= temp; ++ i){
        if(temp % i == 0){
            num.push_back(i);//获取它的因子。
            while(temp % i == 0)temp /= i;
        }
    }
    if(temp > 1)num.push_back(temp);
    //枚举答案。
    ll res = 0,ans = 0;
    for(auto &x : num){
        res = p;
        while(res % q == 0)res /= x;
        ans = max(ans,res);
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> p >> q;
        solve();
    }
    return 0;
}