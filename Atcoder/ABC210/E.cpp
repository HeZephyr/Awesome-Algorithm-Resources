/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 17:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

struct node{
    int a,c;
    bool operator < (const node &A){
        if(c == A.c){
            return a < A.a;
        }
        return c < A.c;
    }
};
node nodes[N];
int n,m;
void solve(){
    ll ans = 0;
    sort(nodes + 1,nodes + 1 + m);
    for(int i = 1; i <= m; ++ i){
        int temp = __gcd(nodes[i].a,n);
        ans += 1LL * (n - temp) * nodes[i].c;
        n = temp;
        if(n == 1)break;
    }
    printf("%lld\n",n > 1 ? -1 : ans);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &nodes[i].a, &nodes[i].c);
    }
    solve();
    return 0;
}