/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-27 19:11
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, x;
int cnt[N];
bool check(int x){
    if(x == 0)return true;
    int ans = 0;
    for(int i = 1; i <= 100; ++ i){
        ans += cnt[i] / x;
    }
    return ans >= n;
}
void solve(){
    int l = 0, r = 100;
    int res;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++ i){
        scanf("%d", &x);
        cnt[x] ++;
    }
    solve();
    return 0;
}