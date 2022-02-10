#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, T[N];
int sum;
int dp[N];
//如果两个克隆体可以共存，那么必然有一个属性A大于B，另一个A小于B。则如果他们的属性值的和sum相同的话，就一定可以共存。这一点很容易证明。
void solve(){
    dp[0] = 1;
    for(int i = 1; i <= n; ++ i){
        for(int j = sum; j > 0; -- j){
            //枚举该点的体积。
            for(int k = 1; k <= j && k <= T[i]; ++ k){
                dp[j] = (dp[j] + dp[j - k]) % P;
            }
        }
    }
    printf("%d\n", dp[sum]);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        sum = 0;
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &T[i]);
            sum += T[i];
        }
        sum /= 2;
        solve();
    }
    return 0;
}