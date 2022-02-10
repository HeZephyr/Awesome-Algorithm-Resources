/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-08 19:04
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s;
void solve(){
    string temp;
    string result;
    int maxx = 0;
    for(int i = 0; i < n - 1; ++ i){
        temp = s.substr(i,2);
        int cnt = 0;
        for(int j = 0; j < n - 1; ++ j){
            if(s.substr(j,2) == temp)cnt ++;
        }
        if(cnt > maxx){
            maxx = cnt;
            result = temp;
        }
    }
    cout << result << endl;
}
int main(){
    cin >> n >> s;	
    solve();
    return 0;
}