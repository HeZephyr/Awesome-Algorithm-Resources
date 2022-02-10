/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-29 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/* struct node{
    int to, next, w;
}edges[N];
int tot, head[N];
int n;
void add(int u, int v, int w){
    edges[++ tot].to = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;
} */
int n, a[N];
int sum;
void solve(){
    sort(a + 1, a + n);
    bool flag = false;
    for(int i = 1; i < n; ++ i){
        if(a[i] > 1){
            sum += 1;
            flag = true;
            break;
        }
    }
    if(!flag)puts("-1");
    else printf("%d\n", sum);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++ i){
        scanf("%d%d", &u, &v);
        scanf("%d", &a[i]);
        sum += a[i];
    }
    solve();
    return 0;
}