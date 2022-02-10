/**
  *@filename:第四题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

void solve(){
    //枚举n
    int n=1;
    while(true){
        if(n*(n-1)/2>=2020){
            //65
            cout<<n<<endl;
            break;
        }
        n++;
    }
}
int main(){
    
    solve();
    return 0;
}