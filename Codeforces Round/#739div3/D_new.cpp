/**
  *@filename:D_new
  *@author: pursuit
  *@created: 2021-08-19 00:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

string a[N];
int t,minn;
string n;
void init(){
    //预处理处2的次幂。
    ll temp = 1;
    for(int i = 0; i <= 60; ++ i){
        a[i] = to_string(temp);
        temp *= 2;
    }
}
void solve(){
    int ans = INF;
    for(int i = 0; i <= 60; ++ i){
        int cnt = 0;
        int l1 = 0,l2 = 0;
        while(l1 < a[i].size() && l2 < n.size()){
            if(a[i][l1] != n[l2]){
                l2 ++;
                cnt ++;
            }
            else{
                l1 ++,l2 ++;
            }
        }
        if(l1 != a[i].size()){
            cnt += (a[i].size() - l1);
        }
        if(l2 != n.size()){
            cnt += (n.size() - l2);
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}
int main(){	
    cin >> t;
    init();
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}