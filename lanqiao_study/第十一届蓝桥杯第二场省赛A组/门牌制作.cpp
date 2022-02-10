/**
  *@filename:门牌制作
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 12:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int cal(int x){
    int ans=0;
    while(x>0){
        if(x%10==2){
            ans++;
        }
        x/=10;
    }
    return ans;
}
void solve(){
    int ans=0;
    for(int i=1;i<=2020;i++){
        ans+=cal(i);
    }
    cout<<ans<<endl;//624
}
int main(){    
    solve();
    return 0;
}