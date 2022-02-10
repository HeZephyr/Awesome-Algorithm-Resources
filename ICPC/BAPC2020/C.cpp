/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 16:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n,p;//n个团队，m个题目。
bool flag;//判断是否可以唯一确定。
int t[N],ans[N];//t[i]表示第i个团队的解题时间。ans[i]表示其解决了多少个问题。
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(t[i] != 0 && p == 0){
            flag = true;
        }
        if(t[i] == 0){
            //罚时为0，说明没有解决问题。
            ans[i] = p = 0;
        }
        else if(t[i] >= t[i - 1]){
            ans[i] = p;
        }
        else{
            p --;
            ans[i] = p;
        }
        if(p < 0)flag = true;
        //解决从2突然跳到0的结果。
        if(ans[i - 1] - ans[i] > 1){
            flag = true;
        }
    }
    if(flag || (ans[n] > 1 && t[n] != 0)){
        printf("ambiguous\n");
    }
    else{
        for(int i = 1; i <= n; ++ i){
            printf("%d%c\n", ans[i], i == n ? '\n' : ' ');
        }
    }
}
int main(){
    scanf("%d%d", &n, &p); 
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &t[i]);
    }
    solve();
    return 0;
}