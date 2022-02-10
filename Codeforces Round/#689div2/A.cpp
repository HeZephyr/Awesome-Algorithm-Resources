/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-18 17:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k,n;
void solve(){
    int cnt = 0;
    for(int i = 0; i < n; ++ i){
        printf("%c", (cnt ++) % 3 + 'a');
    }
    puts("");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        solve();
    }	
    return 0;
}