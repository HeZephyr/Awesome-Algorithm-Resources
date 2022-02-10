/**
  *@filename:J
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-26 13:51
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,m,x,y;
double a[N],sum[N];
double solve(int n,int len){
    //len为区间最小长度。
    for(int i = 1; i <= n; ++ i){
        scanf("%lf", &a[i]);
    }
    double l = -1e5,r = 1e5,mid;
    while(r - l > 1e-7){
        mid = (l + r) / 2.0;
        //cout << mid << " ";
        for(int i = 1; i <= n; ++ i){
            sum[i] = sum[i - 1] + a[i] - mid;
        }
        double minn = 1e6,maxx = -1e6;
        for(int i = len; i <= n; ++ i){
            minn = min(minn,sum[i - len]);//不断维护左端最小值。
            maxx = max(maxx,sum[i] - minn);//相减得到最大值。
        }
        if(maxx >= 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}
int main(){
    scanf("%d%d%d%d", &n, &m, &x, &y);
    printf("%.8lf\n",solve(n,x) + solve(m,y));
    return 0;
}