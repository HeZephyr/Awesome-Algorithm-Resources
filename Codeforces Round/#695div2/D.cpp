#include<bits/stdc++.h>
#define LL long long
#define INF INT64_MAX
#define MOD 998244353
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
typedef pair<int,int>pa;
const int N = 1e5+7;
LL a[N], SegTree[N<<2], lz[N<<2];
bool vis[N<<2];
map<LL, bool> mp;
char s[N];
void build(int rt, int l, int r){
    lz[rt] = SegTree[rt] = 0;
    vis[rt] = 0;
    if(l==r){
        SegTree[rt] = a[l];
        if(mp[a[l]]) vis[rt] = 1;
        return;
    }
    int mid = l+r>>1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    SegTree[rt] = SegTree[ls]+SegTree[rs];
    SegTree[rt] %= MOD;
}
void Pushdown(int rt){
    if(!lz[rt]) return;
    SegTree[ls] = (SegTree[ls]<<1)%MOD;
    SegTree[rs] = (SegTree[rs]<<1)%MOD;
    lz[ls] += lz[rt];
    lz[rs] += lz[rt];
    lz[rt] = 0;
}
LL lowbit(LL x) {return x&(-x);}
LL query(int rt, int l, int r, int ql, int qr){
    if(l>=ql && r<=qr){
        return SegTree[rt];
    }
    Pushdown(rt);
    int mid = l+r>>1;
    LL ans = 0;
    if(mid>=ql) ans += query(ls, l, mid, ql, qr);
    if(mid<qr) ans += query(rs, mid+1, r, ql, qr);
    return ans%MOD;
}
void update(int rt, int l, int r, int ul, int ur){
    if(l>=ul && r<=ur && vis[rt]){
        SegTree[rt] = (SegTree[rt]<<1)%MOD;
        lz[rt]++;
        return;
    }
    if(l==r && l>=ul && l <=ur){
        SegTree[rt] += lowbit(SegTree[rt]);
        if(mp[SegTree[rt]]) vis[rt] = 1;
        return;
    }
    Pushdown(rt);
    int mid = l+r>>1;
    if(mid>=ul) update(ls, l, mid, ul, ur);
    if(mid<ur) update(rs, mid+1, r, ul, ur);
    SegTree[rt] = SegTree[ls]+SegTree[rs];
    if(vis[ls] && vis[rs]){
        vis[rt] = 1;
        SegTree[rt]%=MOD;
    }
}
int main(){
    int n, m, k, _, op, l, r;
    scanf("%d", &_);
    mp[0] = 1;
    LL res = 1;
    for(LL i = 1;i <= 50;i++){
        res<<=1;
        mp[res] = 1;
    }
    while(_--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &op, &l, &r);
            if(op&1) update(1, 1, n, l, r);
            else printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
