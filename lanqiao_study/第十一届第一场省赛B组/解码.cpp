/**
  *@filename:解码
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 18:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
void solve(){
    vector<char> result;
    int l=0,r,len=s.size();
    while(l<len){
        r=l+1;
        while(r<len&&s[r]>='0'&&s[r]<='9')r++;
        int cnt;
        if(r>l+1)cnt=stoi((s.substr(l+1,r-l-1)));
        else cnt=0;
        result.push_back(s[l]);
        for(int i=0;i<cnt-1;i++)result.push_back(s[l]);
        l=r;
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    cout<<endl;
}
int main(){
    while(cin>>s){
        solve();
    }
    return 0;
}