/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 15:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


int solve(int num){
    int ans=0;
    while(num>0){
        ans+=num%10;
        num/=10;
    }
    if(ans>=10){
        return solve(ans);
    }
    else return ans;
}
int main(){
    int num;
    while(cin>>num){
        cout<<solve(num)<<endl;
    }
    return 0;
}