/**
  *@filename:B_Ordinary_Numbers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 22:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
bool check(int x){
    string temp=to_string(x);
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]!=temp[i+1])return false;
    }
    return true;
}
void solve(){
    int ans=0;
    int k=1,temp=1;
    for(int i=temp;i<=n;i+=temp){
        if(check(i))ans++;
        else{
            //不行，说明已经进位，我们需要让temp变为当前长度的1。
            temp=temp*10+1;
            i=0;
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        solve();
    }
    return 0;
}