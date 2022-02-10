#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 100;
map<char, int > map1;
map<int , char>map2;
int tot, cnt;
int n;
struct e_node{
    int to;
    int next;
    int w;
}e[maxn << 1];
int head[maxn];
void add_e(int u, int v, int w){
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;
}
int dis[maxn], flag[maxn], t[maxn];
bool SPFA(int u){
    queue<int > s;
    for(int i = 1; i <= n; ++i)dis[i] = 0, flag[i] = t[i] = 0;
    s.push(u);dis[u] = 0;flag[u] = 1;
    while(!s.empty()){
        int x = s.front();
        s.pop();
        flag[x] = 0;
        for(int i = head[x]; i; i = e[i].next){
            int v = e[i].to;
            int w = e[i].w;
            if(dis[v] < dis[x] + w){
                dis[v] = dis[x] + w;
                if(!flag[v])s.push(v), flag[v] = 1, t[v]++;
                if(t[v] > n)return true;
            }
        }
    }
    return false;
}
int inn[maxn], vis[maxn];
vector<char> ans[maxn];
int main(){
    int m;
    scanf("%d", &m);
    //printf("%d", m);
    for(int i = 1; i <= m; ++i){
        string q;
        cin >> q;
        //cout << q << endl;
        int len = q.length();
        int j = 0;
        char x, u, v;
        int xx, uu, vv;
        x = q[0]; u = q[2]; v = q[3];
        //cout << x << u << v<<endl;
        if(!map1[x])map1[x] = ++cnt, map2[cnt] = x;
        if(!map1[u])map1[u] = ++cnt, map2[cnt] = u;
        if(!map1[v])map1[v] = ++cnt, map2[cnt] = v;
        xx = map1[x];
        uu = map1[u];
        vv = map1[v];
        //cout << xx << uu << vv;
        add_e(uu, xx, 1);
        add_e(xx, vv, 1);
        inn[xx]++, inn[vv]++;
    }
    //printf("%d %d %d %d\n", map1['A'], map1['B'], map1['7'], map1['D']);
    n = cnt;
    //printf("%d\n", tot);
    int root = 0;
    for(int i = n; i >= 1; --i){
        add_e(0, i, 1);
    }
    if(SPFA(0))printf("No Answer\n");
    else {
        int sum = 0;
        
        for(int i = 1; i <= n; ++i){
            vis[dis[i]] = 1;
            ans[dis[i]].push_back(map2[i]);
            sum = max(sum, (int)ans[dis[i]].size());
        }
        int j = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < ans[i].size(); ++j){
                printf("%c", ans[i][j]);
            }
        }
        
    }
}