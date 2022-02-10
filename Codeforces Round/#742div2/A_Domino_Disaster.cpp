/**
  *@filename:A_Domino_Disaster
  *@author: pursuit
  *@created: 2021-09-05 22:36
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
char s[N];
void solve(){
    char pre = ' ';
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'U'){
            printf("D");
        }
        else if(s[i] == 'D'){
            printf("U");
        }
        else{
            printf("%c", s[i]);
        }
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%s", &n, s + 1);
        solve();
    }
    return 0;
}