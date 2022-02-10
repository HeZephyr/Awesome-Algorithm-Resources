/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-10 20:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int cnt[N];
void solve(){
    //判断进行了多少次同或，多少次异或。

}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1, x; i <= n; ++ i){
        scanf("%d", &x);
        for(int j = k - 1; j >= 0; -- j){
            cnt[j] += ((x >> j) & 1);
        }
    }
    solve();
    return 0;
}