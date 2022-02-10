/**
  *@filename:A_Mean_Inequality
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 22:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 5;
const int P = 1e9+7;

int t,n,a[N];
bool vis[N];
void solve(){
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= 2 * n; ++ i){
            cin >> a[i];
        }
        sort(a + 1,a + 2 * n + 1);
        int i = 1,j = 2 * n;
        while(i <= j){
            printf("%d %d ",a[j],a[i]);
            i ++ ;
            j -- ;
        }
        printf("\n");
    }
    solve();
    return 0;
}