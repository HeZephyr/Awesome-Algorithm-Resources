/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-12 14:08
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a,b;
void solve(){
    int maxx = n / b;
    for(int i = 0; i <= maxx; ++ i){
        int temp = n - i * b;
        if(temp % a == 0){
            cout << "YES" << endl;
            cout << temp / a << " " << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){	
    cin >> n >> a >> b;
    solve();
    return 0;
}