#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int t, n, m;
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        ll res = 0;
        for(int i = 1; i <= n; ++ i){
            res += 1LL * (i * i) * m;
        }
        cout << res << endl;
    }
    return 0;
}