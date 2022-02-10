#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n, a[N], b[N];
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    int minn = 1e9, maxx = 0;
    for(int i = 1; i <= n; ++ i){
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        b[i] = floor(100.0 * (a[i] - minn) / (maxx - minn));
        printf("%d ", b[i]);
    }
    puts("");
    return 0;
}