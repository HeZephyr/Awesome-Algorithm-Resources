/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 20:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,m;
int a[N],b[N];
void solve(){
    int minn = 0x3f3f3f3f;
    sort(b + 1, b + 1 + m);
    for(int i = 1; i <= n; ++ i){
        int l = 1, r = m;
        while(l < r){
            int mid = (l + r) >> 1;
            if(b[mid] <= a[i]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        minn = min(minn,abs(b[l] - a[i]));
        if(l > 1){
            minn = min(minn,abs(a[i] - b[l - 1]));
        }
    }
    printf("%d\n",minn);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}