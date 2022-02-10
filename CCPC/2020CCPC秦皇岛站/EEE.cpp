#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 100;
int c[maxn];
int pre[maxn];
int lowbit(int x){return x & (-x);};
int n, p;
void _add(int x, int w){
    while(x <= n){
        c[x] += w;
        x += lowbit(x);
    }
}
int _sum(int x){
    if(x <= 0)return 0;
    int sum = 0;
    while(x > 0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
struct a_node{
    ll x;
    int id;
}a[maxn];
ll b[maxn << 1];
bool cmp(a_node x, a_node y){
    return x.x < y.x;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        scanf("%d %d", &n, &p);
        unordered_map<ll, int> map1;
        n = n * 2;
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i].x);
           a[i].id = (i + 1)/2;
           b[++cnt] = a[i].x;
           b[++cnt] = (1ll * a[i].x * p + 99) / 100;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + cnt + 1);
        int tot = 0, sum = 0;
        int ans = 0;
        for(int i = 1; i <= cnt; ++i){
            if(!map1[b[i]])map1[b[i]] = ++ tot;
            pre[i] = c[i] = 0;
        }
        for(int i = 1; i <= n; ++i){
            int q = map1[a[i].x];
            //cout << q << endl;
            _add(q, 1);
            int flag = 0;
            if(sum < n/2){
                if(pre[a[i].id] == 0)sum++;
                else {
                    _add(pre[a[i].id], -1);
                }
                pre[a[i].id] = q;
                flag = 1;
            }
            if(sum >= n/2){
                //cout << i << endl;
                if(!flag){
                    if(pre[a[i].id])_add(pre[a[i].id], -1);
                }
                pre[a[i].id] = q;
                //cout <<  (q * p) / 100;
                //cout << i << map1[(a[i].x * p) / 100] <<n/2 - _sum(map1[(a[i].x * p + 99) / 100] - 1) << endl;
                //cout << 1ll * (a[i].x * p + 99) / 100 << map1[1ll * (a[i].x * p + 99) / 100] << endl;
                ans = max(ans, n/2 - _sum(map1[1ll * (a[i].x * p + 99) / 100] - 1));
            }
        }
        //cout << _sum(n) << tot;
        printf("Case #%d: %d\n", t, ans);
    }
}
/*
1
10 30
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20

*/