/**
  *@filename:E_Robot_on_the_Board_1
  *@author: pursuit
  *@created: 2021-11-02 23:46
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
char s[N];
void solve(){
    int min1 = 0, max1 = n + 1, min2 = 0, max2 = m + 1;//边界。
    int x = 0, y = 0;
    int resx = 1, resy = 1;
    int len = strlen(s + 1);
    for(int i = 1; i <= len; ++ i){
        if(s[i] == 'R')y += 1;
        else if(s[i] == 'L')y -= 1;
        else if(s[i] == 'D')x += 1;
        else x -= 1;
        min2 = max(min2, y);
        max2 = min(max2, y);
        min1 = max(min1, x);
        max1 = max(max1, y);
        if(min2 + 1 >= max2 || min1 + 1 >= max1){
            break;
        }
        else{
            resx = min1 + 1, resy = min2 + 1;
        }
    }
    cout << resx << " " << resy << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}