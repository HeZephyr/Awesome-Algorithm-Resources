/**
  *@filename:B2
  *@author: pursuit
  *@created: 2021-08-27 10:33
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,p[N],father[N],num[N];
int find(int x){
    int r = x;
    while(father[r] != r)r = father[r];
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    int fu,fv;
    for(int i = 1; i <= n; ++ i){
        fu = find(i), fv = find(p[i]);
        if(fu != fv){
            father[fv] = fu;
            num[fu] += num[fv];
        }
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d%c", num[find(i)], i == n ? '\n' : ' ');
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &p[i]);
            father[i] = i, num[i] = 1;
        }
        solve();
    }
    return 0;
}