/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-24 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k, x;
ll s;
bool vis[80];
ll power[80];
void init(){
    power[1] = 1;
    for(int i = 2; i <= 64; ++ i){
        power[i] = power[i - 1] * 2;
    } 
}
void solve(){
    for(int i = n; i >= 1; -- i){
        if(!vis[i] && s >= power[i]){
            s -= power[i];
            //cout << power[i] << endl;
        }
    }
    if(s)puts("NO");
    else puts("YES");
}
int main(){	
    init();
    //cout << power[64] << endl;
    cin >> n >> k >> s;
    for(int i = 1; i <= k; ++ i){
        cin >> x;
        vis[x] = true;
    }
    solve();
    return 0;
}