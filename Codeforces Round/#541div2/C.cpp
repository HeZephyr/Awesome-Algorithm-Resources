/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-09 16:44
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
void solve(){
    sort(a + 1, a + n + 1);
    int l = n - 1, r = n;
    deque<int> q;
    if(n & 1){
        q.push_back(a[n]);
        -- l, -- r;
    }
    while(l >= 1){
        q.push_back(a[r]);
        q.push_front(a[l]);
        l -= 2;
        r -= 2;
    }
    while(!q.empty()){
        printf("%d ", q.front());
        q.pop_front();
    }
    puts("");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}