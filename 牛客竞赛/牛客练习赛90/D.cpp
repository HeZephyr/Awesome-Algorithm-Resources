/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-10-29 21:23
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
struct node{
    int l, r, id;
}a[110];
void solve(){
    int idx = 1, cnt = 0;
    while(true){
        if(cnt == 2){
            int pre = a[idx].l, next = a[idx].r;
            cout << a[idx].id << " ";
            if(pre == next)break;
            a[pre].r = a[next].id;
            a[next].l = a[pre].id;
            cnt = 0;
        }
        else{
            idx = a[idx].r;
            ++ cnt;
        }
    }
    cout << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            a[i].id = i;
            a[i].r = i + 1;
            if(a[i].r > n)a[i].r -= 1;
            a[i].l = i - 1;
            if(a[i].l < 1)a[i].l = n;
        }
        solve();
    }
    return 0;
}