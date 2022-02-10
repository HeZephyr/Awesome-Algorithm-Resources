/**
  *@filename:A_Nastia_and_nearly_Good_Numbers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

ll t,a,b,c;
void solve(){
    if(b==1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<a*(b-1)<<" "<<a*(b+1)<<" "<<a*2*b<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        solve();
    }
    return 0;
}