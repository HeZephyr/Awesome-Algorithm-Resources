/**
  *@filename:C_Robot_Collisions
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 16:16
**/
#include <bits/stdc++.h>
#define op second
#define x first
using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const int P = 1e9+7;

int t,n,m;
pair<int,char> a[N];
void solve(){
    sort(a+1,a+1+n);//排序完之后。
    vector<int> t1,t2;
    for(int i=1;i<=n;i++){
        if(a[i].op=='L')t1.push_back(a[i].x);
        else t2.push_back(a[i].x);
    }
    //之后。
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i].x;
        for(int i=1;i<=n;i++)cin>>a[i].op;
        solve();
    }
    return 0;
}