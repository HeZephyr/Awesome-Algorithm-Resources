/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-17 13:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,p[N],nex[N],u,v;//nex[u]必须在u的右边。
void solve(){
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for(int i = 1; i <= k; ++ i){
        scanf("%d%d", &u, &v);
        nex[u] = v;
    }
    solve();
    return 0; 
}