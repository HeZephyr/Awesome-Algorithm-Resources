/**
  *@filename:B_Prinzessin_der_Verurteilung
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-06 22:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s;
bool change(string &s){
    int res = 0,len = s.size();
    s[len - 1] += 1;
    res = s[len - 1] > 'z' ? 1 : 0;
    int idx = len - 1;
    while(res){
        s[idx] = 'a';
        idx --;
        if(idx < 0){
            return false;
        }
        s[idx] += res;
        res = s[idx] > 'z' ? 1 : 0;
    }
    return true;
}
void solve(){
    string str[3] = {"a","aa","aaa"};
    string result;
    bool flag = false;
    while(true){
        for(int i = 0; i < 3; ++ i){
            do{
                if(s.find(str[i]) == s.npos){
                    result = str[i];
                    flag = true;
                    break;
                }
            }while(change(str[i]));
            if(flag)break;
        }
        if(flag)break;
    }
    cout << result << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}