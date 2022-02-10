#include<bits/stdc++.h>
#define ull unsigned long long 
#define int long long 
using namespace std;
const int maxn = 2e5 + 100;
struct e_node{
    int next;
    int u;
    int to;
    int w;
}e[maxn << 1];
int head[maxn];
int tot;
void add_e(int u, int v, int w){
    e[++tot].to = v;
    e[tot].u = u;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;
}
struct a_node{
    int sz[4];
}a[maxn], b[maxn];
int sum[4];
void dfs(int u, int father){
    a[u] = b[u];
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        dfs(v, u);
        a[u].sz[1] += a[v].sz[1];
        a[u].sz[2] += a[v].sz[2];
        a[u].sz[3] += a[v].sz[3];
    }
}
signed main(){
    int n;
    scanf("%lld", &n);
    for(int i = 1; i <= n - 1; ++i){
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        add_e(u, v, w);
        add_e(v, u, w);
    }
    int chu = 1;
    for(int i = 1; i <= 3; ++i){
        int m;
        scanf("%lld", &m);
        chu *= m;
        sum[i] = m;
        for(int j = 1; j <= m; ++j){
            int x;
            scanf("%lld", &x);
            b[x].sz[i]++;
        }
    }
    dfs(1, 0);
    double res = 0.0;
    for(int i = 1;i <= tot; i += 2){
        int v = e[i].to, w = e[i].w;
        int p1, q1, p2, q2, p3, q3;
        p1 = a[v].sz[1];q1 = sum[1] - a[v].sz[1];
        p2 = a[v].sz[2];q2 = sum[2] - a[v].sz[2];
        p3 = a[v].sz[3];q3 = sum[3] - a[v].sz[3];
        res += (1.0*p1*q2*q3/(1.0*chu) + 1.0*p2*q1*q3/(1.0*chu) + 1.0*p3*q1*q2/(1.0*chu) + 1.0*q1*p2*p3/(1.0*chu) + 1.0*q2*p1*p3/(1.0*chu) + 1.0*q3*p1*p2/(1.0*chu))*w;
    }
    printf("%.8lf\n", res);
}