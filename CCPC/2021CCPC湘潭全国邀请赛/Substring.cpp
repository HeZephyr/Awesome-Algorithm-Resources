/**
  *@filename:Substring
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 19:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int k;
string s;
int cnt[27];
bool check(){
    for(int i = 0; i < 27; ++ i){
        if(cnt[i] > k){
            //cout << 'a' + i << " " << cnt[i] << endl;
            return false;
        }
    }
    return true;
}
void solve(){
    memset(cnt,0,sizeof(cnt));
    int l = 0, r = 0, n = s.size();
    int maxx = 0;
    while(l < n){
        while(r < n){
            cnt[s[r] - 'a'] ++;
            if(!check()){
                cnt[s[r] - 'a'] --;
                break;
            }
            r ++;
        }
        maxx = max(maxx, r - l);
        //cout << l << " " << r << endl;
        cnt[s[l] - 'a'] --;
        l ++;
    }
    cout << maxx << endl;
}
int main(){
    while(cin >> k >> s)
        solve();
    return 0;
}