/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 15:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,a,x,y;
void solve(){
}
int main(){
    cin >> n >> a >> x >> y;
    if(n <= a){
        cout << n * x << endl;
    }
    else{
        cout << a * x + (n - a) * y;
    }
    solve();
    return 0;
}