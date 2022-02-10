/**
  *@filename:I
  *@author: pursuit
  *@created: 2021-08-28 12:07
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char s[N];
int pre[N][4];
map<char,int> p;
void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < 4; ++ j){
            pre[i][j] = pre[i - 1][j];
        }
        ++ pre[i][p[s[i]]];
    }
    for(int i = 2; i <= n; ++ i){
        //cout << pre[i][0] << " " << pre[i][1] << " " << pre[i][2] << " " << pre[i][3] << endl;
        for(int j = 2; i - j + 1 >= 1; j += 2){
            if(pre[i][0] - pre[i - j][0] == pre[i][1] - pre[i - j][1] && pre[i][2] - pre[i - j][2] == pre[i][3] - pre[i - j][3]){
                ++ ans;
            }
        }
    }
    cout << ans << endl;
}
int main(){	
    cin >> t;
    p['U'] = 0,p['D'] = 1, p ['L'] = 2, p['R'] = 3;
    while(t -- ){
        //cin >> n >> s + 1;
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            if(i & 1){
                s[i] = 'L';
            }
            else{
                s[i] = 'R';
            }
        }
        memset(pre,0,sizeof(pre));
        solve();
    }
    return 0;
}