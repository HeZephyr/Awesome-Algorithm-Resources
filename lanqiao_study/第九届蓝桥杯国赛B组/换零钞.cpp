/**
  *@filename:换零钞
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 12:53
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//需要给的钞票最少，且3种面额的都不能为0.
void solve(){
    int minn=200;
    for(int i=1;i<=10;i++){
        //10为临界点。
        int j=10*i;
        if((200-i-2*j)%5||(200-i-2*j)==0)continue;
        minn=min(minn,i+j+(200-i-2*j)/5);
    }
    cout<<minn<<endl;//74
}
int main(){
    solve();
    return 0;
}