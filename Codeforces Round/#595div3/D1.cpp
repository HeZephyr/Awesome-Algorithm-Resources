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
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,cnt[N];//cnt[i]表示i顶点被覆盖了多少次。
bool vis[N];//vis[i]表示线段i被使用过。
int l,r;
struct node{
    int l,r,id;
    bool operator < (const node &A){
        if(l == A.l){
            return r < A.r;
        }
        return l < A.l;
    }
}a[N];
bool check(int x){
    for(int i = a[x].l; i <= a[x].r; ++ i){
        if(cnt[i] + 1 > k){
            //此时超过了。
            return false;
        }
    }
    vis[x] = true;
    for(int i = a[x].l; i <= a[x].r; ++ i){
        ++ cnt[i];
    }
    return true;
}
void solve(){
    sort(a + 1, a + n + 1);
    vector<int> res;
    int cur = 0;//保存当前能用的线段中右端点最右的线段。
    for(int i = 1; i <= n; ++ i){
        if(check(i)){
            if(i == 1)cur = 1;
            else if(a[i].r >= a[cur].r)cur = i;
        }
        else{
            //删除右端点最右的线段。
            if(a[i].r > a[cur].r)continue;
            vis[cur] = false, vis[i] = true;
            for(int j = a[cur].l; j <= a[cur].r; ++ j){
                -- cnt[j];
            }
            for(int j = a[i].l; j <= a[i].r; ++ j){
                ++ cnt[j];
            }
            //更新右端点。
            int maxx = 0;
            for(int j = 1; j <= i; ++ j){
                if(vis[j] && a[j].r >= maxx){
                    maxx = a[j].r, cur = j;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        if(!vis[i]){
            res.push_back(a[i].id);
        }
    }
    printf("%d\n", (int)res.size());
    sort(res.begin(), res.end());
    for(auto &x : res){
        printf("%d ", x);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i;
    }
    solve();
    return 0;
}