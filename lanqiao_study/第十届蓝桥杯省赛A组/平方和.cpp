/**
  *@filename:A.平方和
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 00:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

bool check(int i){
    while(i){
        int temp=i%10;
        if(temp==2||temp==0||temp==1||temp==9){
            return true;
        }
        i/=10;
    }
    return false;
}
int main(){
    ll ans=0;
    for(int i=1;i<=2019;i++){
        if(check(i)){
            ans+=i*i;
        }
    }
    cout<<ans<<endl;//2658417853
    return 0;
}