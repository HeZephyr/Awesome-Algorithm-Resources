/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-10 18:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],b[N];
void solve(){
    bool flag = false;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] == b[i]){
        }
        else if(a[i] < b[i] && cnt1 == 0){
            flag = true;
            break;
        }
        else if(a[i] > b[i] && cnt2 == 0){
            flag = true;
            break;
        }
        if(a[i] == 1)cnt1 ++;
        else if(a[i] == -1)cnt2 ++;
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        for(int i = 1; i <= n; ++ i){
            cin >> b[i];
        }
        solve();
    }
    return 0;
}