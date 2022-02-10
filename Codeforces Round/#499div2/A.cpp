/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-27 19:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
char s[N];
int cnt[26], res;
void dfs(int idx, int ans, int cnt1){
    if(idx >= 26){
        if(cnt1 == k)res = min(res, ans);
        return;
    }
    if(cnt[idx])dfs(idx + 2, ans + idx + 1, cnt1 + 1);
    dfs(idx + 1, ans, cnt1);
}
void solve(){
    for(int i = 0; i < n; ++ i)cnt[s[i] - 'a'] ++;
    bool flag = false;
    res = INF;
    dfs(0, 0, 0);
    if(res == INF)puts("-1");
    else printf("%d\n", res);
}
int main(){	
    cin >> n >> k;
    cin >> s;
    solve();
    return 0;
}