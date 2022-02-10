/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-15 18:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//有n + 1个检查站，从0到n。相邻两个检查点有m条不同的路径供选择。
int t, n, m, tot;
struct node{
    int w, i, j;
    bool operator < (const node &A){
        return w < A.w;
    }
}a[N * N];
int b[N][N];
void solve(){
    sort(a + 1, a + tot + 1);
    //前m个即为答案，由于i是固定了，j可以交换。
    for(int k = 1; k <= m; ++ k){
        //交换到k这个人上来，即j = k。
        int i = a[k].i, j = a[k].j;
        swap(b[i][j], b[i][k]);
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            printf("%d ", b[i][j]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        tot = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                scanf("%d", &b[i][j]);
                a[++ tot] = {b[i][j], i, j};
            }
        }
        solve();
    }
    return 0;
}