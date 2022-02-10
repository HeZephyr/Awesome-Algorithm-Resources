/**
  *@filename:毒瘤数据结构题
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 15:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e6 + 5;
const int P = 1e9+7;

int n;
int a[N];
void solve(){
    int l = 1,last = 1;
    int op,x,pre;
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &op, &x);
        if(op == 1){
            a[x] = 1;
            while(a[l] && l <= n + 1){
                l ++;
            }
            last = l;
        }
        else{
            bool flag = false;
            if(a[x])flag = true;
            a[x] = 1;//这里是临时补上去的。
            while(a[l] && l <= n + 1){
                l ++;
            }
            printf("%d\n",l);
            l = last;
            if(!flag)a[x] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    solve();
    return 0;
}