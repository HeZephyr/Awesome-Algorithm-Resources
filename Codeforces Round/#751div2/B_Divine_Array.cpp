/**
  *@filename:B_Divine_Array
  *@author: pursuit
  *@created: 2021-10-25 14:38
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[2][N], q;
int res[N], cnt[N];
struct node{
    int id, x, k;
    bool operator < (const node &A){
        return k < A.k;
    }
}b[N];
bool check(){
    for(int i = 1; i <= n; ++ i){
        if(a[0][i] != a[1][i]){
            return false;
        }
    }
    return true;
}
void solve(){
    sort(b + 1, b + 1 + q);
    int ans = 0, idx = 1, op = 0;
    while(true){
        while(idx <= q && ans == b[idx].k){
            res[b[idx].id] = a[op][b[idx].x];
            ++ idx;
        }
        //cout << idx << " ";
        if(idx > q)break;
        ++ ans;
        for(int i = 1; i <= n; ++ i){
            a[op ^ 1][i] = cnt[a[op][i]];
        }
        if(check()){
            for(int i = idx; i <= q; ++ i){
                res[b[i].id] = a[op][b[i].x];
            }
            break;
        }
        op ^= 1;
        for(int i = 1; i <= n; ++ i)cnt[i] = 0;
        for(int i = 1; i <= n; ++ i){
            cnt[a[op][i]] ++;
        }
    }
    for(int i = 1; i <= q; ++ i){
        printf("%d\n", res[i]);
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[0][i]);
            a[1][i] = 0;
            ++ cnt[a[0][i]];
        }
        scanf("%d", &q);
        for(int i = 1; i <= q; ++ i){
            scanf("%d%d", &b[i].x, &b[i].k);
            b[i].id = i;
        }
        solve();
    }
    return 0;
}