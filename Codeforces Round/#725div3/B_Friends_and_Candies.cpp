/**
  *@filename:B_Friends_and_Candies
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 22:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
ll sum;
void solve(){
    if(sum % n){
        printf("-1\n");
    }
    else{
        ll temp = sum / n;
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            if(a[i] > temp){
                cnt ++;
            }
        }
        printf("%d\n",cnt);
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        sum = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        solve();
    }
    return 0;
}