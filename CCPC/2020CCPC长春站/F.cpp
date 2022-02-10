#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e5 + 7;
const int maxm = 1e6 + 10;
struct e_node{
    int next;
    int to;
}e[maxn << 1];
int head[maxn], a[maxn];
int tot;
void add_e(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int son[maxn], sz[maxn];
void pre_dfs(int u, int father){
    sz[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        pre_dfs(v, u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v])son[u] = v;
    }
}
int nowson;
multiset<int >p[maxm];
set<int >q;
ll ans;
void calc(int u, int father, int val){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        //cout << "!!"<<endl;
        if(v == father || v == nowson)continue;
        calc(v, u, val);
    }
    if(val == 1){
        for(auto x : q){
            cout << "!!"<<endl;
            int v = x;
            for(auto y : p[a[u] ^ a[v]]){
                ans += v ^ y;cout << "!!"<<endl;
            }
        }
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(v == father || v == nowson)continue;
            p[a[v]].insert(v);
            q.insert(v);
        }
    }
    if(val == -1){
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(v == father || v == nowson)continue;
            cout << v << endl;
            q.erase(v);
            p[a[v]].erase(p[a[v]].find(v));
        }
    }
    
}
void dsu(int u, int father, int mark){
    cout << q.size() << u << father << endl;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father || v == son[u])continue;
        dsu(v, u, 0);
    }
    cout << "!" << u << father << endl;
    if(son[u])dsu(son[u], u, 1), nowson = son[u];
    calc(u, father, 1);
    nowson = 0;
    if(!mark){
        calc(u, father, -1);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        add_e(u, v);
        add_e(v, u);
    }
    pre_dfs(1, 0);
    dsu(1, 0, 1);
    printf("%lld", ans);
}