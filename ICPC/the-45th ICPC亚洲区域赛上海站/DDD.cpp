/**
  *@filename:DDD
  *@author: pursuit
  *@created: 2021-10-08 14:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//A位于p1，速度为v1，B位于p2，速度为v2.它们随时都可以改变方向
int t;
double n, p1, v1, p2, v2;
double cal(double n, double p, double v){
    return min(n - p + n, p + n) / v;
}
void solve(){
    //一个人走完全程。
    double res = min(cal(n, p1, v1), cal(n, p2, v2));
    if(p1 > p2)swap(p1, p2), swap(v1, v2);
    //沿着对方走，这样相对也能走完全程。
    res = min(res, max(p2 / v2, (n - p1) / v1));
    //二分相遇的位置。
    double l = p1, r = p2, mid;
    while(r - l > 1e-10){
        mid = (l + r) / 2;
        double res1 = cal(mid, p1, v1), res2 = cal(n - mid, p2 - mid, v2);
        res = min(res, max(res1, res2));
        if(res1 > res2){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    printf("%.10f\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
        solve();
    }
    return 0;
}