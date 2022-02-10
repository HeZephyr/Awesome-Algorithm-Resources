#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, father[N], p[N], dist[N];
void solve(){
    bool flag = false;
    for(int i = 1; i <= n; ++ i){
        if(dist[father[i]] > dist[i]){
            flag = true;
            break;
        }
    }
    if(flag)puts("-1");
    else{
        for(int i = 1; i <= n; ++ i){
            printf("%d ", dist[i] - dist[father[i]]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &father[i]);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &p[i]);
            dist[p[i]] = i;
        }
        solve();
    }
    return 0;
}