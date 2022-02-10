/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-11 10:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
void solve(){
    vector<int> ans(n + 1,1);//先定义所有的因子都为1.
    for(int i = 2; i <= n; ++ i){
        for(int j = i * 2; j <= n; j += i){
            //将i的倍数都找出来。
            ans[j] = i;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 2; i <= n; ++ i){
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
}
int main(){	
    scanf("%d", &n);
    solve();
    return 0;
}