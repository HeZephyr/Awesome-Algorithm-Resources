/**
  *@filename:第八题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 20:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//dfs模拟删除。
string s;
string minn;
int t;//可删除字符的数量。
void dfs(string s,int cnt){
    //cnt表示当前已经删除的字符数量。
    if(cnt==t){
        minn=min(minn,s);
        return;
    }
    int len=s.size();
    for(int i=0;i<len;i++){
        //模拟删除第i个字符。
        if(i==0){
            dfs(s.substr(1,len-1),cnt+1);//删除第一个。
        }
        else{
            dfs(s.substr(0,i)+s.substr(i+1,len-i-1),cnt+1);
        }
    }
}
void solve(){
    //初始化minn。
    minn="ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
    dfs(s,0);
    cout<<minn<<endl;
}
int main(){
    while(cin>>s>>t){
        solve();
    }
    return 0;
}