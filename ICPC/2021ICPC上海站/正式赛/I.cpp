#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 205;

ll a[N], m[N], sum[N], Max[N];
vector<ll> v[20];
struct node{
    ll zheng, fu;
};
vector<node> g;
int main(){
    ll n, k, t;
    scanf("%lld%lld", &n, &k);
    for(int i = 1;i <= 13;i++){
        m[i] = INT64_MIN;
        Max[i] = INT64_MAX;
    }
    for(int i = 1;i <= n;i++){
        scanf("%lld %lld", &a[i], &t);
        if(a[i]<0){
            m[t] = max(m[t], a[i]);
        } else {
            v[t].push_back(a[i]);
            sum[t] += a[i];
            Max[t] = min(Max[t], a[i]);
        }
    }
    ll ans = 0;
    for(int i = 1;i <= 13;i++){
        if(v[i].empty()) continue;
        if(v[i].size()%2==0){
            ans += sum[i];
        } else {
            if(Max[i]>m[i])
                g.push_back({Max[i], m[i]});
        }
    }
    int len = g.size();
    return 0;
}