/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-12 11:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//有n块木板组成的栅栏，要使ai变成bi。邀请了m个画家，第j个画家在第j时刻到达，然后选择一个木板着色为cj。
int t, n, m, a[N], b[N], c[N];
void solve(){
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &c[i]);
        }
        solve();
    }
    return 0;
}