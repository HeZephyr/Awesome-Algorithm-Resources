#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6+7;
int a[N], rad[N], c[N], ans[N];
int main(){
    int t, n;
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        int res = 0;
        for(int i = 3; i <= n; ++ i){
            if(a[i] > 2)res ^= min(a[i], i) - 2;
        }
        printf("Case %d: %d\n", k, res);
    }
    return 0;
}