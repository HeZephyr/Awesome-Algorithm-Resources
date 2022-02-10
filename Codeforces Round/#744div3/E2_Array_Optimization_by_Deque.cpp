/**
  *@filename:E2_Array_Optimization_by_Deque
  *@author: pursuit
  *@created: 2021-09-28 23:41
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
int c[N];
vector<int> temp;
int lowbit(int x){
    return x & (- x);
}
void add(int x, int v){
    while(x <= n){
        c[x] += v;
        x += lowbit(x);
    }
}
ll get(int x){
    ll ans = 0;
    while(x){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve(){
    //离散化。可以记住这个离散化操作。
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i = 1; i <= n; ++ i){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    ll res = 0;
    for(int i = 1; i <= n; ++ i){
        res += min(get(a[i] - 1), get(n) - get(a[i]));
        add(a[i], 1);
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        temp.resize(n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            temp[i - 1] = a[i];
            c[i] = 0;
        }
        solve();
    }
    return 0;
}