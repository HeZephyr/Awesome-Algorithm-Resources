/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-07 16:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
struct node{
    int x,y,z;
};
node ans[N];
void solve(){
    int tot = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            int k = n - i - j;
            if(k <= 0)k += n;
            if(k > j){
                ans[++ tot] = {i,j,k};
            }
        }
    }
    printf("%d\n", tot);
    for(int i = 1; i <= tot; ++ i){
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
    }
}
int main(){	
    scanf("%d", &n);
    solve();
    return 0;
}