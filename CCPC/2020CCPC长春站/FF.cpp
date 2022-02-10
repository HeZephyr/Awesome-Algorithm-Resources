#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e5 + 7;
const int maxm = 2e6 + 10;
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
map<pair<int , int >, int>map1;
int nowson;
set<int >p[maxm];
set<int >q;
ll ans;
void calc(int u, int father, int nowu, int val){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        calc(v, u, nowu, val);
    }
    if(val == 1){
        //cout << u << father << q.size() << endl;
        /*for(auto y : p[a[nowu] ^ a[u]]){
            if(map1[{u, y}])continue;
            ans += u ^ y;
            map1[{u, y}] = 1;
            cout << "ans : " << u << y << endl;
        }*/
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(v == father)continue;
            p[a[v]].insert(v);
            q.insert(v);
        }
    }
    
    if(val == 0){
        //cout << u << father << q.size() << endl;
        for(auto y : p[a[nowu] ^ a[u]]){
           // if(y == father)continue;
            if(map1[{u, y}])continue;
            ans += u ^ y;
            map1[{u, y}] = 1;
            //cout << "ans : " << u << y << endl;
        }
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            if(v == father)continue;
            p[a[v]].insert(v);
            q.insert(v);
        }
    }
    //cout << u << father << q.size() << endl;
}
int t = 0;
void dsu(int u, int father, int mark){
    //cout << u << ++t << endl;
    if(son[u])dsu(son[u], u, 1);
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father || v == son[u])continue;
        dsu(v, u, 0);
    }
    calc(u, father, father, mark);
    q.insert(u);
    p[a[u]].insert(u);
    //cout << u << father << q.size() << endl;
}
/*
6 
4 2 1 4 6 2
1 2
2 3
1 4
4 5
4 6
8
4 2 6 4 6 2 4 2
1 2
2 3
1 4
4 5
4 6
5 7
5 8
ans : 78
ans : 65
ans : 25
*/
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
        map1[{u, v}] = map1[{v, u}] = 1;
    }
    pre_dfs(1, 0);
    dsu(1, 0, 1);
    printf("%lld", ans);
}