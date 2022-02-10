#include<bits/stdc++.h>
using ll = long long;
using namespace std;
double p1, p2, v1, v2, n, ans;
bool check(double x){
    double res, sum;
    if(v1*x >= 2*p1){
        res = v1*x-p1;
        //printf("res = %lf\n", res);
        sum = n-res + p2-res;
        if(sum/v2 < x) return true;
        sum = n-p2 + n-res;
        if(sum/v2 < x) return true;
    } else {
        res = (v1*x - p1)/2 + p1;
        //printf("res = %lf\n", res);
        sum = n-res + p2-res;
        if(sum/v2 < x) return true;
        sum = n-p2 + n-res;
        if(sum/v2 < x) return true;
    }
    return false;
}
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &p2, &v1, &v2);
        double l = 0.0, r = 1000000000.0;
        while(r-l > 1e-7){
            double mid = (l+r)/2;
            printf("%lf %lf %lf\n", l, mid, r);
            if(check(mid)){
                ans = mid;
                r = mid;
            }
            else l = mid;
        }
        cout<<ans<<endl;
        printf("%.8lf\n", ans);
    }
    return 0;
}
