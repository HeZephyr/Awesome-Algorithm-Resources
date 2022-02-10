#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
void solve(){
    //n个
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= i; ++ j){
            printf("(");
        }
        for(int j = 1; j <= i; ++ j){
            printf(")");
        }
        for(int j = i + 1; j <= n; ++ j){
            printf("(");
        }
        for(int j = i + 1; j <= n; ++ j){
            printf(")");
        }
        puts("");
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}