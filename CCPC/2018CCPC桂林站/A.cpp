#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 100;
ll a[maxn], b[maxn];
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%lld", &b[i]);
        }
        int idx1 = n, idx2 = m;
        ll res = 0;
        while(idx1 >= 1 || idx2 >= 1){
            if(idx1 < 1){
                res += idx2 * b[idx2];
                -- idx2;
            }
            else if(idx2 < 1){
                res += idx1 * a[idx1];
                -- idx1;
            }
            else{
                if(a[idx1] > b[idx2]){
                    res += (idx1 + idx2) * b[idx2];
                    -- idx2;
                }
                else{
                    res += (idx1 + idx2) * a[idx1];
                    -- idx1;
                }
            }
        }
        printf("Case %d: %lld\n", t, res);
    }
}