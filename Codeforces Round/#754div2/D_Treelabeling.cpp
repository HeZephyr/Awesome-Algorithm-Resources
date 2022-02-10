#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//如果u ^ v <= min(u, v);说明u和v的最高位相等。
int t, n;
struct edge{
    int to, next;
}edges[N << 1];
int tot, head[N];
void add(int u, int ){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void solve(){
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1, u, v; i < n; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        solve();
        for(int i = 1; i <= n; ++ i)head[i] = 0;
        tot = 0;
    }
    return 0;
}