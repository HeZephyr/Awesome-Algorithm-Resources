/**
  *@filename:A_Median_Maximization
  *@author: pursuit
  *@created: 2021-09-12 22:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, s;
void solve(){
    int x = n / 2 - (n % 2 == 0);
    cout << s / (n - x) << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}