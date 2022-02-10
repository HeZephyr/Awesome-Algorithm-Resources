/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-06 19:05
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
    int minn = INF;
    for(int i = max(b, 2); i <= b + 31; ++ i){
        int temp = a, cnt = i - b;
        while(temp){
            temp /= i;
            ++ cnt;
        }
        minn = min(cnt, minn);
    }
    cout << minn << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b;
        solve();
    }
    return 0;
}