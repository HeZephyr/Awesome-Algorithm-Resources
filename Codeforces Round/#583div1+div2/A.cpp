#include<bits/stdc++.h>

using namespace std;

int n, d, e;
int res;
int main(){
    cin >> n >> d >> e;
    e *= 5;
    res = n;
    for(int i = 0; i * e <= n; ++ i){
        int temp = n - i * e;
        res = min(res, temp % d);
    }
    cout << res << endl;
    return 0;
}