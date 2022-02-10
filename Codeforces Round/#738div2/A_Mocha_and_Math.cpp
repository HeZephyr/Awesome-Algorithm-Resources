/**
  *@filename:A_Mocha_and_Math
  *@author: pursuit
  *@created: 2021-08-15 22:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
int minn;
void solve(){
    for(int i = 2; i <= n; ++ i){
        a[1] = a[1] & a[i];
    }
    cout << a[1] << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}