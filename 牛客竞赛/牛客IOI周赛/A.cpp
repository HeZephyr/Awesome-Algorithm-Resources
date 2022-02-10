/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-02 18:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int a,b;
void solve(){
}
int main(){
    while(cin>>a>>b){
        vector<int> temp;
        while(a>0||b>0){
            temp.push_back(a%2+b%2);
            a>>=1,b>>=1;
        }
        for(int i=temp.size()-1;i>=0;i--){
            cout<<temp[i];
        }
        cout<<endl;
        solve();
    }
    return 0;
}