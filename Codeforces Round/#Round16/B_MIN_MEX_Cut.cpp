/**
  *@filename:B_MIN_MEX_Cut
  *@author: pursuit
  *@created: 2021-09-12 22:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
string s;
void solve(){
    //是Mex最小。
    int minn = 2;//最下为2.
    int cnt = 0, ans = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '0'){
            ++ cnt;
        }
        else{
            if(cnt > 0)++ ans;
            cnt = 0;
        }
    }
    if(cnt > 0)++ ans;
    if(ans == 0){
        cout << 0 << endl;
    }
    else{
        cout << min(ans, minn) << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}