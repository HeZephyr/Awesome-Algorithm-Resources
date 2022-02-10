/**
  *@filename:7-4
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-20 12:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,d;
bool check(int x){
    while(x){
        if(x%10==d)return false;
        x/=10;
    }
    return true;
}
void solve(){
}
int main(){
    cin>>n>>d;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(check(i))cnt++;
    }
    cout<<cnt<<endl;
    solve();
    return 0;
}