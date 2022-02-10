/**
  *@filename:G_Changing_Brackets
  *@author: pursuit
  *@created: 2021-10-16 17:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, q, sum[N], l, r;
string s;
void solve(){
    cin >> l >> r;
    cout << abs(sum[r] - sum[l - 1]) << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s >> q;
        for(int i = 0; i < s.size(); ++ i){
            sum[i + 1] = sum[i];
            if(s[i] == '[' || s[i] == ']'){
                if(i % 2)++ sum[i + 1];
                else -- sum[i + 1];
            }
        }
        while(q -- ){
            solve();
        }
    }
    return 0;
}
