/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 18:49
**/
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<double,double> pdd;
const int N = 100000 + 5;
const double EPS = 1e-8;
const int P = 1e9+7;

double r;
int n;
pdd points[110];
double getDist(pdd a,pdd b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
pdd getCenter(pdd a, pdd b){
    pdd mid = {(a.x + b.x) / 2, (a.y + b.y) / 2};
    double w = atan2(a.x - b.x,b.y - a.y);//计算正切值。
    double d = sqrt(r * r - getDist(a,mid) * getDist(a,mid));
    return {mid.x + d * cos(w),mid.y + d * sin(w)};
}
void solve(){
    int maxx = 1;
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            if(getDist(points[i],points[j]) > 2 * r)continue;
            pdd cen = getCenter(points[i],points[j]);
            int cnt = 0;
            for(int k = 1; k <= n; ++ k){
                if(getDist(points[k],cen) < r + EPS)cnt ++;//注意精度问题，在计算过程中可能会损失精度，我们需要加上一个精度控制。
            }
            maxx = max(cnt,maxx);
        }
    }
    cout << maxx << endl;
}
int main(){
    cin >> r;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> points[i].x >> points[i].y;
    }
    solve();
    return 0;
}