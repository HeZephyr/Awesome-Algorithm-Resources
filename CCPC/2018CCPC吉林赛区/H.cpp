#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
struct T_node{
    int l, r;
    ull sum1, sum2;
    ull mark;
    int cnt;
}T[maxn << 2];
int id[maxn];
ll pow_10[maxn];
void pushup(int k){
    T[k].sum1 = (T[k << 1].sum1 + T[k << 1 | 1].sum1)% mod;
    T[k].sum2 = (T[k << 1].sum2 + T[k << 1 | 1].sum2)% mod;
    T[k].cnt = max(T[k << 1].cnt, T[k << 1 | 1].cnt);
}
int getbit(ll x){
    int cnt = 0;
    while(x){
        x/=10;
        cnt++;
    }
    return cnt;
}
void pushdown(int k){
    if(!T[k].mark)return ;
    int cnt = getbit(T[k].mark);
    T[k << 1].sum = (T[k << 1].sum * pow_10[cnt] + T[k].mark * pow_10[T[k << 1].cnt + cnt]%mod) % mod;
    T[k << 1 | 1].sum = (T[k << 1 | 1].sum * pow_10[cnt] + T[k].mark * pow_10[T[k << 1 | 1].cnt + cnt]%mod) % mod;
    T[k << 1].mark = (T[k << 1].mark * pow_10[cnt] + T[k].mark) % mod;
    T[k << 1 | 1].mark = (T[k << 1 | 1].mark * pow_10[cnt] + T[k].mark) % mod;
    T[k].mark = 0;
    T[k << 1].cnt += cnt;
    T[k << 1 | 1].cnt += cnt;
}
void build(int k, int l, int r){
    T[k].l = l, T[k].r = r;
    T[k].sum = T[k].cnt = T[k].mark = 0;
    if(l == r){
        id[l] = k;
        return ;
    }
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
ll query(int k, int L, int R){
    int l = T[k].l, r = T[k].r;
    //cout<< k << endl;
    if(L <= l && r <= R){
        return T[k].sum;
    }
    pushdown(k);
    int mid = l + r >> 1;
    ll sum = 0;
    if(L <= mid)sum = (sum + query(k << 1, L, R)) % mod;
    if(R > mid)sum = (sum + query(k << 1 | 1, L, R)) % mod;
    pushup(k);
    return sum;
}
void update(int k, int L, int R, ll x){
    int l = T[k].l, r = T[k].r;
    if(L <= l && r <= R){
        T[k].cnt ++;
        T[k].mark = (10 * T[k].mark + x)% mod;
        T[k].sum = (10 * T[k].sum + x) % mod;
        T[k].sum = (T[k].sum + pow_10[T[k].cnt * 2 + 1] * x) % mod;
        return ;
    }
    pushdown(k);
    int mid = l + r >> 1;
    if(L <= mid)update(k << 1, L, R, x);
    if(R > mid)update(k << 1 | 1, L, R, x);
    pushup(k);
}
int main(){
    int T;
    scanf("%d", &T);
    int Case = 0;
    pow_10[0] = 1;
    for(int i = 1; i <= 1e5; ++i)pow_10[i] = pow_10[i - 1] * 10 % mod;
    while(T--){
        int n, m;
        scanf("%d %d", &n,&m);
        build(1, 1, n);
        printf("Case %d:\n", ++Case);
        while(m--){
        	string opt;
        	int l, r;
        	ll x;
        	cin >> opt;
        	if(opt == "wrap"){
        	    scanf("%d %d %lld", &l, &r, &x);
        	    update(1, l, r, x);
        	}
        	else{
        	    scanf("%d %d", &l, &r);
        	    printf("%llu\n", query(1, l, r) % mod);
        	}
		} 
        
    }
}