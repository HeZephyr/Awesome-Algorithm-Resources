/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-03 09:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, b[N];
//选择一个城市作为起点，直到选择某个城市作为结束起点。
//满足j - i = bj -
int dp[N];//表示到达i城市的最美丽度。
map<int, ll> p;//存储b[i] - i的最大美丽度。
void solve(){
    for(int i = 1; i <= n; ++ i){
        p[b[i] - i] = (p[b[i] - i] + b[i]);
    }
    ll res = 0;
    for(auto iter : p){
        res = max(res, iter.second);
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}