/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-11 19:29
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,w,a[N];
void solve(){
    int maxx = w,minn = 0;
    bool flag = false;
    int cur = 0;
    for(int i = 1; i <= n; ++ i){
        cur += a[i];
        if(cur + minn < 0){
            minn = 0 - cur;
        }
        else if(cur + maxx > w){
            maxx = w - cur;
        }
    }
    if(maxx < minn){
        puts("0");
    }
    else{
        printf("%d", maxx - minn + 1);
    }
}
int main(){	
    scanf("%d%d", &n, &w);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}