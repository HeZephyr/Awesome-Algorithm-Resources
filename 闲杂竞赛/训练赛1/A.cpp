/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-08 19:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


int t,n,m;
int trie[N][2];
int tot;
void insert(int x){
    int p = 0;
    for(int i = 31; i >= 0; -- i){
        int u = x >> i & 1;
        if(trie[p][u] == 0){
            trie[p][u] = ++tot;
        }
        p=trie[p][u];
    }
}
int query(int x){
    int p=0;
    int res = 0;
    for(int i = 31; i >= 0;i--){
        int u = x >> i & 1;
        if(trie[p][!u]){
            p=trie[p][!u];
            if(u == 1){
                res = res * 2;
            }
            else{
                res = res * 2 + 1;
            }
        }
        else{
            res = res * 2 + u;
            p = trie[p][u];
        }
    }
    return res;
}
void solve(){
    int x;
    while(m --){
        scanf("%d", &x);
        printf("%d\n", query(x));
    }
}
int main(){
    scanf("%d", &t);
    for(int i = 1; i <= t; ++ i){
        scanf("%d%d", &n, &m);
        int x = 0;
        tot = 0;
        memset(trie,0,sizeof(trie));
        for(int j = 1; j <= n; ++ j){
            scanf("%d", &x);
            insert(x);
        }
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}