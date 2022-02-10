/**
  *@filename:Median
  *@author: pursuit
  *@created: 2021-08-05 12:09
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,m;//m个集合。
int b[N],vis[N];
void solve(){
    sort(b + 1,b + 1 + m);
    int pre = -1;
    bool flag = false;
    for(int i = 1; i <= m; ++ i){
        if(b[i] == pre){
            flag = true;
            break;
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &b[i]);
        }
        solve();
    }
    return 0;
}