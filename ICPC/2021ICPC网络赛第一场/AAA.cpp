#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
int SegTree[N], vis[N], mp[N];
int query(int root, int l, int r, int ql, int qr, int val){
    if(SegTree[root] > val){
        return INT_MAX;
    }
    if(l==r){
        mp[l] = root;
        printf("l = %d\n", l);
        return l;
    }
    int mid = l+r>>1, ans = INT_MAX;
    if(mid >= l) {
        int ans = min(ans, query(root<<1, l, mid, ql, qr, val));
        if(ans != INT_MAX){
            return ans;
        }
    }
    if(mid < r){
        return query(root<<1 | 1, mid+1, r, ql, qr, val);
    }
    return INT_MAX;
}
void update(int root, int val){
    if(!root) return;
    SegTree[root] = min(SegTree[root], val);
    update(root>>1, val);
}
int main(){
    int k, n, st, time, x, Max = -1;
    scanf("%d%d", &k, &n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &st, &time);
        printf("i = %d\n", i);
        if(i%k){
            x = query(1, 1, 2*k, i%k, i+k-1, st);
            printf("1x = %d\n", x);
            if(x != INT_MAX){
                vis[x]++;
                Max = max(Max, vis[x]);
                update(mp[x], st+time);
                update(mp[x+k-1], st+time);
            }
        } else {
            x = query(1, 1, 2*k, i%k, i+k-1, st);
            printf("2x = %d\n", x);
            if(query(1, 1, 2*k, k, 2*k-1, st) != INT_MAX){
                vis[x]++;
                Max = max(Max, vis[x]);
                update(mp[x], st+time);
                update(mp[x+k-1], st+time);
            }
        }
    }
    printf("YES Max = %d\n", Max);
    vector<int> v;
    for(int i = 1;i <= n;i++){
        if(vis[i]==Max) v.push_back(i);
    }
    for(int i = 0;i < v.size();i++){
        printf("%d", v[i]-1);
        if(i!=v.size()-1) printf(" ");
    }
    return 0;
}