/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-21 14:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,a[3];
bool vis[N];
void solve(){
    sort(a,a + 3);
    if(a[1] > a[0]){
        a[0] ++;
        if(a[1] > a[0])a[1] --;
        if(a[2] > a[0])a[2] --;
    }
    else if(a[1] == a[0]){
        a[0] ++,a[1] ++;
        if(a[2] > a[0])a[2] --;
        else if(a[2] < a[0])a[2] ++;
    }
    int ans = abs(a[2] - a[1]) + abs(a[2] - a[0]) + abs(a[1] - a[0]);
    printf("%d\n", ans);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        for(int i = 0; i < 3; ++ i)scanf("%d", &a[i]);
        solve();
    }
    return 0;
}