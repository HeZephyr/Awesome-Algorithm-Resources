#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n;
void solve(){
    if(n % 4 == 0){
        puts("bob");
    }
    else{
        puts("kiki");
    }
}
int main(){	
    cin >> n;
    solve();
    return 0;
}