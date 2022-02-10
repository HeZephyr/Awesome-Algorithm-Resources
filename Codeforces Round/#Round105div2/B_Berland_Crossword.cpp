/**
  *@filename:B_Berland_Crossword
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-14 08:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,u,r,d,l;
int x[4];
bool check(){
    for(int i = 0; i < 4; ++ i){
        if(x[i] < 0 || x[i] > n - 2){
            return false;
        }
    }
    return true;
}
void solve(){
    //我们可以枚举这四个顶点的填涂情况。
    bool flag = false;
    for(int i = 0; i <= 1; ++ i){//左上角顶点
        for(int j = 0; j <= 1; ++ j){//右上角顶点
            for(int k = 0; k <= 1; ++ k){//左下角顶点
                for(int q = 0; q <= 1; ++ q){//右下角顶点
                    //下面的两个顶点。
                    x[0] = u - i - j;
                    x[1] = r - j - q;
                    x[2] = d - k - q;
                    x[3] = l - i - k;
                    if(check()){
                        flag = true;
                    }
                }
            }
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> u >> r >> d >> l;
        solve();
    }
    return 0;
}