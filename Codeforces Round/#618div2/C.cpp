/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-14 09:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
void solve(){
    int idx = 0, cnt;
    for(int i = 30; i >= 0; -- i){
        cnt = 0;
        for(int j = 1; j <= n; ++ j){
            if((a[j] >> i) & 1){
                idx = j;
                ++ cnt;
            }
            if(cnt >= 2)break;
        }
        if(cnt == 1)break;
    }
    if(idx)printf("%d ", a[idx]);
    for(int i = 1; i <= n; ++ i){
        if(i == idx)continue;
        printf("%d ", a[i]);
    }
    puts("");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}