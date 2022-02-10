#include<bits/stdc++.h>
const int maxn = 3e4 + 7;
using namespace std;
int mark[maxn];
int prime[maxn];
void orl(int n){
    mark[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(!mark[i]){
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0]; ++j){
            int x = prime[j] * i;
            if(x > n)break;
            mark[x] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1)ans *= n;
        n *= n;
        q >>= 1;
    }
    return ans;
}
double dp[4000][maxn];
double max(double x, double y){return x < y ? y : x;}; 
double calc(int W){
    for(int i = 1; i <= 550; ++i){
        for(int j = 0; j <= W; ++j){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for(int k = 1; ksm(prime[i], k) <= j; ++k){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - ksm(prime[i], k)] + log(ksm(prime[i], k)));
            }
        }
    }
    return dp[prime[0]][W];
}
int main(){
    orl(3e4);
    //ofstream file("data.txt");
    //freopen("data.txt", "w", stdout);
    //printf("%d\n", prime[0]);
    calc(3e4);
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%.8lf\n", dp[550][n]);
    } 
    return 0;
}