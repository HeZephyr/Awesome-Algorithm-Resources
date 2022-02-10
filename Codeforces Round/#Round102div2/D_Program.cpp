/**
  *@filename:D_Program
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 14:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,m,l,r;
int pre[N],pre_min[N],pre_max[N];
int suf[N],suf_min[N],suf_max[N];
char s[N];//操作指令。
int now;
void solve(){
    int now = 1;
    for(int i = 1; i <= n; ++ i){
        now = 1;
        if(s[i] == '-'){
            now = -1;
        }
        pre[i] = pre[i - 1] + now;
        pre_min[i] = min(pre_min[i - 1],pre[i]);
        pre_max[i] = max(pre_max[i - 1],pre[i]);
    }
    suf[n + 1] = suf_min[n + 1] = suf_max[n + 1] = 0;
    for(int i = n; i >= 1; -- i){
        now = 1;
        if(s[i] == '-'){
            now = -1;
        }
        suf[i] = suf[i + 1] + now;
        suf_min[i] = min(0,suf_min[i + 1] + now);
        suf_max[i] = max(0,suf_max[i + 1] + now);
    }
    while(m -- ){
        cin >> l >> r;
        int maxx = pre_max[l - 1],minn = pre_min[l - 1];
        maxx = max(maxx,suf_max[r + 1] + pre[l - 1]);
        minn = min(minn,suf_min[r + 1] + pre[l - 1]);
        cout << maxx - minn + 1 << endl;
    } 
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        cin >> s + 1;
        solve();
    }
    return 0;
}