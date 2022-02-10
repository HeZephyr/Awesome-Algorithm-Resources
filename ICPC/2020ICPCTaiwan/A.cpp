/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-10 14:47
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int x,y;
char s[10][15] = {"RRRRRRRRRD","UDLLLLLLLL","URRRRRRRRD","UDLLLLLLLL","URRRRRRRRD","UDLLLLLLLL","URRRRRRRRD","UDLLLLLLLL","URRRRRRRRD","ULLLLLLLLL"};
void solve(){
    int cnt = 0;
    while(true){
        cout << x << " " << y << endl;
        cnt ++;
        if(cnt == 100)break;
        if(s[x][y] == 'R'){
            y += 1;
        }
        else if(s[x][y] == 'L'){
            y -= 1;
        }
        else if(s[x][y] == 'D'){
            x += 1;
        }
        else{
            x -= 1;
        }
    }
}
int main(){
    cin >> x >> y;	
    solve();
    return 0;
}