/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-09-01 12:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//修复后所有主子的高度相同。
//放砖成本为a，取出砖的成本为r。移动的成本为m。
//m = m(m, a + r);
int n, a, r, m, h[N];
ll check(int x){
    //砖块所有的高度为x。
    ll sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(h[i] < x)sum1 += x - h[i];//放砖
        else sum2 += h[i] - x;//取砖。
    }
    ll cnt = min(sum1,sum2);
    sum1 -= cnt, sum2 -= cnt;
    return sum1 * a + sum2 * r + cnt * m;
}
void solve(){
    m = min(m, a + r);
    int l = 0, r = 1e9;
    while(l < r){
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if(check(lmid) < check(rmid)){
            r = rmid - 1;
        }
        else{
            l = lmid + 1;
        }
    }
    printf("%lld\n", check(l));
}
int main(){	
    scanf("%d%d%d%d", &n, &a, &r, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    solve();
    return 0;
}