/**
  *@filename:D
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 19:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;     
int a[maxn];   
void solve(){
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]&1){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            solve();
        }
    }
    return 0;
}