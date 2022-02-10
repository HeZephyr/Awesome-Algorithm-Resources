/**
  *@filename:A_Potion_making
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 16:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,k;
void solve(){
}
int main(){
    cin>>t;
    while(t--){
        cin>>k;
        int x=100-k;
        int temp=__gcd(k,x);
        cout<<x/temp+k/temp<<endl;
    }
    solve();
    return 0;
}