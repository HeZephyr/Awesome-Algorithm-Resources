/**
  *@filename:激光样式递推
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 13:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int f[40][2];//f[i][0]表示前i个，且第i位是0的方案数，f[i][1]表示前i个，且第i为时1的方案数。
void solve(){
    f[1][0]=1,f[1][1]=1;//其实状态。
    //易知状态转移方程为:f[i][0]=f[i-1][0]+f[i-1][1],f[i][1]=f[i-1][0]
    for(int i=2;i<=30;i++){
        f[i][0]=f[i-1][0]+f[i-1][1];
        f[i][1]=f[i-1][0];
    }
    cout<<f[30][1]+f[30][0]<<endl;//2178309
}
int main(){
    solve();
    return 0;
}