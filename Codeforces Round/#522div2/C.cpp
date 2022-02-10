/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-31 14:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N];
bool dp[N][10];//dp[i][j]表示前i个且第i个填j的合法情况。为0代表不可行，否则可行。
int pre[N][10];//pre[i][j]表示该状态前一个填的是什么值。
int Stack[N],top;
void solve(){
    for(int j = 1; j <= 5; ++ j){
        dp[1][j] = 1;
    }
    for(int i = 2; i <= n; ++ i){
        for(int j = 1; j <= 5; ++ j){
            if(dp[i - 1][j]){
                if(a[i] > a[i - 1]){
                    //则b[i] > b[i - 1]。
                    for(int k = j + 1; k <= 5; ++ k){
                        dp[i][k] = true, pre[i][k] = j;
                    }
                }
                else if(a[i] == a[i - 1]){
                    //则b[i] != b[i - 1]。
                    for(int k = 1; k <= 5; ++ k){
                        if(k != j){
                            dp[i][k] = true, pre[i][k] = j;
                        }
                    }
                }
                else{
                    //则b[i] < b[i - 1]。
                    for(int k = 1; k < j; ++ k){
                        dp[i][k] = true, pre[i][k] = j;
                    }
                }
            }
        }
    }
    int x = -1;
    for(int j = 1; j <= 5; ++ j){
        if(dp[n][j]) x = j;//找到合法状态。
    }
    if(x == -1){
        puts("-1");
    }
    else{
        top = 0;
        for(int i = n; i >= 1; -- i){
            Stack[top ++] = x;
            x = pre[i][x];
        }
        for(int i = top - 1; i >= 0; -- i){
            printf("%d ", Stack[i]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}