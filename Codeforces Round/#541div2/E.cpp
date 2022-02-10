/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-09-09 21:10
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s[N];
//abc * de = deadebdecde
//计算s1 * s2 * s3 * ... * sn;
int cal(char c, int idx){
    int res = 0, cnt = 0;
    for(int i = 0; i < s[idx].size(); ++ i){
        if(s[idx][i] == c){
            ++ cnt;
        }
        else{
            cnt = 0;
        }
        res = max(res, cnt);
    }
    return res;
}
bool check(char c, int idx){
    for(auto x : s[idx]){
        if(c != x)return false;
    }
    return true;
}
int back(char c, int idx){
    int cnt = 0;
    for(int i = s[idx].size() - 1; i >= 0; -- i){
        if(s[idx][i] == c)++ cnt;
        else break;
    }
    return cnt;
}
int front(char c, int idx){
    int cnt = 0;
    for(int i = 0; i < s[idx].size(); ++ i){
        if(s[idx][i] == c)++ cnt;
        else break;
    }
    return cnt;
}
void solve(){
    ll res = 0;
    for(char c = 'a'; c <= 'z'; ++ c){
        ll cnt = 0;
        for(int i = 1; i <= n; ++ i){
            if(cnt == 0){
                cnt = cal(c, i);
            }
            else{
                //判断是否全是a。
                if(check(c, i)){
                    cnt = cnt + (cnt + 1) * s[i].size();
                }
                else{
                    //否则取最大值。
                    cnt = max(cal(c, i), 1 + back(c, i) + front(c, i));
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
}
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i];
    }
    solve();
    return 0;
}