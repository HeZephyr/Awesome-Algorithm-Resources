/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-11 21:09
**/
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v;
int ans[N],st[N],ed[N],num;//st[u]表示的为起始dfs序，ed[u]表示以u为结点的子树的终止dfs序，即子树的最大编号。
struct node{
    int to,next;
}edges[N];
int tot,head[N];
bool vis[N];
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    st[u] = ++ num;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        dfs(v,u);
    }
    ed[u] = num;
}
int lowbit(int x){
    return x & (- x);
}
void insert(int x,int value){
    while(x <= n){
        ans[x] += value;
        x += lowbit(x);
    }
}
int sum(int x){
    int res = 0;
    while(x > 0){
        res += ans[x];
        x -= lowbit(x);
    }
    return res;
}
void solve(){
    dfs(1,1);
    for(int i = 1; i <= n; ++ i){
        insert(st[i],1);
    }
    scanf("%d", &m);
    char op;
    int x;
    while(m -- ){
        scanf(" %c%d", &op, &x);
        if(op == 'C'){
            insert(st[x],vis[x] ? -1 : 1);
            vis[x] ^= 1;
        }
        else{
            printf("%d\n", sum(ed[x]) - sum(st[x] - 1));
        }
    }
}
int main(){	
    scanf("%d", &n);
    memset(vis,true,sizeof(vis));
    memset(head,0,sizeof(head));
    tot = num = 0;
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v);
    }
    solve();
    return 0;
}