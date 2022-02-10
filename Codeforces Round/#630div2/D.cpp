/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-11 16:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 500 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int k,a = 1 << 17;
void solve(){
    printf("2 3\n");
    printf("%d %d %d\n", a + k, k , 0);
    printf("%d %d %d\n", a, a + k, k);
}
int main(){	
    scanf("%d", &k);
    solve();
    return 0;
}