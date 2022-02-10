/**
  *@filename:子串分值和暴力
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 21:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
bool vis[27];//vis[i]表示第i个字母有没有出现。
void solve(){
}
int main(){
    while(cin>>s){
        ll ans=0;
        int cnt;
        for(int i=0;i<s.size();i++){
            memset(vis,0,sizeof(vis));
            cnt=0;
            for(int j=i;j>=0;j--){
                if(!vis[s[j]-'a']){
                    vis[s[j]-'a']=true;
                    cnt++;
                }
                ans+=cnt;
            }
        }
        cout<<ans<<endl;
        solve();
    }
    return 0;
}