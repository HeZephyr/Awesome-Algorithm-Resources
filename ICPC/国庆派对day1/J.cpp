#include<bits/stdc++.h>
#define ll long long 

const int maxn = 1e5 + 10;
using namespace std;

struct q_node{
    int l, r;
    int id;
}q[maxn];
int n, m;
int ans[maxn], cnt[maxn];
int a[maxn];
void add(int x){
    if(x == 0)return ;
    cnt[a[x]]--;
    if(cnt[a[x]] == 0)ans[0]--;
}
void del(int x){
    if(x == 0)return ;
    if(cnt[a[x]] == 0)ans[0]++;
    cnt[a[x]]++;
}
int block_length;
bool cmp(q_node a, q_node b){
    return (a.l/block_length) ^ (b.l / block_length) ? a.l < b.l : (((a.l/block_length) & 1) ? a.r < b.r : a.r > b.r);
}
int main(){
    while(cin >> n >> m){
        memset(cnt, 0, sizeof(cnt));
        ans[0] = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(cnt[a[i]] == 0)ans[0]++;
            cnt[a[i]]++;
        }
        int tot = 0;
        for(int i = 1; i <= m; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            x++, y--;
            if(x > y){
                ans[i] = ans[0];
                continue;
            }
            q[++tot].l = x, q[tot].r = y, q[tot].id = i;
        }
        block_length = n / sqrt(tot);
        sort(q + 1, q + tot + 1, cmp);
        int L = 0, R = 0;
        for(int i = 1; i <= tot; ++i){
           while(L < q[i].l)del(L++);
           while(R > q[i].r)del(R--);
           while(L > q[i].l)add(--L);
           while(R < q[i].r)add(++R);
           //cout << q[i].l <<" " <<q[i].r<<endl;
           //cout << L << " "<<R<<endl;
           ans[q[i].id] = ans[0];
        }
        for(int i = 1; i <= m; ++i){
            printf("%d\n", ans[i]);
        }
    }
}