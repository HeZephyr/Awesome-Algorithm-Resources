#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e7 + 10;
const int P = 998244353;
ll fib[35];
map<pair<int, int>, ll> dp;
int main(){
    fib[1] = fib[2] = 1ll;
    for(int i = 3;i <= 35;i++){
        fib[i] = (fib[i-1]+fib[i-2])%P;
    }
    dp[{1, 1}] = 2;
    for(int i = 2;i <= 35;i++){
        for(int j = 1;j <= 100;j++){
            dp[{i,j}] = dp[{i-1, j}];
            if(j-fib[i]>=1){
                printf("i = %d %d\n", i ,j);
                dp[{i,j}] = dp[{i-1, j-fib[i]}] * fib[i] %P;
            }
        }
    }
    for(int j = 1;j <= 100;j++){
        printf("%lld\n", dp[{35, j}]);
    }
    return 0;
}