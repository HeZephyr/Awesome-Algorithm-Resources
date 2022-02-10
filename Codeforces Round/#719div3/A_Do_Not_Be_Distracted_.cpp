/**
  *@filename:A_Do_Not_Be_Distracted_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 22:35
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
    char pre=s[0];
    p[pre]++;
    bool flag=false;
    for(int i=1;i<n;i++){
        if(s[i]!=pre){
            if(p.find(s[i])!=p.end()){
                flag=true;
                break;
            }
            else{
                pre=s[i];
                p[s[i]]++;
            }
        }
    }
    if(!flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        solve();
    }
    return 0;
}