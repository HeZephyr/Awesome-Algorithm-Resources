#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

map<string, int> p;
int n;
void solve(){
    p["You were studying Higher mathematics!"] = 1;
    p["You were studying Linear algebra!"] = 2;
    p["You were studying Principle of computer composition!"] = 3;
    p["You were studying Database system concept!"] = 4;
    p["You were playing games!"] = 5;
    for(auto [a , b] : p){
        if(b == n){
            cout << a << endl;
            break;
        }
    }
}
int main(){	
    cin >> n;
    solve();
    return 0;
}