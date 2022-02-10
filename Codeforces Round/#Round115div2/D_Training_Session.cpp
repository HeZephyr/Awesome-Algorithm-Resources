/**
  *@filename:D_Training_Session
  *@author: pursuit
  *@created: 2021-10-10 17:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];//a和b元素的取值都为1.不存在ai = aj && bi = bj的情况。
//从中选择三个问题，其中三个问题主题不一样，三个问题难度也不一样。问方案数。
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        vector<int> cntA(n + 1, 0), cntB(n + 1, 0);
        int x;
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d", &a[i], &b[i]);
            ++ cntA[a[i]];
            ++ cntB[b[i]];
        }
        ll res = 1LL * n * (n - 1) * (n - 2) / 6;
        for(int i = 1; i <= n; ++ i){
            res -= 1LL * (cntA[a[i]] - 1) * (cntB[b[i]] - 1);
        }
        printf("%lld\n", res);
    }
    return 0;
}