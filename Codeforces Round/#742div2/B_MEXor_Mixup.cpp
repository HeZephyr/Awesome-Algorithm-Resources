/**
  *@filename:B_MEXor_Mixup
  *@author: pursuit
  *@created: 2021-09-05 22:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a, b;
void solve(){
    int res, len = a;
    int x = a - 1;
    if(x % 4 == 1)res = 1;
    else if(x % 4 == 2)res = a;
    else if(x % 4 == 3)res = 0;
    else res = x;
    if(res == b){
        cout << len << endl;
        return;
    }
    int temp = (res ^ b);
    if(temp == a){
        //说明不能选取。
        cout << len + 2 << endl;
    }
    else{
        cout << len + 1 << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b;
        solve();
    }
    return 0;
}