/**
  *@filename:H
  *@author: pursuit
  *@created: 2021-09-22 19:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, q, x;
char op[1000];
unordered_map<int, set<int> > p1, p2;
int id1, id2, a, b, c;
void solve(){
    scanf("%d", &q);
    while(q -- ){
        scanf("%d", &x);
        printf("%d\n", x);
        printf("[");
        bool flag = false;
        for(auto x : p2[x]){
            if(flag)printf(",");
            printf("%d", x);
            flag = true;
        }
        printf("]\n[");
        flag = false;
        for(auto x : p1[x]){
            if(flag)printf(",");
            printf("%d", x);
            flag = true;
        }
        puts("]");
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < 4; ++ j){
            scanf("%s", op);
        }
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &id1, &id2);
        if(id2 == 203){
            scanf("%d%d%d", &a, &b, &c);
            p1[a].insert(id1), p1[b].insert(id1), p1[c].insert(id1);
            p2[a].insert(b), p2[a].insert(c);
            p2[b].insert(a), p2[b].insert(c);
            p2[c].insert(a), p2[c].insert(b);
        }
        else{
            scanf("%d%d", &a, &b);
            p1[a].insert(id1), p1[b].insert(id1);
            p2[a].insert(b), p2[b].insert(a);
        }
    }
    solve();
    return 0;
}