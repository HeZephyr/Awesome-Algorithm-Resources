#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;

struct node{
    ll val, id;
    bool operator < (const node &x) const{
        return val<x.val;
    }
}a[N];
ll ans[N];
int main(){
    ll t, n;
    scanf("%lld", &t);
    for(ll c = 1;c <= t;c++){
        scanf("%lld", &n);
        for(ll i = 1;i <= n;i++){
            scanf("%lld", &a[i].val);
            ans[i] = 0;
            a[i].id = i;
        }
        ll c0 = 1, c1 = 1, pos = 1, fla = 0;
        sort(a+1, a+1+n);
        for(ll i = 1;i <= n;i++){
            while(pos<a[i].val){
                c0<<=1ll;
                c1<<=1ll;
                pos++;
                if(c0+c1 > n-i+1ll){
                    fla = 1;
                    break;
                }
            }
            //printf("c0 = %lld, c1 = %lld\n", c0, c1);
            if(fla) break;
            if(c1){
                ans[a[i].id] = 1ll;
                c1--;
            }
            else if(c0){
                c0--;
            }
            if(c0==0 && c1==0) break;
        }
        printf("Case %lld: ", c);
        if(fla){
            printf("NO\n");
        } else {
            printf("YES\n");
            for(int i = 1;i <= n;i++){
                printf("%lld", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}