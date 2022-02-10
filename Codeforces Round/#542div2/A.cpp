/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-10 15:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], cnt0, cnt1;
void solve(){
    if(cnt0 >= (n + 1) / 2){
        cout << 1 << endl;
    }
    else if(cnt1 >= (n + 1) / 2){
        cout << -1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        if(a[i] > 0)++ cnt0;
        else if(a[i] < 0)++ cnt1;
    }
    solve();
    return 0;
}