/**
  *@filename:Ink_on_paper
  *@author: pursuit
  *@created: 2021-08-12 12:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
pii a[N];
struct node{
    int u,v;
    ll dist;
    bool operator < (const node &A)const{
        return dist > A.dist;
    }
};
int father[N];
ll getDist(int i,int j){
    ll temp1 = a[i].x - a[j].x,temp2 = a[i].y - a[j].y;
    return temp1 * temp1 + temp2 * temp2;
}
int find(int x){
    int r = x;
    while(r != father[r])r = father[r];
    int i = x,j;
    while(father[i] != r)j = i,father[i] = r,i = j;
    return r;
}
void solve(){
    ll maxx;
    priority_queue<node> q;
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            q.push({i,j,getDist(i,j)});
        }
    }
    node b;
    int res = 0,fu,fv;
    while(!q.empty()){
        b = q.top();
        q.pop();
        fu = find(b.u), fv = find(b.v);
        //cout << b.u << " " << b.v << " " << b.dist << endl;
        if(fu != fv){
            res ++;
            father[fu] = fv;
            maxx = b.dist;
        }
        if(res == n - 1)break;
    }
    printf("%lld\n", maxx);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld", &a[i].x, &a[i].y);
            father[i] = i;
        }
        solve();
    }	
    return 0;
}