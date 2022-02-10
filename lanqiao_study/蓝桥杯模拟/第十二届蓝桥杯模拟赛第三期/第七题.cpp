/**
  *@filename:第七题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 14:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//这道题绝对不可能是去模拟它等于多少，只能找规律。
//1,1,2,3,5,8,13,12,34
//其实规律很好发现，当n能整除3时候则是偶数，因为只有奇数+奇数的时候才可以为偶数。
int n;
void solve(){
    if(n%3==0){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}