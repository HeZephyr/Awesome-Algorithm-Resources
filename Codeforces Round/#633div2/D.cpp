/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-15 10:41
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


struct node{
    int to,next;
}edges[N << 1];
int head[N],tot,in[N];
int depth[N];//深度。
int n,u,v;
int f[N];//统计和叶子结点相邻的次数。
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    int v;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(in[i] == 1){
            f[edges[head[i]].to] ++;
        }
    }
    dfs(1,0);
    int minn = 1,maxx = n - 1;
    for(int i = 1; i <= n; ++ i){
        maxx -= max(0,f[i] - 1);
    }
    bool flag1 = false, flag2 = false;
    for(int i = 1; i <= n; ++ i){
        if(in[i] == 1){
            if(depth[i] & 1)
                flag1 = true;
            else{
                flag2 = true;
            }
        }
    }
    if(flag1 && flag2)minn = 3;
    printf("%d %d\n", minn, maxx);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v),add(v,u);
        in[u] ++,in[v] ++;
    }
    solve();
    return 0;
}