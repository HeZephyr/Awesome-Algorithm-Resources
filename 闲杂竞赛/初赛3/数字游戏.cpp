/**
  *@filename:数字游戏
  *@author: pursuit
  *@created: 2021-08-07 14:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


int t;
int n;
double maxx,minn,ave;
void solve(){
    if(n == 1){
        if(maxx == minn && minn == ave){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    else if(n == 2){
        if(maxx >= minn && 2 * ave == maxx + minn){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    else if(ave * n >= minn * (n - 1) + maxx && ave * n <= maxx * (n - 1) + minn){
        puts("yes");
    }
    else{
        puts("no");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%lf%lf%lf", &n, &maxx, &minn, &ave);
        solve();
    }
    return 0;
}