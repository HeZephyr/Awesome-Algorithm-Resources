/**
  *@filename:蛇形填数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 12:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//不用想得很复杂，由于是在20行20列，而在对角线的位置每隔一个差距就增加4.
void solve(){
    int result=1,d=4;
    for(int i=2;i<=20;i++){
        result+=d;
        d+=4;
    }
    cout<<result<<endl;//761
}
int main(){
    solve();
    return 0;
}