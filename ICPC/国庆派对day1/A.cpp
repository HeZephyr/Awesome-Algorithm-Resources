#include<bits/stdc++.h>
#define ll long long 

const int N = 1e3 + 5;
const int P = 1e9 + 7;
using namespace std;

int n, m;
ll dp[N][N][3];
void init(){
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = 1;
    for(int i = 1; i <= 1000; ++ i){
        for(int j = 1; j <= 1000; ++ j){
            if(i == 1 && j == 1)continue;
            if(i == 1){
                for(int u = 0; u <= 2; ++ u){
                    for(int v = 0; v <= u; ++ v){
                        dp[i][j][u] += dp[i][j - 1][v];
                    }
                }
            }
            else if(j == 1){
                for(int u = 0; u <= 2; ++ u){
                    for(int v = 0; v <= u; ++ v){
                        dp[i][j][u] += dp[i - 1][j][v];
                    }
                }
            }
            else{
                for(int u = 0; u <= 2; ++ u){
                    for(int v = 0; v <= u; ++ v){
                        for(int k = 0; k <= u; ++ k){
                            dp[i][j][u] += (dp[i][j - 1][v]) *  (dp[i - 1][j - 1][k]);
                        }
                    }
                }
            }
        }
    }
}
int main(){
    init();
    while(cin >> n >> m){
        cout << (dp[n][m][0] + dp[n][m][1] + dp[n][m][2]) % P << endl;
    }
    return 0;
}