#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
ll a[N], x, y;
//一个去杀龙， 其他人都要防御，则一个a[i] >= x[j], 其他的都要>=y[j];
ll sum;
int check(ll y){
    int l = 1, r = n + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] >= y){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
void solve(){
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++ i){
        scanf("%lld%lld", &x, &y);
        //二分找到需要打龙的。
        int idx1 = check(x);
        //a[l]是打龙的。a[l - 1]也可以打龙，让它增加。
        ll ans = max(0LL, max(0LL, x - a[idx1]) + max(0LL, y - (sum - a[idx1])));
        if(idx1 > 1)ans = min(ans, max(0LL, x - a[idx1 - 1] + max(0LL, y - (sum - a[idx1 - 1]))));
        printf("%lld\n", ans);
    }
    solve();
    return 0;
}