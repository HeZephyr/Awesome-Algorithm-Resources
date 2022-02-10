/**
  *@filename:冰雹数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-20 21:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n;
void solve(){
    ll maxx=n;
    for(ll i=2;i<=n;i++){
        ll temp=i;
        while(temp!=1){
            while(temp%2==0){
                temp/=2;
            }
            if(temp==1){
                break;
            }
            temp=temp*3+1;
            maxx=max(maxx,temp);
        }
    }    
    cout<<maxx<<endl;
}
int main() {
    while(cin>>n){
        solve();
    }
    return 0;
}