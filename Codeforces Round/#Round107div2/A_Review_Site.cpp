/**
  *@filename:A_Review_Site
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 13:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 50 + 5;
const int mod = 1e9+7;

int t,n,r[maxn];
void solve(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(r[i]==1){
            cnt++;
        }
        else if(r[i]==3){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>r[i];
        solve();
    }
    return 0;
}