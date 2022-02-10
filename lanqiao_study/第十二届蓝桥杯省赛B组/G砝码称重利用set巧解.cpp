/**
  *@filename:G砝码称重利用set巧解
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-19 21:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,w[105];
set<int> t1,t2;
int sum;
bool vis[maxn];//判断是否出现。
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    t1.insert(0),t2.insert(0);//以它们作为更新点。
    for(int i=1;i<=n;i++){
        //每次加入一个元素进去。
        for(auto &x:t1){
            t2.insert(x+w[i]);
            t2.insert(x-w[i]);
        }
        t1=t2;
    }
    for(auto &x:t1){
        vis[abs(x)]=true;
    }
    int ans=0;
    for(int i=1;i<=maxn;i++){
        if(vis[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}