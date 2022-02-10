/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-04 15:11
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
bool vis[N];
//更改序列中的任意一个整数只能改变一个点。
void solve(){
    //最小化序列中的序列次数。
    memset(vis, 0, sizeof(vis));
    int res = 0, ans = 0;
    for(int i = 2; i < n; ++ i){
        if((a[i] > a[i - 1] && a[i] < a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])){
            vis[i] = true;
            ++ ans;
        }
    }
    if(ans != 0){
        //说明出现了。我们可以进行至少进行修改使得减1。
        res = 1;
    }
    for(int i = 2; i < n; ++ i){
        if(vis[i]){
            if(vis[i - 1] && vis[i + 1]){
                res = 3;
                break;
            }
            else if(vis[i + 1]){
                if(i == 2 || i == n - 1){
                    res = 2;
                }
                else if(abs(a[i] - a[i - 1]) >= abs(a[i] - a[i + 1])){
                    res = 2;
                }
                else if(abs(a[i + 2] - a[i + 1]) >= abs(a[i] - a[i + 1])){
                    res = 2;
                }
                else if(a[i - 2] == a[i - 1] || a[i + 2] == a[i + 3]){
                    res = 2;
                }
            }
        }
    }
    printf("%d\n", ans - res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}