/**
  *@filename:D1
  *@author: pursuit
  *@created: 2021-08-27 12:08
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,cnt[N];//cnt[i]表示i顶点被覆盖了多少次。
bool vis[N];//vis[i]表示线段i被使用过。
int l,r;
struct node{
    int l,r,id;
    bool operator < (const node &A){
        if(l == A.l)return r < A.r;
        return l < A.l;
    }
}a[N];
set<pii> s;
void solve(){
    sort(a + 1, a + n + 1);
    vector<int> res;
    int idx = 1;
    pii temp;
    for(int i = l; i <= r; ++ i){
        //将小于该界限的放入set集合中。
        while(idx <= n && a[idx].l <= i){
            s.insert({a[idx].r, a[idx].id});
            ++ idx;
        }
        //剔除过期元素。
        while(s.size() && s.begin() -> first < i){
            s.erase(s.begin());
        }
        while(s.size() > k){
            temp = *(-- s.end());
            res.push_back(temp.second);
            s.erase(temp);
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for(auto &x : res){
        printf("%d ", x);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &k);
    l = INF,r = 0;
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i].l, &a[i].r);
        r = max(a[i].r, r),l = min(a[i].l, l);
        a[i].id = i;
    }
    solve();
    return 0;
}