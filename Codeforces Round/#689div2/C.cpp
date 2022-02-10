/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-18 17:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,m,a[N];//m次实验。
struct node{
    int r;
    double p;
}op[N];
void solve(){
    int r;
    for(int i = n; i >= 1; -- i){
        r = i;
        if(a[i] != i)break;//说明这里出现不相等的情况。
    }
    if(r == 1){
        //说明是全部相等
        printf("%.8lf\n", 1.0);
    }
    else{
        double cnt = 1.0;
        //只有后面的对其才会有影响。
        for(int i = 1; i <= m; ++ i){
            if(op[i].r >= r){
                cnt = cnt * (1.0 - op[i].p);
            }
        }
        printf("%.8lf\n", 1.0 - cnt);
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d%lf", &op[i].r, &op[i].p);
        }
        solve();
    }
    return 0;
}