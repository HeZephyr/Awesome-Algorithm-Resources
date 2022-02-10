#include<bits/stdc++.h>
#define L second 
#define R first

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 1e5 + 10;

int n;
pii a[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i].L, &a[i].R);
    }
    sort(a + 1, a + 1 + n);
    ll res = 0;
    int last = 0;
    for(int l = 1, r; l <= n; l = r){
        r = l;
        while(r <= n && a[r].R == a[l].R)++ r;
        //贪心取最左端。
        int tmp = max(last, a[r - 1].L);
        res += 1LL * (r - l) * tmp;
        last = tmp;
    }
    printf("%lld\n", res);
    return 0;
}