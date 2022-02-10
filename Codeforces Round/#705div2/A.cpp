/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-07 19:29
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k;
void solve(){
    vector<int> res;
    for(int i = k + 1; i <= n; ++ i){
        res.push_back(i);
    }
    for(int i = k - 1; i >= (k + 1) / 2; -- i){
        res.push_back(i);
    }
    printf("%d\n", int(res.size()));
    for(auto x : res){
        printf("%d ", x);
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