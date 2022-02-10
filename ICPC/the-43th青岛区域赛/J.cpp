#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e17;
const int N = 1e5 + 10;
int t;
int n, m, a[N];
ll l, r;
int check(ll x){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        if(x >= a[i]){
            ++ cnt;
            x -= a[i];
        }
    }
    return cnt;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        l = 0, r = INF;
        ll sum = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            //a[i] = 1e9;
            sum += a[i];
        }
        cout << sum << endl;
        if(n == m){
            puts("Richman");
            continue;
        }
        bool flag = false;
        ll res = 0;
        while(l <= r){
            ll mid = (l + r) >> 1;
            //cout << mid << endl;
            int x = check(mid);
            if(x > m){
                r = mid - 1;
            }
            else{
                if(x == m){
                    flag = true;
                    res = max(res, mid);
                }
                l = mid + 1;
            }
        }
        if(check(l) == m)res = max(res, l);
        if(!flag){
            puts("Impossible");
        }
        else{
            printf("%lld\n", res);
        }
    }
    return 0;
}