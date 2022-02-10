/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-03 14:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
map<char,int> p;
void solve(){
    int cnt=0;
    for(auto &x:p){
        if(x.second%2)cnt++;
    }
    if(cnt==0){
        cnt=1;
    }
    cout<<cnt<<endl;
}
int main(){
    cin>>s;
    for(auto &x:s){
        p[x]++;
    }
    solve();
    return 0;
}