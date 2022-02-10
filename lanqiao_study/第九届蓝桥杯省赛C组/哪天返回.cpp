/**
  *@filename:哪天返回
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 13:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


void solve(){
}
int main(){
    //等差数列求和公式得解。公差为2.
    int n=1;
    while(n*1+n*(n-1)*2/2<108){
        n++;
    }
    cout<<n<<endl;//11
    solve();
    return 0;
}