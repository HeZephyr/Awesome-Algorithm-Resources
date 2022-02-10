/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 20:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string a,b;
void solve(){
    deque<char> result;
    int flag=0;
    for(int i=0;i<b.size();i++){
        if(!flag){
            result.push_back(a[i]);
        }
        else{
            result.push_front(a[i]);
        }
        if(b[i]=='R'){
            flag=0;
        }
        else{
            flag=1;
        }
    }
    while(!result.empty()){
        cout<<result.front();
        result.pop_front();
    }
    cout<<endl;
}
int main(){
    while(cin>>a>>b){
        solve();
    }
    return 0;
}