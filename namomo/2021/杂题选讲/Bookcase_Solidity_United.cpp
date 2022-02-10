/**
  *@filename:Bookcase_Solidity_United
  *@author: pursuit
  *@created: 2021-10-27 22:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
有n个书架，从上到下放置，第i个架子的承受额能力严格小于ai。
如果货架上有>=ai的球，那么就会坏。如果没有完整的架子，所有的
球都会掉到地板上。有x/2的球会落在下一个架子上。
持续下去直至架子上的球不掉落。
问打破第k层货架所需要的最小球数。
*/
int dp[N][N][N];
//dp[l][r][k]表示仅击碎[l, r]的区间，且最后还剩下k个物品可以落下的最小花费。
int n, a[N], maxx;
void solve(){
    memset(dp, 150, sizeof(dp));
    for(int i = 1; i <= n; ++ i){
        //初始状态，仅击碎一层。
        dp[i][i][a[i] / 2] = a[i]; 
    }
    for(int len = 2; len <= n; ++ len){
        for(int l = 1, r; l + len - 1 <= n; ++ l){
            r = l + len - 1;
            cout << l << " " << r << endl;
            for(int  k = a[r] / 2; k <= maxx; ++ k){
                int &x = dp[l][r][k];
                x = INF;
                for(int mid = l + 1; mid <= r - 1; ++ mid){
                    //枚举这些球漏到了第几层。
                    for(int k1 = a[r - 1] / 2; k1 <= maxx; ++ k){
                        //计算击穿本层需要多少。
                        int need = max(0, a[r] - k1);
                        int K = k1 + need;//k为击碎a[r - 1]用到的球。
                        int y = k - K / 2;//除以2则是掉下来的球， 
                        if(y >= 0){
                            if(y >= a[mid - 1] / 2){
                                x = min(x, dp[l][mid - 1][y] + dp[mid][r - 1][k1] + need);
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
                if(k == a[r] / 2){
                    for(int k1 = a[r - 1] / 2; k1 <= min(maxx, a[r] + 1); ++ k1){
                        int need = max(0, a[r] - k1);
                        if((need + k1) / 2 != a[r] / 2)break;
                        if(need < x){
                            x = min(x, dp[l][r - 1][k1] + need);
                        }
                    }
                }
                for(int k1 = a[r - 1] / 2; k1 <= maxx; ++ k1){
                    if(k1 / 2 > k)break;
                    int y = 2 * k - k1;
                    if(y + k >= a[r] && y < x){
                        x = min(x, dp[l][r - 1][k1] + y);
                    }
                }
                x = min(x, dp[l][r - 1][k - a[r] / 2] + a[r]);
            }
        }
    }
    puts("1");
    for(int i = 1; i <= n; ++ i){
        int res = INF;
        for(int j = a[i] / 2; j <= maxx; ++ j){
            res = min(res, dp[1][i][j]);
        }
        printf("%d ", res);
    }
    puts("");
}
struct node{
    int l, r;
    int x;
};

int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        maxx = max(a[i], maxx);
    }
    solve();
    return 0;
}