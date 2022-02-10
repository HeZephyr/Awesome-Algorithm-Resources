/**
  *@filename:B_Phoenix_and_Puzzle
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 15:53
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
bool check(int x){
    int temp=sqrt(x);
    if(temp*temp==x){
        return true;
    }
    return false;
}
void solve(){
    //要能凑成一个正方形，那么应该就是2的次方即可。
    bool flag=false;
    if(n%2==0&&check(n/2)){
        cout<<"YES"<<endl;
    }
    else if(n%4==0&&check(n/4)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        solve();
    }
    return 0;
}