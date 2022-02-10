/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-24 21:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char r[N],b[N];
void solve(){
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(r[i] > b[i])cnt1 ++;
        else if(r[i] < b[i])cnt2 ++;
    }
    if(cnt1 == cnt2){
        puts("EQUAL");
    }
    else if(cnt1 > cnt2){
        puts("RED");
    }
    else{
        puts("BLUE");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        scanf("%s%s", r + 1, b + 1);
        solve();
    }
    return 0;
}