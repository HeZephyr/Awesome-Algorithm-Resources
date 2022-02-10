/**
  *@filename:C_Songs_Compression
  *@author: pursuit
  *@created: 2021-10-26 19:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, a[N], b[N], pos[N];
ll sum1, sum2;
bool cmp(int i, int j){
    return a[i] - b[i] > a[j] - b[j];
}
void solve(){
    if(sum1 > m){
        puts("-1");
    }
    else{
        sort(pos + 1, pos + 1 + n, cmp);
        int idx = 1;
        while(sum2 > m){
            sum2 -= (a[pos[idx]] - b[pos[idx]]);
            ++ idx;
        }
        cout << idx - 1 << endl;
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
        sum1 += b[i], sum2 += a[i];
        pos[i] = i;
    }
    solve();
    return 0;
}