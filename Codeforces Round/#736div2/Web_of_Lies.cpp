/**
  *@filename:Web_of_Lies
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 23:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,m,q,u,v,op;
set<int> s;
int cnt[N];//统计每个结点死了几次。
void solve(){
    while(q -- ){
        scanf("%d", &op);
        if(op == 3){
            printf("%d\n", (int)s.size());
        }
        else{
            scanf("%d%d", &u, &v);
            if(op == 1){
                if(u > v){
                    cnt[v] ++;
                }
                else{
                    cnt[u] ++;
                }
                if(cnt[u] != 0){
                    s.erase(u);
                }
                else{
                    s.insert(u);
                }
                if(cnt[v] != 0){
                    s.erase(v);
                }
                else{
                    s.insert(v);
                }
            }
            else if(op == 2){
                if(u > v){
                    cnt[v] --;
                }
                else{
                    cnt[u] --;
                }
                if(cnt[u] != 0){
                    s.erase(u);
                }
                else{
                    s.insert(u);
                }
                if(cnt[v] != 0){
                    s.erase(v);
                }
                else{
                    s.insert(v);
                }
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        s.insert(i);
    }
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &u, &v);
        if(u > v){
            cnt[v] ++;
        }
        else{
            cnt[u] ++;
        }
        if(cnt[u] != 0){
            s.erase(u);
        }
        else{
            s.insert(u);
        }
        if(cnt[v] != 0){
            s.erase(v);
        }
        else{
            s.insert(v);
        }
    }
    scanf("%d", &q);
    solve();
    return 0;
}