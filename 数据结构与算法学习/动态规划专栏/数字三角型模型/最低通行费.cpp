/**
  *@filename:最低通行费
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 20:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 105 + 5;
const int P = 1e9+7;

int n,a[N][N];
//必须在2n-1的时间内走出去==只能向右走或者向下走。
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1)a[i][j]+=a[i][j-1];
            else if(j==1)a[i][j]+=a[i-1][j];
            else{
                a[i][j]+=min(a[i][j-1],a[i-1][j]);
            }
        }
    }
    cout<<a[n][n]<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    solve();
    return 0;
}