#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n;
ll fac[N];
void solve(){
    fac[0] = 1;
    for(int i = 1; i <= 31; ++ i){
        fac[i] = fac[i - 1] * 2;
    }
    vector<int> res;
    for(int i = 31; i >= 1; -- i){
        if(n >= fac[i]){
            n -= fac[i];
            res.push_back(fac[i]);
        }
    }
    if(n == 0){
        for(auto x : res){
            cout << x << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}
int main(){	
    cin >> n;
    solve();
    return 0;
}