/**
  *@filename:B_The_Cake_Is_a_Lie
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 22:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n,m,k;
void solve(){
    if(k==(m-1)+m*(n-1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        solve();
    }
    return 0;
}