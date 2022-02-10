/**
  *@filename:数的分解
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 00:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int result=2019;
bool check(int x){
    while(x>0){
        if(x%10==2||x%10==4){
            return false;
        }
        x/=10;
    }
    return true;
}
void solve(){
    int ans=0;
    for(int i=1;i<=2019/3;i++){
        if(!check(i))continue;
        for(int j=i+1;j<=(2019-i)/2;j++){
            int k=2019-i-j;
            if(k==j||i==k)continue;
            if(check(j)&&check(k)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}