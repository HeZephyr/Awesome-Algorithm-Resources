/**
  *@filename:D
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-17 19:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,s,n;
map<string,int> p;
string op;
int temp;
void solve(){
    int cnt=0;
    map<string,int> p2;  
    for(int i=0;i<n;i++){
        cin>>temp;
        p2.clear();
        for(int j=0;j<temp;j++){
            cin>>op;
            p2[op]++;
        }
        //开始去检索没有的。
        for(auto &x:p){
            if(p2.find(x.first)==p2.end()&&x.second>0){
                x.second--;
            }
        }
    }
    for(auto &x:p){
        if(x.second>0)cnt++;
    }
    if(cnt==0){
        cout<<"Need to be lucky"<<endl;
    }
    else{
        cout<<cnt<<endl;
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>s>>n;
            p.clear();
            for(int i=0;i<s;i++){
                cin>>op>>temp;
                p[op]+=temp;
            }
            solve();
        }
    }
    return 0;
}