#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 10;
int t, n, x[N];
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i)scanf("%d", &x[i]);
        sort(x + 1, x + 1 + n);
        int minn = 1e9, maxx = 0;

        for(int i = 1; i <= n; ++ i){
            int l = i - 1, r = i + 1, cnt = 1;
            while(l >= 1 && abs(x[l] - x[l + 1]) <= 2)++ cnt, -- l;
            while(r <= n && abs(x[r] - x[r - 1]) <= 2)++ cnt, ++ r;
            minn = min(minn, cnt);
            maxx = max(maxx, cnt);
        }
        printf("%d %d\n", minn, maxx);
    }
    return 0;
}