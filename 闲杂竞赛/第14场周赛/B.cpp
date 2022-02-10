/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-28 19:02
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define l first
#define r second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,ans[N];
pii a[N];
void solve(){
    int t = 0;//为下次开始打饭的时间。
    for(int i = 1; i <= n; ++ i){
        if(a[i].l >= t){
            ans[i] = a[i].l;
            t = a[i].l + 1;
        }
        else if(a[i].r >= t){
            ans[i] = t;
            ++ t;
        }
        else{
            ans[i] = 0;
        }
        //debug(t);
    }
    for(int i = 1; i <= n; ++ i){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i].l >> a[i].r;
        }
        solve();
    }
    return 0;
}
/*
3
2
1 2000
2 2
2
2 2000
2 2
2
2 2
2 2000

1 2 
2 0 
2 3 
*/