/**
  *@filename:成绩统计
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 21:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
void solve(){
}
int main(){
    int temp;
    cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>=60)cnt1++;
        if(temp>=85)cnt2++;
    }
    double result1=double(cnt1)/n*100;
    double result2=double(cnt2)/n*100;
    cout<<round(result1)<<"%"<<endl;
    cout<<round(result2)<<"%"<<endl;
    solve();
    return 0;
}