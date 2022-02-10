#include<bits/stdc++.h>

using namespace std;
using pdi = pair<double, int>;

const int N = 1e5 + 10;

int n;
double y[N];
pdi dp[N][3];//0次，1次，2次。
double dist(int i, int j){
    return sqrt(1.0 * (j - i) * (j - i) + (y[j] - y[i]) * (y[j] - y[i]));
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lf", &y[i]);
    }
    dp[1][1].first = 0, dp[1][1].second = 0;
    dp[1][2].first = dist(0, 1), dp[1][2].second = 1;
    for(int i = 2; i <= n; ++ i){
        if(i == 2){
            //特殊处理dp[2][0]。
            dp[2][0].first = 0, dp[2][0].second = 0;
        }
        else{
            //dp[i][0]由dp[i - 1][1]和dp[i - 1][0]转移。
            dp[i][0].first = dp[i - 1][0].first + dist(i, dp[i - 1][0].second);
            dp[i][0].second = i;
            if(dp[i - 1][1].first < dp[i][0].first){
                dp[i][0].first = dp[i - 1][1].first;
                dp[i][0].second = dp[i - 1][1].second;
            }
        }
        dp[i][1].first = dp[i - 1][1].first + dist(i, dp[i - 1][1].second);
        dp[i][1].second = i;
        if(dp[i - 1][2].first < dp[i][1].first){
            dp[i][1].first = dp[i - 1][2].first;
            dp[i][1].second = dp[i - 1][1].second;
        }
        dp[i][2].first = dp[i - 1][2].first + dist(i, i - 1);
        dp[i][2].second = i;
    }
    double res = dp[n][0].first + dist(n + 1, dp[n][0].second);
    printf("%.10lf\n", res);
    return 0;
}