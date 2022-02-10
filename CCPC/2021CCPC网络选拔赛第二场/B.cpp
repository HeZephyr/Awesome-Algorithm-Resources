#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a, b, c;
ll x[2], y[3];
/*
A：x0,y0
B：x1,y0
C：x1,y1
D：x1,y2

*/
ll getY(ll x){
    return a * x * x + b * x + c;
}
bool check(){
    int temp = c - y[0];
    double d = sqrt(1.0 * (b * b - 4 * a * temp));
    double x1 = min((-b - d) / (2 * a), (-b + d) / (2 * a));
    if(x1 >= x[0])return false;
    return true;
}
void solve(){
    if(!check()){
        puts("No");
    }
    else if(getY(x[0]) > y[0] && getY(x[1]) < y[1]){
        puts("Yes");
    }
    else if(getY(x[1]) >= y[0] && getY(x[1]) <= y[2] && getY(x[1]) > y[0] && getY(x[1] + x[1] - x[0]) < y[0]){
        puts("Yes");
    }
    else{
        puts("No");
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c;
        cin >> x[0] >> x[1] >> y[0] >> y[1] >> y[2];
        solve();
    }
    return 0;
}