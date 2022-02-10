#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
typedef long long ll;

int t;
double a, b, r;
double dist(double a, double b, double c, double d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int main(){
    cin >> t;
    for(int i = 1; i <= t; ++ i){
        cin >> a >> b >> r;
        double res = 0;
        if(b - r > 0){
            res += dist(0, 0, a, b - r);
            double temp = dist(a, b - r, 2 * a, 0);
            if(temp >= r){
                res += temp - r;
            }
        }
        else{
            double temp = dist(0, 0 , 2 * a, 0);
            if(temp >= r){
                res += temp - r;
            }
        }
        printf("Case #%d: %.2lf\n", i, res);
    }
    
    return 0;
}