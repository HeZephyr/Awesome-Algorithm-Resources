/**
  *@filename:C_Deep_Down_Below
  *@author: pursuit
  *@created: 2021-08-24 23:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
pii res[N];
bool cmp(pii a, pii b){
    return (a.first - a.second) < (b.first - b.second);
}
void solve(){
    int k;
    ll x,minn,ans = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d", &k);
        minn = 0;
        for(int j = 0; j < k; ++ j){
            scanf("%lld", &x);
            if(x >= minn)minn = x + 1;//此时这个阶段增大。
            ++ minn;//杀死加1.
        }
        res[i].first = minn;//最后出来的最小值。
        res[i].second = k;//记录当前的有多少怪物。
    }
    sort(res,res + n, cmp);
    ans = res[0].first - res[0].second;
    ll cur = res[0].first;
    for(int i = 1; i < n; ++ i){
        //当前最小的值为了res[i].first - res[i].second;
        int temp = res[i].first - res[i].second;
        if(temp > cur){
            //补上差的temp - cur
            ans += temp - cur;
            cur = res[i].first;
        }
        else{
            //说明可行。我们累加现在的战力。
            cur += res[i].second;
        }
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        solve();
    }
    return 0;
}