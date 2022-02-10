/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-11 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
int a[N];
int cnt = 0;
map<int,int> p;
void solve(){
    memset(a,0,sizeof(a));
    for(auto &x : p){
        a[x.second] = x.first;
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; ++ i){
        if(a[i]){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        if(!p[a[i]]){
            cnt ++;
        }
        p[a[i]] = i;
    }	
    solve();
    return 0;
}