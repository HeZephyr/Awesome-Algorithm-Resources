/**
  *@filename:星期一
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-03 09:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//计算这期间有多少天然后根据日历判断初始时星期几即可。
//我们知道平年是365，闰年是366.
bool check(int year){
    if((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    return false;
}
void solve(){
    int ans=0;
    for(int i=1901;i<=2000;i++){
        if(check(i)){
            ans+=366;
        }
        else{
            ans+=365;
        }
    }
    //利用日历，也可以根据现在的时间推回去。这里采用直接看日历的方式：2000年12月31日为星期一
    //如果根据现在的时间推回去就是计算现在里2000年12月31日有多少天再做处理。
    cout<<ans/7<<endl;//5217
    cout<<ans%7<<endl; //由于余6，构不成。
}
int main(){
    solve();
    return 0;
}