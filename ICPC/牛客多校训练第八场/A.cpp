/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-09 15:10
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 4933;
const int INF = 0x3f3f3f3f;

int n,m,k,a,l;//总共改变了n - m个问题，而m个问题并未更改。而是增强了范围。
int qsm(int n,int q){
    n %= P;
    int ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    int ans = 1;
    int x,y,z;
    while(k -- ){
        cin >> x >> y >> z;
        if(x)ans = ans * (1 - y * qsm(z,P - 2) % P) % P;
    }
    cout << (a + ans + P) % P << endl;
}
int main(){	
    //n,m,l,x都没有用。
    cin >> n >> m >> k >> a >> l;
    solve();
    return 0;
}