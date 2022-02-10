/**
  *@filename:C_Omkar_and_Determination
  *@author: pursuit
  *@created: 2021-10-17 19:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, q, l, r;
string g[N];
int sum[N];
void solve(){
    int res = sum[r] - sum[l - 1];
    if(res){
        puts("NO");
    }
    else{
        puts("YES");
    }
}
int main(){	
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> g[i];
        g[i] = " " + g[i];
    }
    for(int j = 2; j <= m; ++ j){
        sum[j] = sum[j - 1];
        int flag = false;
        for(int i = 2; i <= n; ++ i){
            if(g[i][j] == 'X'){
                flag = 1;
                break;
            }
        }
        sum[j] += flag;
    }
    cin >> q;
    while(q -- ){
        cin >> l >> r;
        solve();
    }
    return 0;
}