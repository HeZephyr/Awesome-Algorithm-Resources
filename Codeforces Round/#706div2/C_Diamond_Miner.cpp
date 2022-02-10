/**
  *@filename:C_Diamond_Miner
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-30 17:23
**/
#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n;
vector<pll> a,b;
double dist(pll a,pll b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
void solve(){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    double ans = 0;
    for(int i = 0; i < n; ++ i){
        ans += dist(a[i],b[i]);
    }
    printf("%.10llf\n",ans);
}
int main(){
    int t;
    scanf("%d", &t);
    ll u,v;
    while(t -- ){
        scanf("%d", &n);
        a.clear(),b.clear();
        for(int i = 0;i < 2 * n;i ++){
            scanf("%lld %lld",&u,&v);
            if(u){
                a.push_back({abs(u),abs(v)});
            }
            else{
                b.push_back({abs(u),abs(v)});
            }
        }
        solve();
    }
    return 0;
}