/**
  *@filename:A_Split_it_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-30 16:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,k;
char s[N];
void solve(){
    //要分成2k + 1份，不满足直接输出no。
    if(n < 2 * k + 1){
        puts("NO");
        return;
    }
    bool flag = true;
    int i;
    for(i = 0; i < k; ++ i){
        if(s[i] != s[n - i - 1]){
            flag = false;
            break;
        }
    }
    if(flag)puts("YES");
    else puts("NO");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%s", &n ,&k,s);
        solve();
    }
    return 0;
}