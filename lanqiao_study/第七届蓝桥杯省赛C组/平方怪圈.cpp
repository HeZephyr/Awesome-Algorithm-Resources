/**
  *@filename:平方怪圈
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-20 21:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//我们先进行测试，看出现什么样的循环。
int n=5;
void change(int &n){
    int result=0;
    //得到循环圈最大是145.
    while(n>0){
        result+=pow(n%10,2);
        n/=10;
    }
    n=result;
}
void solve(){
    int maxx=0;
    for(int i=0;i<100;i++){
        change(n);
        maxx=max(maxx,n);    
    }
    cout<<maxx<<endl;
}
int main() {
    solve();
    return 0;
}