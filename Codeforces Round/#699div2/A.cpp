/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-12 10:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, x, y, cnt[4];
char s[N];
void solve(){
    int n = strlen(s + 1);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'U')++ cnt[0];
        else if(s[i] == 'D')-- cnt[1];
        else if(s[i] == 'R')++ cnt[2];
        else -- cnt[3];
    }
    if(y >= cnt[1] && y <= cnt[0] && x >= cnt[3] && x <= cnt[2]){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> x >> y >> s + 1;
        solve();
    }
    return 0;
}