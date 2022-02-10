/**
  *@filename:最大乘积
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-15 20:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

//暴力全排列+枚举。
int a[]={1,2,3,4,5,6,7,8,9};
ll get(int i,int j){
    ll ans=0;
    for(int t=i;t<=j;t++){
        ans=ans*10+a[t];
    }
    return ans;
}
bool check(ll ans){
    bool vis[10];
    memset(vis,false,sizeof(vis));
    while(ans){
        vis[ans%10]=true;
        ans/=10;
    }
    for(int i=1;i<=9;i++){
        if(!vis[i])return false;
    }
    return true;
}
void solve(){
    ll maxx=0;
    do{
        for(int i=1;i<=7;i++){
            ll ans1=get(0,i),ans2=get(i+1,8);
            ans1*=ans2;
            if(check(ans1)){
                maxx=max(maxx,ans1);
            }
        }
    }while(next_permutation(a,a+9));
    cout<<maxx<<endl;//839542176
}
int main(){
    solve();
    return 0;
}