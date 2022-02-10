#include<bits/stdc++.h>

using namespace std;

int n, a[11110];

int g[11110];
int main(){
    cin >> n;
    int res = 0, x, y;
    for(int i = 1; i <= n; ++ i){
        cin >> x >> y;
        res += y;
    }
    cout << res * 3 << endl;
    return 0;
}