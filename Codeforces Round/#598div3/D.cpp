/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 15:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
ll k;
string s;
queue<int> pos;
void solve(){
    while(!pos.empty())pos.pop();
    for(int i = 0; i < n; ++ i){
        if(s[i] == '0')pos.push(i);
    }
    //每次遇见0往前放。
    int last = 0;
    while(!pos.empty() && k > 0){
        int idx = pos.front();
        pos.pop();
        if(idx - last < k){
            k -= (idx - last);
        }
        else{
            last = idx - k;
            k = 0;
        }
        swap(s[last],s[idx]);
        last ++;
    }
    cout << s << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k >> s;
        solve();
    }
    return 0;
}