/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-11 10:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 500 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//找到3 * 3矩阵的特例，再从1入口进去即可。
int n,res[N][N];
void solve(){
    if(n <= 2){
        puts("-1");
    }
    else{
        res[1][1] = 9,res[1][2] = 5,res[1][3] = 6;
        res[2][1] = 7,res[2][2] = 2,res[2][3] = 8;
        res[3][1] = 1,res[3][2] = 3,res[3][3] = 4;
        int t = n,num = 0;//num为编号。
        while(t > 3){
            if(t % 2 == 0){
                for(int i = 1; i <= t; ++ i){
                    res[i][t] = ++ num;
                }
                for(int j = t - 1; j >= 1; -- j){
                    res[t][j] = ++ num;
                }
            }
            else{
                for(int j = 1; j <= t; ++ j){
                    res[t][j] = ++ num;
                }
                for(int i = t - 1; i >= 1; -- i){
                    res[i][t] = ++ num;
                }
            }
            t --;
        }
        //最后编号为num。
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                if(i <= 3 && j <= 3)res[i][j] += num;
                printf("%d ", res[i][j]);
            }
            puts("");
        }
    }
}
int main(){	
    scanf("%d", &n);
    solve();
    return 0;
}