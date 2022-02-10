/**
  *@filename:B_Odd_Grasshopper
  *@author: pursuit
  *@created: 2021-11-02 22:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll x, n;
void solve(){
    if(x % 2 == 0){
        //-1, +2, + 3, - 4, -5 +6 +7
        //1, -1, 1, -1
        ll temp = n % 4;
        if(temp == 1){
            x -= n;
        }
        else if(temp == 2){
            x += 1;
        }
        else if(temp == 3){
            x += (n + 1);
        }
    }
    else{
        //+1, -2, -3, + 4 + 5, -6 -7
        ll temp = n % 4;
        if(temp == 1){
            x += n;
        }
        else if(temp == 2){
            x -= 1;
        }
        else if(temp == 3){
            x -= (n + 1);
        }
    }
    cout << x << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> x >> n;
        solve();
    }
    return 0;
}