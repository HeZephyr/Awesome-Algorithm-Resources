/**
  *@filename:D_PriceFixed
  *@author: pursuit
  *@created: 2021-09-11 15:46
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
struct node{
    ll a, b;
    bool operator < (const node &A){
        return b < A.b;
    }
}nodes[N];
void solve(){
    sort(nodes + 1, nodes + n + 1);
    int l = 1, r = n;//l代表当前购买的商品，r代表当前需要消耗的商品。
    ll res = 0, cnt = 0;//cnt代表购买了多少商品，res代表代价。
    while(l <= r){
        if(nodes[l].b <= cnt){
            //说明符合要求。
            res += nodes[l].a, cnt += nodes[l].a;
            ++ l;
        }
        else{
            //说明不行，此刻要让r消耗。
            ll x = min(nodes[r].a, nodes[l].b - cnt);
            res += 2 * x, cnt += x;
            nodes[r].a -= x;
            if(!nodes[r].a)-- r;
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld%lld", &nodes[i].a, &nodes[i].b);
    }
    solve();
    return 0;
}