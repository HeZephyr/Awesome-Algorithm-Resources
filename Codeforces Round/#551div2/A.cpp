/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-11-04 21:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, t;
int s[N], d[N], pos[N];
bool cmp(int i, int j){
    return s[i] < s[j];
}
void solve(){
    int res = INF, idx = 0;
    for(int i = 1; i <= n; ++ i){
        //什么时候能坐到。
        int temp;
        if(s[i] >= t){
            temp = s[i] - t;
        }
        else{
            int x = (t - s[i] + d[i] - 1) / d[i];
            temp = x * d[i] + s[i] - t;
        }
        if(temp < res){
            res = temp;
            idx = i;
        }
    }
    cout << idx << endl;
}
int main(){	
    cin >> n >> t;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i] >> d[i];
        pos[i] = i;
    }
    solve();
    return 0;
}