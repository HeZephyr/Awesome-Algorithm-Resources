/**
  *@filename:B_I_Hate_1111
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 22:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll x;
ll a[] = {0,11,111};
ll dp[N];
int main(){
    cin >> t;
    int n = 2;
    while(t -- ){
        cin >> x;
        if(x > 1099){
            cout << "YES" << endl;
        }
        else{
            memset(dp,0,sizeof(dp));
            dp[0] = 1;
            for(int i = 1; i <= n; ++ i){
                for(int j = 0; j <= x; ++ j){
                    if(j >= a[i]){
                        dp[j] = max(dp[j],dp[j - a[i]]);
                    }
                }
            }
            if(dp[x] > 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}