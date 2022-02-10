#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 205;

ll m[N], sum[N], Max[N];
bool vis[N];
struct node{
    ll v, t;
}a[N];
vector<ll> v[20];
int main(){
    ll n, k, t;
    scanf("%lld%lld", &n, &k);
    for(int i = 1;i <= n;i++){
        m[i] = INT64_MIN;
        Max[i] = INT64_MAX;
    }
    ll cnt = 0, ans = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld %lld", &a[i].v, &a[i].t);
        if(a[i].v<0){
            m[t] = max(a[i].v, m[t]);
        } else {
            ans += a[i].v;
            v[t].push_back(a[i].v);
            sum[t] += a[i].v;
            Max[t] = min(Max[t], a[i].v);
        }
    }
    for(int i = 1;i <= 13;i++){
        if(v[i].size()&1) cnt++;
    }
    if(cnt+k>=4 || k>=cnt){
        printf("%lld\n", ans);
        return 0;
    }
    cnt -= k;
    for(int i = 1;i <= cnt;i++){
        ll tem = 0, pos = 0;
        for(int j = 1;j <= 13;j++){
            if(vis[j] || v.size()%2==0) continue;
            if(Max[j]+m[j] > tem){
                tem = Max[j]+m[j];
                pos = j;
            }
        }
        ans += m[pos];
        vis[pos] = 1;
    }
    return 0;
}