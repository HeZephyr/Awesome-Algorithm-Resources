/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 16:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,w[N];
int into[N];
priority_queue<pii> q;
ll ans;
void solve(){
    while(!q.empty())q.pop();
    for(int i = 1; i <= n; ++ i){
        if(into[i] > 1){
            q.push({w[i],into[i]});
        }
    }
    printf("%lld ",ans);
    for(int i = 1; i < n - 1; ++ i){
        pii temp = q.top();
        q.pop();
        ans += temp.first;
        printf("%lld ",ans);
        if(--temp.second > 1){
            q.push(temp);
        }
    }
    printf("\n");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        ans = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &w[i]);
            ans += w[i];
        }
        int u,v;
        memset(into,0,sizeof(into));
        for(int i = 1; i < n; ++ i){
            scanf("%d%d", &u, &v);
            into[u] ++,into[v] ++;
        }
        solve();
    }
    return 0;
}