#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int n;
int a[N], b[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    ll sum1 = 0, sum2 = 0;
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        sum1 += a[i], sum2 += b[i];
        if(sum1 == sum2)++ cnt;
    }
    printf("%d\n", cnt);
    return 0;
}