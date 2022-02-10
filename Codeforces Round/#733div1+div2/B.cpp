/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-31 11:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 20 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, h, w;
char s[N][N];
bool check(int i, int j){
    if(s[i][j] == '1')return false;
    if(i - 1 >= 1){
        if(s[i - 1][j] == '1')return false;
        if(j - 1 >= 1){
            if(s[i - 1][j - 1] == '1')return false;   
        }
        if(j + 1 <= w){
            if(s[i - 1][j + 1] == '1')return false;
        }
    }
    if(i + 1 <= h){
        if(s[i + 1][j] == '1')return false;
        if(j - 1 >= 1){
            if(s[i + 1][j - 1] == '1')return false;   
        }
        if(j + 1 <= w){
            if(s[i + 1][j + 1] == '1')return false;
        }
    }
    if(j - 1 >= 1 && s[i][j - 1] == '1')return false;
    if(j + 1 <= w && s[i][j + 1] == '1')return false;
    return true;
}
void solve(){
    memset(s, '0', sizeof(s));
    for(int i = 1; i <= h; ++ i){
        if(check(i, 1)){
            s[i][1] = '1';
        }
        if(check(i, w)){
            s[i][w] = '1';
        }
        s[i][w + 1] = '\0';
    }
    for(int j = 1; j <= w; ++ j){
        if(check(1, j)){
            s[1][j] = '1';
        }
        if(check(h, j)){
            s[h][j] = '1';
        }
    }
    for(int i = 1; i <= h; ++ i){
        cout << (s[i] + 1) << endl;
    }
    cout << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> h >> w;
        solve();
    }
    return 0;
}