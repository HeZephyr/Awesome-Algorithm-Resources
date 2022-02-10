/**
  *@filename:F_Strange_Housing
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 11:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 600000 + 5;
const int P = 1e9+7;

int t,n,m,u,v;
struct node{
    int to,next;
}edges[N];
bool vis[N],flag[N];//vis[i]表示i节点是否已经访问过，flag[i]表示i节点是否已经染色。
int head[N],tot;
void init(){
    for(int i = 1; i <= n; ++ i){
        vis[i] = false;
        flag[i] = false;
        head[i] = false;
    }
    tot = 0;
}
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
bool check(){
    //检查图是否连通。以1作为起点，判断是否能访问到n个顶点。
    int num = 1;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(int i = head[idx]; i; i = edges[i].next){
            if(!vis[edges[i].to]){
                vis[edges[i].to] = true;
                num ++;
                q.push(edges[i].to);
            }
        }
    }
    return num == n;
}
void solve(){
    if(!check()){
        puts("NO");
    }
    else{
        //否则一定连通。
        puts("YES");
        queue<int> q;
        q.push(1);
        for(int i = 1; i <= n; ++ i){
            vis[i] = false;
        }
        vis[1] = true;
        int res = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            bool flag1 = false;
            for(int i = head[idx]; i; i = edges[i].next){
                if(!vis[edges[i].to]){
                    vis[edges[i].to] = true;
                    q.push(edges[i].to);
                }
                //检查相邻顶点是否染色。
                if(flag[edges[i].to]){
                    flag1 = true;
                }
            }
            //检查是否有必要染色。
            if(!flag1){
                flag[idx] = true;
                res ++;
            }
        }
        printf("%d\n",res);
        for(int i = 1; i <= n; ++ i){
            if(flag[i]){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++ i){
            scanf("%d%d", &u, &v);
            add(u,v);
            add(v,u);
        }
        solve();
    }
    return 0;
}