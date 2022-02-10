/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-09 14:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000 + 5;
const int P = 1e9+7;

int t,n,a[N];
int sum;
void solve(){
    //枚举分成的段。
    for(int i = n; i >= 1; -- i){
        if(sum % i)continue;//说明不能整段分。
        bool flag = true;
        int res = 0,temp = sum / i;
        for(int j = 1; j <= n; ++ j){
            res += a[j];
            if(res == temp)res = 0;
            if(res > temp){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d\n",n - i);
            break;
        }
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