/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-13 09:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
int x,y,p,c;
void solve(){
    bool flag = false;
    p = c = 0;
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &x, &y);
        if(x < p || y < c || y - c > x - p){
            flag = true;
        }
        p = x, c = y;
    }
    printf("%s\n", flag ? "NO" : "YES");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        solve();
    }
    return 0;
}