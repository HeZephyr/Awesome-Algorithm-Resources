/**
  *@filename:第三题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int a[6];//存储选取的数。
int ans;
void dfs(int index){
    //index表示当前正在选择第i个数。
    if(index==6){
        for(int i=1;i<=5;i++){
            cout<<a[i];
            i==5?cout<<endl:cout<<" ";
        }
        ans++;
        return;
    }
    for(int i=1;i<=10;i++){
        if(a[index-1]<=i){
            a[index]=i;
            dfs(index+1);
        }
    }
}
void solve(){
    ans=0;
    dfs(1);
    cout<<ans<<endl;//2002.
}
int main(){ 
    solve();
    return 0;
}