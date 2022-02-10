/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-07 10:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e2 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, a[N][N];
void solve(){
    int lcm = 1;
    for(int i = 2; i <= 16; ++ i){
        lcm = i * lcm / __gcd(i, lcm);
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if((i + j) & 1){
                printf("%d ", lcm);
            }
            else{
                printf("%d ", lcm + (int)pow(a[i][j], 4));
            }
        }
        puts("");
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}