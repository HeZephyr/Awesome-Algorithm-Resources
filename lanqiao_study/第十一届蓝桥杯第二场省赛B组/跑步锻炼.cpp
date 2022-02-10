/**
  *@filename:跑步锻炼
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 18:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void solve(){
    int k=5,special=0;//0,1,2,3,4,5,6表示周一到周日。
    int ans=0;
    for(int month=1;month<=9;month++){
        for(int day=1;day<=months[month];day++){
            k++;
            k%=7;
            if(day==1||k==0)special++;
            ans++;
        }
    }
    ans++,special++;
    cout<<ans+special<<endl;//324
}
int main(){
    solve();
    return 0;
}