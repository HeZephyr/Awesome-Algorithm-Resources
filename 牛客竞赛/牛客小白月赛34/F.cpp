/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 19:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000000 + 5;
const int P = 1e9+7;

int n,x;
int a[N];
void solve(){
}
int main(){
    scanf("%d%d", &n, &x);
    int sum = 0,minn = N,min_l,min_r,l = 1,r = 1;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    while(l <= n){
        while(sum < x && r <= n)sum += a[r],r++;
        if(sum >= x && minn > (r - l)){
            minn = r - l;
            min_l = l;
            min_r = r - 1;
        }
        sum -= a[l];
        l ++;
    }
    printf("%d %d\n",min_l,min_r);
    solve();
    return 0;
}