/**
  *@filename:3333K优字符串
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-22 18:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,k;
char s[N];
void solve(){
    int cnt=0;
    for(int i=1;i<=n/2;i++){
        if(s[i]!=s[n-i+1]){
            cnt++;
        }
    }
    cout<<abs(k-cnt)<<endl;
}
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>s+1;
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}