/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-21 15:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k;
char s[N];
bool vis[200];
void solve(){
    int l = 1,r = 1;
    ll ans = 0;
    while(l <= n){
        while(r <= n && vis[s[r]])r ++;
        //[l,r - 1]都是有效的。
        ans += 1LL * (r - l + 1) * (r - l) / 2;
        l = r;
        if(!vis[s[l]])l ++;
        r = l;
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> k >> s + 1;	
    char c;
    for(int i = 0; i < k; ++ i){
        cin >> c;
        vis[c] = true;
    }
    solve();
    return 0;
}