#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m, a[N], b[N], pos[N], flag[N];
ll sum1, sum2;
int vis1[N], vis2[N];
bool cmp(int i, int j){
    return b[i] < b[j];
}
void solve(){
    sort(a + 1, a + 1 + n);
    sort(pos + 1, pos + 1 + m, cmp);
    int l, r;
    ll res = 0;
    if(n < m){
        //肯定不能全杀完，则挑能杀的都杀了。
        l = n, r = 1;
        while(l >= 1 && r <= m){
            if(a[l] < b[pos[r]])break;
            if(flag[pos[r]])++ r;
            else{
                res += (a[l] - b[pos[r]]);
                -- l, ++ r;
            }
        }
    }
    else{
        //此时分两种策略，不全杀完和全杀完。
        ll ans1 = 0;
        l = n, r = 1;
        while(l >= 1 && r <= m){
            while(flag[pos[r]] && r <= m)++ r;
            if(r > m || a[l] < b[pos[r]])break;
            ans1 += (a[l] - b[pos[r]]);
            -- l, ++ r;
        }
        //全杀完。
        //先杀掉防御的。
        l = 1, r = 1;
        while(l <= n && r <= m){
            while(!flag[pos[r]] && r <= m)++ r;
            if(r > m)break;
            if(a[l] < b[pos[r]])++ l;
            else{
                vis1[l] = 1, vis2[r] = 1;
                ++ l, ++ r;
            }
        }
        //debug(r);
        ll res2 = 0;
        if(r > m){
            //说明防御的被打完了。
            ll sum1 = 0;
            l = 1, r = 1;
            while(l <= n && r <= m){
                while(flag[pos[r]] && r <= m)++ r;
                if(r > m)break;
                if(vis1[l])++ l;
                else{
                    if(a[l] >= b[pos[r]]){
                        vis1[l] = 1;
                        res2 += a[l] - b[pos[r]];
                        l ++, r ++;
                    }
                }
            }
            //debug(r);
            if(r > m){
                for(int i = 1; i <= n; ++ i){
                    if(!vis1[i]){
                        res2 += a[i];
                    }
                }
            }
        }
        res = max(ans1, res2);
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        sum1 = sum2 = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            vis1[i] = 0;
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &b[i]);
            pos[i] = i;
            vis2[i] = 0;
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &flag[i]);
        }
        printf("Case %d: ", k);
        solve();
    }
    return 0;
}