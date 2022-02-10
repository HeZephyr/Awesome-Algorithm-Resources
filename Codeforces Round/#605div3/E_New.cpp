/**
  *@filename:E_New
  *@author: pursuit
  *@created: 2021-08-21 18:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//反向建边。
int n,a[N],dp[N][2];
struct edge{
    int to,next;
}edges[N];
int head[N],tot;
vector<int> odd,even,ans;
void add(int u,int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void bfs(vector<int> &st, vector<int> &ed){
    vector<int> dp(n + 1,INF);//初始化。
    queue<int> q;
    for(auto &u : st)dp[u] = 0,q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = edges[i].next){
            int v = edges[i].to;
            if(dp[v] == INF){
                dp[v] = dp[u] + 1;
                q.push(v);
            }
        }
    }
    for(auto &v : ed){
        if(dp[v] != INF){
            ans[v] = dp[v];
        }
    }
}
void solve(){
    ans.resize(n + 1, - 1);
    bfs(odd,even);
    bfs(even,odd);
    for(int i = 1; i <= n; ++ i){
        printf("%d ", ans[i]);
    }
    puts("");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        if(a[i] & 1)odd.push_back(i);
        else even.push_back(i);
        int idx1 = i - a[i], idx2 = i + a[i];
        if(idx1 >= 1)add(idx1,i);
        if(idx2 <= n)add(idx2,i);
    }
    solve();
    return 0;
}