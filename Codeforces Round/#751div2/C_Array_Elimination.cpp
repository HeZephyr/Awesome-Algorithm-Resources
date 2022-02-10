/**
  *@filename:C_Array_Elimination
  *@author: pursuit
  *@created: 2021-10-25 15:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], ans[N];
int g[N][32];
void solve(){
    for(int j = 30; j >= 0; -- j){
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            cnt += g[i][j];
        }
        if(cnt == 0){
            for(int i = 1; i <= n; ++ i)ans[i] ++;
        }
        else{
            for(int i = 1; i * i <= cnt; ++ i){
                if(cnt % i == 0){
                    if(i == cnt / i){
                        ++ ans[i];
                    }
                    else{
                        ++ ans[i], ++ ans[cnt / i];
                    }
                }
            }
        }
    }
    //puts("1");
    for(int i = 1; i <= n; ++ i){
        if(ans[i] == 31)cout << i << " ";
    }
    cout << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            ans[i] = 0;
            for(int j = 30; j >= 0; -- j){
                g[i][j] = ((a[i] >> j) & 1);
            }
        }
        solve();
    }
    return 0;
}