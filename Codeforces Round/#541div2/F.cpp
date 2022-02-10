/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-09-09 16:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, father[N];
struct node{
    int l, r, next;
}nodes[N];
int find(int x){
    int r = x;
    while(father[r] != r){
        r = father[r];
    }
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    int u, v, fu, fv;
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        fu = find(u), fv = find(v);
        father[fu] = fv;
        nodes[nodes[fv].r].next = nodes[fu].l;
        nodes[fv].r = nodes[fu].r;
    }
    int root = nodes[find(1)].l;
    while(root){
        printf("%d ", root);
        root = nodes[root].next;
    }
    puts("");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        father[i] = nodes[i].l = nodes[i].r = i;
    }
    solve();
    return 0;
}