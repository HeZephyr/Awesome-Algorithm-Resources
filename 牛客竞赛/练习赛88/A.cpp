/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-10 19:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a, b, n;
char s[N];
pii g[] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 1}, {1, 0}, {1, 1}, {1, 2}, {1, 3}};
void solve(){
    if(a + b <= n){
        //此时不需要拼接，直接按最大来即可。
        while(a -- ){
            printf("5");
        }
        while(b -- ){
            printf("1");
        }
    }
    else{
        //此时需要拼接。凑往高位凑。
        int idx = 0;
        for(int i = 8; i >= 1; -- i){
            while(true){
                int x = g[i].first, y = g[i].second;
                //cout << x << " " << y << endl;
                if(n == 0)break;
                if(a < x || b < y || a + b - x - y + 1 < n){
                    break;
                }
                s[idx ++] = i + '0';
                a -= x, b -= y;
                -- n;
            }
        }
        s[idx] = '\0';
        printf("%s", s);
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &a, &b, &n);
        solve();
    }
    return 0;
}