/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-26 18:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
void solve(){
    int m = 1;
    int sum = 12;
    for(int i = 2; i <= n; ++ i){
        m += sum;
        sum += 12;
    }
    cout << m << endl;
}
int main(){	
    cin >> n;
    solve();
    return 0;
}