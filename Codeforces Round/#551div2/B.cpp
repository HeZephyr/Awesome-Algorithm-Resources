/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-11-04 21:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//在(i, j)处，有h[i][j]积木相互叠放。
int n, m, h;
int a[N], b[N], c[N][N], res[N][N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(c[i][j]){
                res[i][j] = min(b[i], a[j]);
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){	
    cin >> n >> m >> h;
    for(int i = 1; i <= m; ++ i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++ i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cin >> c[i][j];
        }
    }
    solve();
    return 0;
}