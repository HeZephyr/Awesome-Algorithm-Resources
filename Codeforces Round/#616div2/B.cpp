/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-22 15:43
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//选择一个正数-1.
int t,n,a[N],maxx,idx;
void solve(){
    int st = -1,ed = n;
    for(int i = 1; i <= n; ++ i){
        if(a[i] < i - 1)break;
        st = i;
    }
    for(int i = n; i >= 1; -- i){
        if(a[i] < n - i)break;
        ed = i;
    }
    printf("%s\n", st < ed ? "No" : "Yes");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}