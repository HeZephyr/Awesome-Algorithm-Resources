/**
  *@filename:A_Red_and_Blue_Beans
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll t,r,b,d;
void solve(){
    if(r<b)swap(r,b);
    if(b+b*d>=r){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>r>>b>>d;
        solve();
    }
    return 0;
}