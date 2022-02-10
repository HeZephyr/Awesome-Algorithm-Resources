/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-09-01 17:56
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
map<int, int> p;
void solve(){
    p[n + 1] = 3;
    int x = 0, y = 3;//x代表前一列，y代表前一列的状态。
    for(auto iter : p){
        int a = iter.first, b = iter.second;
        if(b == 3){
            //由于该行为3已填满，判断前一行是否填满。
            if(y != 3){
                puts("NO");
                return;
            }
            x = a;
        }
        else if(b == 1){
            //由于b = 1，所以如果前一列已经填满，则无法通过前一列，所以这里需要通过后一列，则
            //后移一位判断。
            if(y == 3){
                x = a + 1, y = 2;
            }
            else if((y == 1 && (x - a) % 2 == 0) || (y == 2 && (x - a) % 2 != 0)){
                puts("NO");
                return;
            }
            else{
                x = a, y = 3;
            }
        }
        else if(b == 2){
            if(y == 3){
                x = a + 1, y = 1;
            }
            else if((y == 2 && (x - a) % 2 == 0) || (y == 1 && (x - a) % 2 != 0)){
                puts("NO");
                return;
            }
            else{
                x = a, y = 3;
            }
        }
    }
    puts("YES");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        p.clear();
        scanf("%d%d", &n, &m);
        int r, c;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &r, &c);
            p[c] += r;
        }
        solve();
    }
    return 0;
}