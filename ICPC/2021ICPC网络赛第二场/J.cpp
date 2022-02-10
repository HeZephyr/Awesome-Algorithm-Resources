#include<bits/stdc++.h>
#define ll long long  
using namespace std;


const int N = 500 + 10;
const int M = 1e6 + 7;
const int maxn = N * N * 5;
int head[M];
struct e_node{
    int to;
    int next;
    int w;
}e[M<<1];
int tot = 1;
int S,T;
void add_e(int u,int v,int w){
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;
}
int dep[M], head2[M];
bool bfs(){
    memset(dep, -1, sizeof(dep));
    dep[S] = 0;
    memcpy(head2, head, sizeof(head));
    queue<int > q;
    q.push(S);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            ll w = e[i].w;
            if(w > 0 && dep[v] == -1){
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[T] != 1;
}
int dfs(int u,int f){
    if(u == T)return f;
    int sum = f;
    for(int i = head2[u]; i && sum; i = e[i].next){
        int v = e[i].to;
        int w = e[i].w;
        head2[u] = i;
        if(w > 0 && dep[v] == dep[u] + 1){
            int c = dfs(v, min(w, sum));
            e[i].w -=c;
            e[i ^ 1].w += c;
        }
    }
    return f - sum;
}
int dinic(){
    int ans = 0;
    while(bfs()){
        ans += dfs(S, INT_MAX);
    }
    return ans;
}
int n, m;
int put[N][N];
int a[N][N];
int main(){
    scanf("%d %d", &n, &m);
    S = n * n + 1;
    T = n * n + 2;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0){
                add_e(i * n + j, T, m);
                add_e(T, i * n + j, 0);
            }
            else {
                add_e(S, i * n + j, m);
                add_e(i * n + j, S, 0);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i - 1 >= 0 && a[i][j] > a[i - 1][j])
                add_e(i * n + j, (i - 1) * n + j, m), add_e((i - 1) * n + j, i * n + j, 0);
            if(i + 1 < n && a[i][j] > a[i + 1][j])
                add_e(i * n + j, (i + 1) * n + j, m), add_e((i + 1) * n + j, i * n + j, 0);
            if(j - 1 >= 1 && a[i][j] > a[i][j - 1])
                add_e(i * n + j, i * n + j - 1, m), add_e(i * n + j - 1, i * n + j, 0);
            if(j + 1 <= n && a[i][j] > a[i][j + 1])
                add_e(i * n + j, i * n + j + 1, m), add_e(i * n + j + 1, i * n + j, 0);
        }
    }
    int anss = dinic();
    for(int i = head[T]; i; i = e[i].next){
        int v = e[i].to;
        int w = e[i].w;
        if(w < 0){
            int x = v/n;
            int y = v%n;
            put[x][y] = -w;
        }
    }
    for(int i = 0; i < n ; ++i){
        for(int j = 1; j <= n; ++j){
            printf("%d", put[i][j]);
            if(put[i][j])printf(".0000000 ");
        }
        printf("\n");
    }

}