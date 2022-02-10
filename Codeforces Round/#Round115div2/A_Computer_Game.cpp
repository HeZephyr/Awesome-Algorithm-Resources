/**
  *@filename:A_Computer_Game
  *@author: pursuit
  *@created: 2021-10-10 17:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
char s[2][N];
void solve(){
    bool flag = false;
    for(int j = 0; j < n; ++ j){
        if(s[0][j] == s[1][j] && s[0][j] == '1'){
            flag = true;
            break;
        }
    }
    if(flag){
        puts("NO");
    }
    else{
        puts("YES");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 0; i < 2; ++ i){
            scanf("%s", s[i]);
        }
        solve();
    }
    return 0;
}