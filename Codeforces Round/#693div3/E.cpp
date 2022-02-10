/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 09:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 400000 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int t,n;
struct node{
    int h, w, id;
    bool operator < (const node &A){
        //由于等于的明显不行了，所以我们为了区分，设置w > a.w利于区分。相同级的。
        return h == A.h ? w > A.w : h < A.h;
    }
}a[N];
int tot,ans[N];
void solve(){
    sort(a + 1,a + 1 + tot);
    memset(ans, -1, sizeof(ans));
    int minn = INF, pos;//保存前面最小的w。由于h一定是最小的了。
    for(int i = 1; i <= tot; ++ i){
        if(a[i].w > minn){
            ans[a[i].id] = pos;
        }
        else{
            pos = a[i].id, minn = a[i].w;
        }
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d ", ans[i]);
    }
    puts("");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        int h,w;
        tot = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d", &h, &w);
            a[++ tot].h = h, a[tot].w = w, a[tot].id = i;
            a[++ tot].h = w, a[tot].w = h, a[tot].id = i;
        }
        solve();
    }
    return 0;
}