/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-07 19:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//一天持续h个小时，每小时持续m分钟。
//只有01258这几个反射之后才是有效时间。
int to[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int t, h, m, hh, mm;
void solve(){
    for(int i = hh; i < h; ++ i){
        for(int j = (i == hh) ? mm : 0; j < m; ++ j){
            if(to[i % 10] >= 0 && to[i / 10] >= 0 && to[j % 10] >= 0 && to[j / 10] >= 0){
                int x = to[j % 10] * 10 + to[j / 10], y = to[i % 10] * 10 + to[i / 10];
                if(x >= 0 && x < h && y >= 0 && y < m){
                    printf("%d%d:%d%d\n", i / 10, i % 10, j / 10, j % 10);
                    return;
                }
            }
        }
    }
    for(int i = 0; i <= hh; ++ i){
        for(int j = 0; j < m; ++ j){
            if(to[i % 10] >= 0 && to[i / 10] >= 0 && to[j % 10] >= 0 && to[j / 10] >= 0){
                int x = to[j % 10] * 10 + to[j / 10], y = to[i % 10] * 10 + to[i / 10];
                if(x >= 0 && x < h && y >= 0 && y < m){
                    printf("%d%d:%d%d\n", i / 10, i % 10, j / 10, j % 10);
                    return;
                }
            }
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &h, &m);
        scanf("%d:%d", &hh, &mm);
        solve();
    }
    return 0;
}