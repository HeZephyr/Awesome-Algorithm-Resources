/**
  *@filename:第四题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 14:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int p=2021,v=1160;//模拟即可。
int a[maxn];
void solve(){
    a[1]=v;
    int index=2;
    while(true){
        a[index]=p%a[index-1];
        if(a[index]==0)break;
        index++;
    }
    cout<<index-1<<endl;//12
    for(int i=1;i<=index-1;i++){
        cout<<a[i];
        i==index-1?cout<<endl:cout<<" ";
    }
}
int main(){
    solve();
    return 0;
}