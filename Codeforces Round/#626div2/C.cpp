/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-15 14:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s;
//))((())(
void solve(){
    int ans = 0,sum = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] == '(')ans ++;
        else ans --;
        if(ans < 0 || ans == 0 && s[i] == '('){
            sum ++;
        }
    }
    printf("%d\n", ans != 0 ? - 1 : sum);
}
int main(){	
    cin >> n >> s;
    solve();
    return 0;
}
//HYSBZ 4373
//601B
//1136E
//1401F