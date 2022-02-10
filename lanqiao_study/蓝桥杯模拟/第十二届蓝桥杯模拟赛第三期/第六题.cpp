/**
  *@filename:第六题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 14:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
void solve(){
    deque<char> q;
    for(int i=s.size()-1,k=1;i>=0;i--,k++){
        q.push_back(s[i]);
        if(k%3==0)q.push_back(',');
    }
    while(!q.empty()){
        cout<<q.back();
        q.pop_back();
    }
}
int main(){
    while(cin>>s){
        solve();
    }
    return 0;
}