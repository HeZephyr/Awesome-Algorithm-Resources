#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const double PI = acos(-1);
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        double a, b, r, d;
        cin >> a >> b >> r >> d;
        d = d * PI / 180.0;
        if(d >= atan(b / (a + r))){
            printf("%.9lf\n", sqrt((a + r) * (a + r) + b * b) - r);
        }
        else {
            double x = (a + r) * tan(d);
            double y = (a + r) / cos(d);
            //cout << x << y << endl;
            double ans = y + (b - x) * sin(d);
            ans -= r;
            printf("%.9lf\n", ans);
        }
    }
}