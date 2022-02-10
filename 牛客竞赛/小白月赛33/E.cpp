/**
  *@filename:E
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 13:59
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,a,b;
void solve(){
}
int main(){
    while(cin>>n>>a>>b){
        int ans=n;
        for(int i=1;i<=n;i++){
            int cnt1=i,cnt2=n-i;
            int cnt=n;
            while(cnt1>=a||cnt2>=b){
                cnt=cnt1/b+cnt2/a;
                int temp=cnt1;
                cnt1=cnt1%a+cnt2/a;
                cnt2=cnt2%b+temp/b;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    solve();
    return 0;
}