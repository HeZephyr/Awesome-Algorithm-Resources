#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-7;
int t;
double r, h;
double x0, y0, z0, vx, vy, vz;
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%lf%lf", &r, &h);
        scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &z0, &vx, &vy, &vz);
        printf("Case %d: ", k);
        double a = vx * vx * h * h + vy * vy * h * h - r * r * vz * vz; 
        double b = 2 * x0 * vx * h * h + 2 * y0 * vy * h * h + 2 * h * vz * r * r - 2 * z0 * vz * r * r;
        double c = x0 * x0 * h * h + y0 * y0 * h * h - r * r * h * h - r * r * z0 * z0 + 2 * h * z0 * r * r;
        double d = sqrt(b * b - 4 * a * c);
        double t1 = (-b + d) / 2 / a, t2 = (-b - d) / 2 / a;
        //printf("%.10lf %.10lf\n", t1, t2);
        if(t1 < 0){
            printf("%.10lf\n", t2);
        }
        else if(t2 < 0){
            printf("%.10lf\n", t1);
        }
        else{
            if(t1 > t2)swap(t1, t2);
            double z = z0 + t1 * vz;
            if(z >= 0 && z <= h){
                printf("%.10lf\n", t1);
            }
            else{
                printf("%.10lf\n", t2);
            }
        }
    }
    return 0;
}