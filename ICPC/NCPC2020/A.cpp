/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-03 20:31
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int n;
ll a[N];
bool flag;
bool cal(int idx){
    string s = to_string(a[idx]);
    for(int i = 0; i < s.size(); ++ i){
        for(int j = 1; j < 11; ++ j){
            char pre = s[i];
            s[i] = (s[i] - '0' + j) % 10 + '0';
            if(i == 0 && s[i] == '0'){
                s[i] = pre;
                continue;
            }
            ll temp = stoll(s);
            if(idx - 1 >= 1 && temp < a[idx - 1]){
                a[idx] = temp;
                return true;
            }
            if(idx + 1 <= n && temp > a[idx + 1]){
                a[idx] = temp;
                return true;
            }
            s[i] = pre;
        }
    }
    return false;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(cal(i)){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i = 1; i <= n; ++ i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "impossible" << endl;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    solve();
    return 0;
}