/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-11 14:29
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
int a,b,c,d;//a次左，b次右，c次下，d次上。
int x,y,x1,Y1,x2,y2;
void solve(){
    //左和右可以相互抵消。
    int temp1 = min(a,b),temp2 = min(c,d);
    if((x == x1 && x == x2 && (b > 0 || a > 0)) || 
    (y == Y1 && y == y2 && (c > 0 || d > 0))){
        puts("No");
        return;
    } 
    a -= temp1,b -= temp1,c -= temp2,d -= temp2;
    bool flag = false;
    if(x - x1 < a || x2 - x < b || y - Y1 < c || y2 - y < d){
        flag = true;
    }
    if(flag){
        puts("No");
    }
    else{
        puts("Yes");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &Y1, &x2, &y2);
        solve();
    }
    return 0;
}