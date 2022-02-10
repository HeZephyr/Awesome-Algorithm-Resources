/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-26 18:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int cnt[110];
int id[110];
int sum = 0;
void solve(){
    if(sum < k)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 1, x = 0; i <= 100 && x < k; ++ i){
            if(cnt[i] >= 1){
                ++ x;
                cout << id[i] << " ";
            }
        }
        cout << endl;
    } 
}
int main(){	
    cin >> n >> k;
    for(int i = 1, x; i <= n; ++ i){
        cin >> x;
        if(!cnt[x])++ sum;
        ++ cnt[x];
        id[x] = i;
    }
    solve();
    return 0;
}