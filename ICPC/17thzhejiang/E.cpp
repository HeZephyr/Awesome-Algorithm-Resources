#include<bits/stdc++.h>
#define ll long long 

using namespace std;

const int maxn = 1e5 + 7;
int L[maxn<<5], R[maxn<<5];
int sum[maxn<<5];
ll suma[maxn<<5];
int root[maxn<<5];
int a[maxn], b[maxn];
int idx;
int n;
void build(int t,int l,int r){
    if(!root[t])root[t] = ++idx;
    sum[root[t]] = 0;
    int mid = (l + r)>>1;
    if(l ^ r)build(L[root[t]], l, mid), build(R[root[t]], mid + 1, r);
}

int update(int pre, int l, int r, int num){
    int t = ++idx;
    L[t] = L[pre];
    R[t] = R[pre];
    sum[t] = sum[pre] + 1;
    suma[t] = suma[pre] + num;

    if(l ^ r){
        int mid = (l + r)>>1;
        if(num <= mid)L[t] = update(L[pre], l, mid, num);
        else R[t] = update(R[pre], mid + 1, r, num);
    }
    return t;
}

ll anssum;
int query(int x, int y, int l, int r, int k){
	//if(!k)return 0;
    if(l == r){
        if(k == 1)anssum += l;
        return l;
    }
    int mid = (l + r)>>1;
    int tmp = sum[R[y]] - sum[R[x]];
    //printf("%d\n",tmp);
    if(tmp <= k){
        anssum += suma[R[y]] - suma[R[x] - 1];
        //printf("x %d, y %d\n",x,y);
        return query(L[x], L[y], l, mid, k - tmp);
    }
    else return query(R[x], R[y], mid + 1, r, k);
}
ll sumi_2[maxn];

void init(){
    memset(suma, 0, sizeof(suma));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(sum, 0, sizeof(sum));
    memset(root, 0, sizeof(root));
    idx = 0;
}
int main(){
    int T;
    sumi_2[1] = 1;
    for(int i = 2; i <= maxn; ++i)
        sumi_2[i] = sumi_2[i - 1] + i * i;
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        build(1, 1, n);
        sort(b + 1, b + n + 1);
        int len = unique(b + 1, b + n + 1) - b - 1;
        for(int i = 1; i <= n; ++i){
            root[i] = update(root[i - 1], 1, len, lower_bound(b + 1, b + len + 1, a[i]) - b);
        }
        //printf("YES\n");
        int m;
        scanf("%d", &m);
        while(m--){
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            ll ans = sumi_2[r - l + 1];
            //printf("1:%d\n", r - l + 1);
            printf("%lld\n",ans);
            anssum = 0;
            int q = query(root[l - 1], root[r], 1, len, k);
            printf("%lld\n", ans + anssum);
        }
    }
}
/*
1
5
1 2 3 4 5
3
1 3 2
1 5 5
3 3 1
*/