/**
  *@filename:POJ2117
  *@author: pursuit
  *@created: 2021-08-14 09:48
**/
//#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//求删除一个点之后最大的连通块。
int n,m;
struct node{
    int to,next;
}edges[N];
int head[N],tot;
int dfn[N],low[N],num;
int add_block[N];//add_block[u]表示删除u之后能增加的连通块。
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void tarjan(int u,int fu){
    dfn[u] = low[u] = ++ num;
    int v,son = 0,fu_cnt = 0;//son统计子树有多少。
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu){
            fu_cnt ++;continue;
        }
        if(!dfn[v]){
            son ++;
            //没有被访问过。
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(u != fu && dfn[u] <= low[v]){
                add_block[u] ++;
            }
        }
        else{
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(u == fu){
        //说明为根节点。
        add_block[u] = son - 1;
    }
}
void solve(){
    int cnt = 0;
    for(int i = 0; i < n; ++ i){
        if(!dfn[i]){
            tarjan(i,i);
            cnt ++;//连通块数量。
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        ans = max(ans,cnt + add_block[i]);
    }
    printf("%d\n", ans);
    memset(head,0,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(add_block,0,sizeof(add_block));
    num = tot = 0;
}
int main(){	
    while(~scanf("%d%d", &n, &m) && (n + m)){
        int u,v;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u,v),add(v,u);
        }
        solve();
    }
    return 0;
}