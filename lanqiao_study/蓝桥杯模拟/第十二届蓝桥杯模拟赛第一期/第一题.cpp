/**
  *@filename:第一题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 19:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//遍历统计输出即可。
void solve(){
    int ans=0;
    for(int i=1;i<=2020;i++){
        if(2020%i==0)ans++;
    }
    cout<<ans<<endl;//12
}
int main(){
    
    solve();
    return 0;
}