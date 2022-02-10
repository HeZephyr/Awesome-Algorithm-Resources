/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-17 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t;
string s;
void solve(){
    int cnt0=0,cnt1=0,cnt2=0;
    while(getline(cin,s)){
        if(s=="=====")break;
        cnt0++;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                flag=true;
            }
            if(((s[i]==' ')||(i==s.size()-1))&&flag){
                flag=false;
                cnt1++;
            }
        }
        //cout<<s<<endl;
        cnt2+=s.size();
    }
    cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
}
int main(){
    while(cin>>t){
        getchar();//就是加载了这个地方。
        while(t--){
            solve();
        }
    }
    return 0;
}