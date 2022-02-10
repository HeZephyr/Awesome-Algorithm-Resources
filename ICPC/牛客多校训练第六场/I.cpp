/**
  *@filename:I
  *@author: pursuit
  *@created: 2021-08-06 19:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;
#define l first 
#define r second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//若l <= r,则区间表示为[l,r]
//若l > r，则区间表示为[l,l + 1...n,1...r];
int t,n,m;
int l,r;
void solve(){
    vector<pii> interval(m);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &l, &r);
        interval[i] = {l,r};
    }
    printf("%d\n", m);
    sort(interval.begin(), interval.end());
    for(int i = 0; i < m; ++ i){
        printf("%d %d\n", interval[i].l, interval[(i + m - 1) % m].r);
        //cout << (i + m - 1) % m << endl;
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        solve();
    }	
    return 0;
}