/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 19:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

struct point{
    double x,y,z;
}points[4];
double dist(point a,point b){
    double dx = a.x - b.x,dy = a.y - b.y,dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
void solve(){
    double p,q,l,r,m,n;
    p = dist(points[0],points[1]);
    q = dist(points[0],points[2]);
    l = dist(points[0],points[3]);
    r = dist(points[1],points[2]);
    m = dist(points[1],points[3]);
    n = dist(points[2],points[3]);
    double s1 = p * p + q * q - r * r;
    double s2 = q * q + l * l - n * n;
    double s3 = l * l + p * p - m * m;
    double ans = 4 * p * p * q * q * l * l + s1 * s2 * s3 - q * q * s3 * s3 - l * l * s1 * s1 - p * p * s2 * s2;
    printf("%.4lf\n",sqrt(ans / 144));
}
int main(){
    for(int i = 0; i < 4; ++ i){
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    solve();
    return 0;
}