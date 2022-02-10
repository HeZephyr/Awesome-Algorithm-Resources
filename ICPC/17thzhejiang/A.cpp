#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int t, n, c, SegTree[N*4]; 
int a[N], b[N], ans2;
priority_queue<int, vector<int>, greater<int> > q;
void solve(){
    sort(b + 1, b + 1 + n, greater<int>() );
    q.push(0);
    for(int i = 1; i <= n; ++ i){
        int x = q.top();
        if(x +b[i] <= c){
            q.pop();
            q.push(x + b[i]);
        }
        else{
            q.push(b[i]);
        }
    }
    printf("%d %d\n", ans2, int(q.size()));
    while(!q.empty()) q.pop();
}
int query(int rt, int l, int r, int ql, int qr, int val){
    if(c-SegTree[rt] < val){
        return INT_MAX;
    }
    if(l==r){
        return l;
    }
    int mid = l+r>>1, ans = INT_MAX;
    if(c-SegTree[rt<<1] >= val) ans = min(ans, query(rt<<1, l, mid, ql, qr, val));
    else ans = min(ans, query(rt<<1 | 1, mid+1, r, ql, qr, val));
    //else if(qr > mid) ans = min(ans, query(rt<<1 | 1, mid+1, r, ql, qr, val));
    return ans;
}
void update(int rt, int l, int r, int pos, int val){
    if(l==r && l==pos){
        SegTree[rt] += val;
        return;
    }
    int mid = l+r>>1;
    if(mid >= pos) update(rt<<1, l, mid, pos, val);
    else update(rt<<1 | 1, mid+1, r, pos, val);
    SegTree[rt] = min(SegTree[rt<<1], SegTree[rt<<1|1]);
}
void build(int rt, int l,int r){
    if(l==r){
        SegTree[l] = 0;
        return;
    }
    int mid = l+r>>1;
    build(rt<<1, l, mid);
    build(rt<<1 | 1, mid+1, r);
    SegTree[rt] = 0;
}
int main(){
    scanf("%d", &t);
    while(t--){
        ans2 = 0;
        scanf("%d%d", &n, &c);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        build(1, 1, n);
        for(int i = 1;i <= n;i++){
            int q = query(1, 1, n, 1, n, a[i]);
            ans2 = max(ans2, q);
            update(1, 1, n, q, a[i]);
        }
        solve();
    }
    return 0;
}