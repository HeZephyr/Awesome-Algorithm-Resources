/**
  *@filename:激光样式
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 13:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//0表示关闭，1表示打开。
//这种题目一看就是找规律的，或者直接枚举。用dfs。
bool vis[maxn];//判断该点是否已经打开了。
int ans;
void dfs(int idx){
    //idx表示当前正在判断第idx个激光器。
    if(idx==31){
        //说明前30台激光器已经确定了。
        ans++;
        return;
    }
    //接下来开始枚举下一台。可以关闭也可以打开。打开的前提是前者不允许为1.
    if(!vis[idx-1]){
        vis[idx]=true;
        dfs(idx+1);
        vis[idx]=false;
    }
    dfs(idx+1);
}
void solve(){
    dfs(1);
    cout<<ans<<endl;//2178309.
}
int main(){ 
    solve();
    return 0;
}