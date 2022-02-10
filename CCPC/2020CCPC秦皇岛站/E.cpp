#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e5+7;
struct node{
    ll val, id;
    bool operator < (const node &x) const{
        return val<x.val;
    }
}a[N];
ll vis[N];
int main(){
    ll t, n, p;
    scanf("%lld", &t);
    for(int ca = 1;ca <= t;ca++){
        scanf("%lld%lld", &n, &p);
        ll Max = 0ll;
        for(ll i = 1;i <= n;i++){
            vis[i] = vis[i+n] = 0ll;
            scanf("%lld%lld", &a[i].val, &a[i+n].val);
            Max = max(Max, a[i+n].val);
            a[i].id = a[i+n].id = i;
        }
        sort(a+1, a+1+2*n);
        ll vl = (Max*p+99)/100, l = 0ll, r = 2*n, cnt = 0ll;
        //printf("\n");
        for(ll i = 1;i <= 2*n;i++){
            if(a[i].val>=vl){
                l = i;
                break;
            }
        }
        for(ll i = l;i <= 2*n;i++){
            if(a[i].val>Max){
                r = i-1ll;
                break;
            }
            if(!vis[a[i].id]){
                cnt++;
                vis[a[i].id]++;
            } else {
                vis[a[i].id]++;
            }
        }
        ll ans = cnt;
        //printf("ans = %lld\n", ans);
        while(r<2*n){
            r++;
            if(!vis[a[r].id]){
                cnt++;
            }
            vis[a[r].id]++;
            vl = (a[r].val*p+99)/100;
            while(a[l].val<vl){
                vis[a[l].id]--;
                if(!vis[a[l].id]){
                    cnt--;
                }
                l++;
            }
            ans = max(ans, cnt);
            //printf("l = %lld, r = %lld, ans = %lld\n", l, r, ans);
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}