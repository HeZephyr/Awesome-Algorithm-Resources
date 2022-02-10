/**
  *@filename:032彩虹瓶
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 18:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m,k;//利用栈模拟即可。
void solve(){
    stack<int> s;
    int cur=1,u;//当前需要放的货物。
    bool flag=false;
    for(int i=1;i<=n;i++){
        cin>>u;
        //不相等就入栈，相等就看看是否还鞥你出栈。
        if(u==cur){
            cur++;
            while(!s.empty()&&!flag&&cur==s.top())cur++,s.pop();
        }
        else{
            s.push(u);
            if(s.size()>m){
                flag=true;
            }
        }
    }
    if(s.empty())puts("YES");
    else puts("NO");
}
int main(){
    cin>>n>>m>>k;
    while(k--){
        solve();
    }
    return 0;
}