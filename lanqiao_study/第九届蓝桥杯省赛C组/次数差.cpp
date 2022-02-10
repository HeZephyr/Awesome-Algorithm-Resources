/**
  *@filename:次数差
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 14:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

map<char,int> p;
string s;
void solve(){
    for(auto &x:s){
        p[x]++;
    }
    int minn=1000,maxx=0;
    for(auto &x:p){
        minn=min(x.second,minn);
        maxx=max(x.second,maxx);
    }
    cout<<maxx-minn<<endl;
}
int main(){
    while(cin>>s){
        p.clear();
        solve();
    }
    return 0;
}