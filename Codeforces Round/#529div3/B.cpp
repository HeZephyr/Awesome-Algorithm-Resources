#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n,a[N];
void solve(){
    sort(a + 1,a + 1 + n);
    //要么删最大值要么删最小值。
    printf("%d\n", min(a[n - 1] - a[1], a[n] - a[2]));
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}