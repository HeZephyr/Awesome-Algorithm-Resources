/**
  *@filename:第七题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 20:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month,day;
void solve(){
    if(month>12||month<1){
        puts("no");
    }
    else{
        //判断日期是否符合。
        if(day>months[month]||day<1){
            puts("no");
        }
        else{
            puts("yes");
        }
    }
}
int main(){
    while(cin>>month>>day){
        solve();
    }
    return 0;
}