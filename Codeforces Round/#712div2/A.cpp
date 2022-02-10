/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-06 18:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t;
string s;
bool check(string s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}
void solve(){
    //简单分析一下，如果是回文的，那么如果一直添加a可行，说明该字符串中不是全部的a。
    bool flag=true;
    for(auto &x:s){
        if(x!='a'){
            flag=false;
            break;
        }
    }
    if(!flag){
        cout<<"YES\n";
        if(check(s+"a")){
            cout<<"a"+s<<endl;
        }
        else{
            cout<<s+"a"<<endl;
        }
    }
    else{
        cout<<"NO\n";
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>s;
            solve();
        }
    }
    return 0;
}