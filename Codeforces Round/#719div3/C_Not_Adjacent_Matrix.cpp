/**
  *@filename:C_Not_Adjacent_Matrix
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 22:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int t,n;
int a[maxn][maxn];
void solve(){
    if(n==2)cout<<-1<<endl;
    else{
        int odd=1,even=2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(odd>n*n){
                    a[i][j]=even;
                    even+=2;
                }
                else{
                    a[i][j]=odd;
                    odd+=2;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        solve();
    }
    return 0;
}