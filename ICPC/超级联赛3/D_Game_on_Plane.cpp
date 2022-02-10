/**
  *@filename:D_Game_on_Plane
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 09:14
**/
#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
int f[N];
pii v[N];
void solve(){
    sort(v + 1,v + 1 + n);
    memset(f,0,sizeof(f));
    int i,j,k;
    for(i = 1; i <= n; i = j){
        for(j = i; j <= n && v[i] == v[j]; ++ j){
            //计算从i开始有几条斜率相同的直线。
        }
        for(k = 1; k <= j - i; ++ k){
            f[k] ++;
        }
    }
    for(i = j = 1; i <= n; ++ i){
        //i为可选择的直线数。
        while(!f[j]){
            j ++;
        }
        f[j] --;
        printf("%d\n", i - j);
    }
}
int main(){
    scanf("%d", &t);
    pii a,b;
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
            int dx = a.x - b.x,dy = a.y - b.y;
            if(dx == 0){
                //说明是垂直的。
                dy = 1;
            }
            else if(dy == 0){
                //说明是水平的。
                dx = 1;
            }
            else{
                //将dx，dy统一化。
                if(dx < 0){
                    dx = -dx, dy = -dy;
                }
                int gcd = __gcd(abs(dx),abs(dy));
                dx /= gcd, dy /= gcd;
            }
            v[i] = pii(dx,dy);
        }
        solve();
    }
    return 0;
}