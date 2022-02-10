/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-05 17:45
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
void solve(){
    if(n == 1)cout << "a" << endl;
    else{
        //如果我们刚好构造出了长度为n的字符串。那就可以了。
        //左右两边都放n / 2个。中间根据奇偶性放b还是放bc。这样能确保截取到的a的数量为奇数。
        string strL = string(n / 2, 'a'), strR = string(n / 2 - 1, 'a');
        string s = strL + (n % 2 ? "bc" : "b") + strR;
        cout << s << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}