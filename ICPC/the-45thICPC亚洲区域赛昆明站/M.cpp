#include<bits/stdc++.h>
#define ll long long 

using namespace std;

const int maxn = 2e5 + 7;
struct T_node {
    int l, r;
    int L, R;
    ll x;
}T[maxn * 40];
int root[maxn << 5];
int a[maxn];
vector<int >b;
int idx;
int n;
void build(int k, int &t, int l, int r) {
    t = ++idx;
    if (l == r){
        return ;
    }
    int mid = (l + r) >> 1;
    build(k << 1, T[t].l, l, mid);
    build(k << 1 | 1, T[t].r, mid + 1, r);
}

int find(int x){//离散化后的编号
    return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}

void insert(int &t,int pre, int l, int r, int pos, int num) {
    t = ++idx;
    T[t] = T[pre];
    if (l == r) {
        T[t].L = T[t].R = num;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        insert(T[t].l, T[pre].l, l, mid, pos, num);
    else insert(T[t].r, T[pre].r, mid + 1, r, pos, num);
}

ll query(int p, int q, int l, int r, int k) {

}
