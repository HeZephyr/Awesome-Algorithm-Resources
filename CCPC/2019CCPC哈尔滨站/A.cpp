#include<bits/stdc++.h>
#define ll long long 
const int maxn = 4e4 + 7;
using namespace std;
struct e_node{
    int next;
    int to;
    int w;
    int q;
}e[maxn << 1];
int head[maxn];
int tot;
int sum;
void add_e(int u, int v, int w, int q){
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].next = head[u];
    e[tot].q = q;
    head[u] = tot;
}
ll ans;
int n, m;
int flag[maxn], t[maxn], dis[maxn];
bool SPFA(int u){
    queue<int > s;
    for(int i = 0; i <= n + 1; ++i){
        dis[i] = - maxn, flag[i] = t[i] = 0;
    }
    s.push(u);dis[u] = 0;flag[u] = 1;
    while(!s.empty()){
        int x = s.front();
        s.pop();
        flag[x] = 0;
        for(int i = head[x]; i; i = e[i].next){
            int  v = e[i].to, w = e[i].w;
            if(dis[v] < dis[x] + w + sum * e[i].q){
                dis[v] = dis[x] + w + sum * e[i].q;
                if(!flag[v])s.push(v), flag[v] = 1, t[v]++;
                //if(t[v] > n + 1)return true;
            }
        }
    }
    //cout << " ------" << endl;
    dis[0] = 0;
    //for(int i = 1; i <= n + 1; ++i){
        //if(dis[i] > n + 1 || dis[i] < 0)return true;
        //if(dis[i] - dis[i - 1] > 1)return true;
        //printf("%d ", dis[i]);
    //}
    for(int i = 1; i <= n + 1; ++i){
        if(dis[i] > n + 1 || dis[i] < 0)return true;
        if(dis[i] - dis[i - 1] > 1)return true;
        //printf("%d ", dis[i]);
    }
    //cout << dis[n + 1] << endl;
    if(dis[n + 1] == sum)return false;
    else return true;
}
void solove(){
    int m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    tot = 0;
    for(int i = 0; i <= n + 1; ++i){
        head[i] = 0;
    }
    for(int i = 1; i <= m1; ++i){
        int L, R, w;
        scanf("%d %d %d", &L, &R, &w);
        L++, R++;
        add_e(L - 1, R, w, 0);
    }
    for(int i = 1; i <= m2; ++i){
        int L, R, w;
        scanf("%d %d %d", &L, &R, &w);
        L++, R++;
        add_e(L - 1, R, -w, 1);
    }
    for(int i = n + 1; i >= 1; --i)add_e(0, i, 0, 0);
    for(int i = n + 1; i >= 2; --i)add_e(i - 1, i, 0, 0);
    int L = 0, R = n;
    int ans = 0;
    while(L <= R){
        int mid = L + R >> 1;
        sum = mid;
        //cout <<"sum:" << sum << endl;
        if(!SPFA(0)){
            L = mid + 1;
            ans = mid;
            //cout << "OK" << endl;
        }else  R = mid - 1;
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){       
        solove();
    }
}