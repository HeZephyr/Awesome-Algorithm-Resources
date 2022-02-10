/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-07 09:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, q, k, a[N], diff[N], sum[N];
void solve(){
    int l, r;
    while(q -- ){
        scanf("%d%d", &l, &r);
        //l 和 r可以往l - 1和r + 1那靠。
        int x = (sum[r] - sum[l]) * 2;
        x += a[l] - 1 + k - a[r];
        printf("%d\n", x);
    }
}
int main(){	
    scanf("%d%d%d", &n, &q, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        diff[i] = a[i] - a[i - 1] - 1;//判断可供选择空间。
        sum[i] = sum[i - 1] + diff[i];
    }
    solve();
    return 0;
}