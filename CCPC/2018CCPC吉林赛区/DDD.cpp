#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-12;
int t;
double p, res;
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        res = 0;
        //memset(dp, 0, sizeof(dp));
        scanf("%lf", &p);
        p = p * 0.01;
        printf("Case %d: ", k);
        for(int i = 1; i <= 100; ++ i){
            //第i场赢。
        }
        printf("%.10lf\n", res);
    }
    return 0;
}