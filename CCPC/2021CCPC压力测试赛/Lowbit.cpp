/**
  *@filename:Lowbit
  *@author: pursuit
  *@created: 2021-09-04 13:07
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], m;
int sum[N], lazy[N], flag[N];//flag[i]表示结点i的所有点是不是只剩一个1了。
void buildTree(int rt, int l, int r){
    
}
void solve(){
    memset(flag, false, sizeof(flag));
    mesmet(lazy, 0, sizeof(lazy));
    buildTree(1, 1, n);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        solve();
    }
    return 0;
}