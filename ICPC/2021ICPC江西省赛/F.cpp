#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 10;
int t;
ll n, f[N];
void init(){
    f[1] = 1;
    ll sum = 2, cnt = 0, d = 2;
    for(int i = 2; i < N; ++ i){
        f[i] = f[i - 1] + d;
        ++ cnt;
        if(cnt == d){
            cnt = 0;
            d += 2;
        }
    }
}
int main(){
    cin >> t;
    init();
    while(t -- ){
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}