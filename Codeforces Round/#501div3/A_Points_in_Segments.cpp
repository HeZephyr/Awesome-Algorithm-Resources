/**
  *@filename:A_Points_in_Segments
  *@author: pursuit
  *@created: 2021-10-26 19:00
**/
#include <bits/stdc++.h>
#define l first 
#define r second
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
pii a[N];
int cnt[N];
void solve(){
    vector<int> res;
    for(int i = 1; i <= m; ++ i){
        if(!cnt[i])res.push_back(i);
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++ i){
        cout << res[i] << " ";
    }
    cout << endl;
}
int main(){	
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i].l >> a[i].r;
        for(int j = a[i].l; j <= a[i].r; ++ j)++ cnt[j];
    }
    solve();
    return 0;
}