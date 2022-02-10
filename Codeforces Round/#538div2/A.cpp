/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-16 14:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int x,y,z,a,b,c;
void solve(){
    if(x > a || y > a - x + b || x + y + z > a + b + c){
        puts("NO");
    }
    else{
        puts("YES");
    }
}
int main(){	
    cin >> x >> y >> z >> a >> b >> c;
    solve();
    return 0;
}