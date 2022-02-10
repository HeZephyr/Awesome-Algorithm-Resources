/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-25 22:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll t,n,m,x;
void solve(){
    x--;
    ll temp1=x/n,temp2=x%n;
    cout<<temp2*m+temp1+1<<endl;
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n>>m>>x;
            solve();
        }
    }
    return 0;
}