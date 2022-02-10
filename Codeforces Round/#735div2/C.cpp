/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-05 17:04
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
void solve(){
    //由于n ^ i = k, 则k ^ n = i,那么如果能被异或得到，则一定是属于[0, m]。不符合的即是>m，则找最小的k ^ n > m
    ++ m;
    int res = 0;
    for(int i = 30; i >= 0; -- i){
        int u = (n >> i) & 1, v = (m >> i) & 1;
        if(u < v){
            res += 1 << i;
        }
        //如果已经符合条件则退出。
        if((res ^ n) >= m)break;
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        solve();
    }
    return 0;
}