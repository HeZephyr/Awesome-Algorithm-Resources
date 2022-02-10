/**
  *@filename:一步之遥
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-24 12:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//判断多少次前进=多少次后退+1即可。我们枚举即可。
//答案为97.
void solve(){
    for(int i=1;;i++){
        for(int j=1;j*97-1<=127*i;j++){
            if(j*97-1==127*i){
                cout<<i+j<<endl;
                return;
            }
        }
    }
    return;
}
int main() {
    cout<<97<<endl;
    //solve();
    return 0;
}