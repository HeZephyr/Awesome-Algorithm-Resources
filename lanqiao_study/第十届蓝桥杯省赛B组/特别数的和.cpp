/**
  *@filename:特别数的和
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 00:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int ans;
bool check(int x){
    int temp;
    while(x>0){
        temp=x%10;
        if(temp==2||temp==0||temp==1||temp==9)return true;
        x/=10;
    }
    return false;
}
void solve(){
    ans=0;
    for(int i=1;i<=n;i++){
        if(check(i))ans+=i;
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}