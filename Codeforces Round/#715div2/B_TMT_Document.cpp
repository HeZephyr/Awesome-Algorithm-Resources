/**
  *@filename:B_TMT_Document
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-16 22:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
string s;
map<char,int> p;
void solve(){
    p.clear();
    bool flag=true;
    int cnt=0;
    for(int i=0;i<n;i++){
        p[s[i]]++;
        if(s[i]=='M'){
            if(p['T']==0){
                flag=false;
                break;
            }
            else{
                p['T']--;
            }
        }
        else{
            if(p['M']>0){
                p['M']--;
                //这个T可以在任何位置，存储需要的t。
                cnt++;
            }
        }
    }
    p['T']-=cnt;
    if(p['T']!=0||p['M']!=0)flag=false;
    if(flag)puts("YES");
    else puts("NO");
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>s;
            solve();
        }
    }
    return 0;
}