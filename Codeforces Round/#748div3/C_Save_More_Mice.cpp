/**
  *@filename:C_Save_More_Mice
  *@author: pursuit
  *@created: 2021-10-13 23:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
int x[N];
ll res = 0;
void solve(){
    sort(x + 1, x + 1 + m);
    int cnt = n, res = 0;
    for(int i = m; i >= 1; -- i){
        if(cnt > n - x[i]){
            ++ res;
            cnt -= (n - x[i]);
        }
        else{
            break;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &x[i]);
        }
        solve();
    }
    return 0;
}