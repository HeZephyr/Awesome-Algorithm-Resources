/**
  *@filename:B_Nezzar_and_Lucky_Number
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-27 13:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,d,a[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(a[i] >= 10 * d){
            printf("YES\n");
        }
        else{
            bool flag = false;
            while(a[i] > 0){
                if(a[i] % d == 0){
                    flag = true;
                    break;
                }
                a[i] -= 10;
            }
            printf("%s\n",flag ? "YES" : "NO");
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}