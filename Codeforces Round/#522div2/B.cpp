/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-31 13:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,len;
char s[N];
void solve(){
    //确定行列即可。
    len = strlen(s + 1);
    for(n = 1; n <= 5; ++ n){
        m = len / n + (len % n != 0);
        if(n <= 5 && m <= 20)break;
    }
    int cnt = n * m - len, idx = 1;//需要填充的*号。
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m - (cnt != 0); ++ j){
            printf("%c", s[idx ++]);
        }
        if(cnt){
            printf("*");
            -- cnt;
        }
        puts("");
    }
}
int main(){	
    scanf("%s", s + 1);
    solve();
    return 0;
}