/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 19:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

//两次顺时针就和原来没什么区别，记录顺时针的操作次数即可，我们需要知道的是，如果旋转了，则是末尾输出。
int n,q;
int a[N][N];
void solve(){
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &q);
    int cnt1 = 0,cnt2 = 0,x;
    while(q -- ){
        scanf("%d", &x);
        if(x & 1)cnt1 ++;
        else cnt2 ++ ;
    }
    if((cnt1 & 1)&&(cnt2 & 1)){
        for(int i = 1; i <= n; ++ i){
            for(int j = n; j >= 1; -- j){
                printf("%d%c",a[i][j],j == 1 ? '\n' : ' ');
            }
        }
    }
    else if(cnt1 & 1){
        for(int i = n; i >= 1; -- i){
            for(int j = n; j >= 1; -- j){
                printf("%d%c",a[i][j],j == 1 ? '\n' : ' ');
            }
        }
    }
    else if(cnt2 & 1){
        for(int i = n; i >= 1; -- i){
            for(int j = 1; j <= n; ++ j){
                printf("%d%c",a[i][j],j == n ? '\n' : ' ');
            }
        }
    }
    else{
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                printf("%d%c",a[i][j],j == n ? '\n' : ' ');
            }
        }
    }
    solve();
    return 0;
}