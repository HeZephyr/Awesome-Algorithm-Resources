/**
  *@filename:三角形面积
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 21:39
**/
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<double,double> pdd;
typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

pdd points[3];
double dist(pdd a,pdd b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)); 
}
void solve(){
    //已知三条边计算三角形的面积，可以利用海伦公式，也可以使用叉积公式。
    //海伦公式：S=sqrt(p*(p-a)*(p-b)*(p-c))，其中p=(a+b+c)/2
    double a=dist(points[0],points[1]),b=dist(points[1],points[2]),c=dist(points[0],points[2]);
    double p=(a+b+c)/2;
    printf("%.03f\n",sqrt(p*(p-a)*(p-b)*(p-c)));
    //叉积公式
    printf("%.03f\n",0.5*abs((points[1].x-points[0].x)*(points[2].y-points[0].y)-(points[1].y-points[0].y)*(points[2].x-points[0].x)));
    //8.795

}
int main(){
    for(int i=0;i<3;i++){
        cin>>points[i].x>>points[i].y;
    }
    solve();
    return 0;
}