/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 08:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[N],c[3];   
void solve(){
    //从0 - > 1转换1次，从1 - > 2转换1次，从2 - > 0转换一次。
    int avg = (c[0] + c[1] + c[2]) / 3;
    int cnt = 0;
    for(int i = 0; i < 3; ++ i){
        if(c[i] > avg){
            c[(i + 1) % 3] += (c[i] - avg);
            cnt += c[i] - avg;
        }
    }
    for(int i = 0; i < 3; ++ i){
        if(c[i] < avg){
            cnt += avg - c[i];
        }
    }
    cout << cnt << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(c,0,sizeof(c));
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            c[a[i] % 3] ++ ;
        }
        solve();
    }
    return 0;
}