#include<bits/stdc++.h>
#define map unordered_map
using namespace std;
const int maxn = 2100;
struct Point{
    double x, y;
}a[maxn];
map<double , int> map1[maxn];
map<int , int> map2; // 斜率不存在
map<double, int>mapa;
map<double, int>map3;//当前斜率是否被计算
void calc(Point s1, Point s2, int i){
    if(s1.x == s2.x){
        map2[i]++;
    }
    else{
        double k = (s1.y - s2.y) / (s1.x - s2.x);
        map1[i][k]++;
    } 
}
int calc(Point s1, Point s2){
    if(s1.x == s2.x){
        return 1;
    }
    else{
        double k = (s1.y - s2.y) / (s1.x - s2.x);
        mapa[k]++;
        return 0;
    } 
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i){
        scanf("%lf %lf", &a[i].x, &a[i].y);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            calc(a[i], a[j], i);
        }
    }
    while(q--){
        double x, y;
        scanf("%lf %lf", &x, &y);
        int sum = 0;//与A斜率不存在
        mapa.clear();
        for(int i = 1; i <= n; ++i){
            sum += calc(Point{x, y}, a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){// A为直角点时
            double xx = a[i].x, yy = a[i].y;
            if(xx == x){
                ans += mapa[0];
            }
            else {
                double k = (yy - y) / (xx - x);
                if(k == 0)ans += sum;
                else ans += mapa[-1.0 / k];
            }
            //cout << ans << endl;
        }
        ans /= 2;
        for(int i = 1; i <= n; ++i){//A为非直角点时
            double xx = a[i].x, yy = a[i].y;
            if(xx == x)ans += map1[i][0];
            else {
               double k = (yy - y) / (xx - x);
                if(k == 0)ans += map2[i];
                else {
                    ans += map1[i][-1.0 / k];
                }
            }
            //cout << ans << endl;
        }
        printf("%d\n", ans);
    }
}