/**
  *@filename:7-6
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-20 12:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 110 + 5;
const int P = 1e9+7;

int n,k,x;
int a[N][N];
void solve(){
    bool flag=true;
    int t;
    for(int j=2;j<=n;j+=2){
        if(flag)t=1;
        else t=k;
        for(int c=1;c<=t;c++){
            for(int i=n;i>=1;i--){
                a[i][j]=a[i-1][j];
            }
        }
        for(int i=1;i<=t;i++){
            a[i][j]=x;
        }
        flag=!flag;
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=a[i][j];
        }
        cout<<sum;
        i==n?cout<<endl:cout<<" ";
    }
}
int main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    solve();
    return 0;
}