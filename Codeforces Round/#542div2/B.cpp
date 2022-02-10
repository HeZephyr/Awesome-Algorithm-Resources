/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-10 15:43
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//每家糕点店只能购买一个特定尺寸的层。即在第i家能购买到ai的层。
int n;
vector<int> a[N];
void solve(){
    ll cnt = 0, pre = 1;
    for(int i = 1; i <= n; ++ i){
        int cur = a[i][0];
        cnt += abs(cur - pre);
        pre = cur;
    }
    pre = 1;
    for(int i = 1; i <= n; ++ i){
        int cur = a[i][1];
        cnt += abs(cur - pre);
        pre = cur;
    }
    printf("%lld\n", cnt);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1, x; i <= 2 * n; ++ i){
        scanf("%d", &x);
        a[x].push_back(i);
    }
    solve();
    return 0;
}