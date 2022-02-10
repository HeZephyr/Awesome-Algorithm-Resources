/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-07 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int x[4];
void solve(){
    sort(x,x + 4);
    //最大的一定是a + b + c。
    for(int i = 2; i >= 0; -- i){
        cout << x[3] - x[i] << " ";
    }
    cout << endl;
}
int main(){
    for(int i = 0; i < 4; ++ i){
        cin >> x[i];
    }	
    solve();
    return 0;
}