/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-10 12:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
string s;
void solve(){
    char minn = 'z';
    for(auto &x : s){
        min = min(x,minn);
    }
    //通过这个来构造。
    int len = 0;
    vector<int> ans;
    for(int i = 1; i <= k; ++ i){
        if(k % i == 0){
            ans.push_back(i);
        }
    }
    int idx = ans.
    string str = "";
    while(len != n){
        
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        cin >> s;
        solve();
    }	
    return 0;
}