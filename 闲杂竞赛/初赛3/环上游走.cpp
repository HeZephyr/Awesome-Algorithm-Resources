/**
  *@filename:环上游走
  *@author: pursuit
  *@created: 2021-08-07 15:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
int ans;
int cnt[81];
void dfs(int pos,int i){
    if(i == n){
        bool flag = false;
        for(int j = 1; j <= n; ++ j){
            if(cnt[j] != 1)flag = true;
        }
        if(!flag)ans++;
        return;
    }
    for(int op = 0; op < 2; ++ op){
        int x = pos;
        if(op == 0){
            x += i;
        }
        else{
            x -= i;
        }
        if(x > n){
            x -= n;
        }
        else if(x < 1){
            x += n;
        }
        if(cnt[x]){
            continue;
        }
        //cout << pos << "->" << x << endl;
        cnt[x] ++;
        dfs(x,i + 1);
        cnt[x] --;
    }
}
void solve(){
    memset(cnt,0,sizeof(cnt));
    cnt[1] ++;
    dfs(1,1);
    cout << ans << endl;
}
int main(){ 
    int t;
    cin >> t;
    while(t -- ){
        ans = 0;
        cin >> n;
        solve();
    }
    return 0;
}