#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
int k, n;
struct tree_node{
    int l, r;
    int id;
    int w;
    int minnum;
}T[N << 2];
int a[N<<1];
int b[N];
void pushup(int k){
    T[k].minnum = min(T[k<<1].minnum, T[k<<1|1].minnum);
    if(T[k<<1|1].minnum == INT_MAX)T[k].minnum = T[k<<1].minnum;
    if(T[k<<1].minnum == INT_MAX)T[k].minnum = T[k<<1|1].minnum;
}
void build(int k,int l,int r){
    T[k].l = l, T[k].r = r;
    T[k].minnum = INT_MAX;
    if(l == r){
        T[k].w = a[l];
        T[k].id = l;
        T[k].minnum = a[l];
        return ;
    }
    int mid = (l + r)>>1;
    build(k<<1, l, mid);
    build(k<<1|1, mid + 1, r);
    pushup(k);
}
int ansflag, ans;
void find(int k,int L,int R,int x){
    //printf("%d:%d\n",k,T[k].minnum);
    if(ansflag)return ;
    int l = T[k].l, r = T[k].r;
    //printf("%d %d\n", k, T[k].minnum);
    if(l == r){
        ansflag = 1;
        ans = T[k].id;
        return ;
    }
    int mid = (l + r)>>1;
    if(mid >= L){
        if(x >= T[k<<1].minnum)find(k<<1, L, R, x);
        //printf("%d %d\n",x,T[k].minnum);
        if(ansflag)return;
    }
    if(mid < R){
        if(x >= T[k<<1|1].minnum)find(k<<1|1, L, R, x);
        if(ansflag)return;
    }
}
void update(int k,int x,int w){
    int l = T[k].l, r = T[k].r;
    if(l == r){
        T[k].minnum = w;
        return;
    }
    int mid = (l + r)>>1;
    if(x <= mid)update(k<<1, x, w);
    else update(k<<1|1, x, w);
    pushup(k);
}
int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; ++i){
        int x, t;
        scanf("%d %d", &x, &t);
        if(i < k){
           a[i] = a[i + k] = x + t; 
           b[i] = 1;
        }
        else {
            if(i == k)build(1, 0, k * 2 - 1);
            int id = i % k;
            //printf("%d\n",id);
            ans = ansflag = 0;
            find(1, id, id + k, x);
            //printf("%d %d\n",ansflag, ans);
            if(ansflag){
                update(1, ans, x + t);
                a[ans] = x + t;
                update(1, ans + k, x + t);
                a[ans + k] = x + t;
                b[ans] ++;
            }
            
        }
    }
    int maxans = 0;
    for(int i = 0; i < k; ++i){
        maxans = max(maxans, b[i]);
    }
    vector<int> res;
    for(int i = 0; i < k; ++i){
        if(maxans == b[i])res.push_back(i);
        //printf("%d ",b[i]);
    }
    for(int i = 0; i < res.size(); ++ i){
        printf("%d", res[i]);
        if(i != res.size() - 1)printf(" ");
    }
    return 0;
}