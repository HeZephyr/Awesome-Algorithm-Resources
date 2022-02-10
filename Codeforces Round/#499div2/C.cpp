/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-10-27 19:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, a[N], b[N];
void solve(){
    double res = m;
    bool flag1 = false, flag2 = true;
    for(int i = n + 1; i > 1; -- i){
        //从i降落，i - 1起飞。
        if(b[i] == 1 || a[i - 1] == 1){
            flag1 = true;
            res = 1e9;
            break;
        }
        double y = res / (b[i] - 1);
        res += y;
        y = res / (a[i - 1] - 1);
        res += y;
    }
    double temp = m;
    for(int i = 1; i <= n; ++ i){
        //从i降落，i + 1起飞。
        if(b[i] == 1 || a[i + 1] == 1){
            temp = 1e9;
            flag2 = true;
            break;
        }
        double y = temp / (b[i] - 1);
        temp += y;
        y = temp / (a[i + 1] - 1);
        temp += y;
    }
    res = min(res, temp);
    if(flag1 && flag2)puts("-1");
    else printf("%.10lf\n", res - m);
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        b[i + n] = b[i];
    }
    solve();
    return 0;
}