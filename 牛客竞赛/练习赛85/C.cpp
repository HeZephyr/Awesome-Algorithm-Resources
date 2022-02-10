/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-24 19:54
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
int y[4];
void solve(){
    if(y[1] > y[2] + 1 && y[2] > y[3] + 1){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    y[1] = 1e9, y[2] = 1e8, y[3] = 1e7;
    cin >> n >> m;
    int xx, yy;
    for(int i = 1; i <= m; ++ i){
        cin >> xx >> yy;
        y[xx] = min(y[xx], yy);
    }
    solve();
    return 0;
}