/**
  *@filename:平方十位数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-02 10:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//暴力全排列获取所有情况。
ll a[]={1,0,2,3,4,5,6,7,8,9};//由于首位不能为0，所以我们这里字典序初始为1023456789.
double pow_value[]={1e9,1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1e0};
void solve(){
    ll maxx=0;
    do{
        ll ans=0;
        for(int i=0;i<10;i++){
            ans=ans+ll(a[i]*pow_value[i]);
        }
        ll temp=sqrt(ans);
        if(temp*temp==ans){
            maxx=max(maxx,ans);
        }
    }while(next_permutation(a,a+10));//9814072356
    cout<<maxx<<endl;
}
int main(){
    solve();
    return 0;
}