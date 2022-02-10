/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 14:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[N];     
map<int,int> p;  
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        p[a[i]] ++;
        if(p[a[i]] > 1){
            //说明相同的，我们最大化让其加1.
            if(p[a[i] + 1] < 1){
                cnt ++;
            }
            p[a[i] + 1] ++; 
        }
        else{
            cnt ++;
        }
    }
    cout << cnt << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        p.clear();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}