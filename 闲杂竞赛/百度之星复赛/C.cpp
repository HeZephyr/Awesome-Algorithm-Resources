/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-21 20:02
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v;
char s[N];
struct edge{
    int to,next;
}edges[N];
int head[N],tot;
void add(int u,int v){
    edges[++tot].next = head[u];
    edges[tot].to = v;
    head[u] = tot;
}
void solve(){

}
int main(){	
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v);
    }
    solve();
    return 0;
}