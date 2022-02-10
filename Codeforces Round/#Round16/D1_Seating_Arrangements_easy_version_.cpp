/**
  *@filename:D1_Seating_Arrangements_easy_version_
  *@author: pursuit
  *@created: 2021-09-12 22:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 300 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//若ai < aj，则si < sj
int t, n, m, a[N], pos[N];//代表坐第几个位置。
bool vis[N];
bool cmp(int i, int j){
    if(a[i] == a[j])return i > j;
    return a[i] < a[j];
}
void solve(){
    sort(pos + 1, pos + 1 + m, cmp);
    memset(vis, 0, sizeof(vis));
    int res = 0;
    for(int i = 1; i <= m; ++ i){
        int x = pos[i];
        //debug(x);
        for(int j = 1; j < x; ++ j){
            if(vis[j])++ res;
        }
        vis[x] = true;
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &a[i]);
            pos[i] = i;
        }
        solve();
    }
    return 0;
}