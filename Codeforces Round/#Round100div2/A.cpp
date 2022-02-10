/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-17 09:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,a,b,c;
void solve(){
    int sum = a + b + c;
    if(sum % 9 == 0 && min(a,min(b,c)) >= sum / 9){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &a, &b, &c);
        solve();
    }
    return 0;
}