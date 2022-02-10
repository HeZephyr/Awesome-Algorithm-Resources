/**
  *@filename:D_Take_a_Guess
  *@author: pursuit
  *@created: 2021-08-31 12:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k;
ll a[N];
//通过a + b = a & b + a | b。所以我们可以求出a + b,a + c,b + c来求出a b c。
//当然如果已知了a，我们也同样可以通过上述式子求出a + b。
int query(int i,int j){
    ll a,b;
    printf("or %d %d\n", i, j);
    fflush(stdout);
    scanf("%lld", &a);
    printf("and %d %d\n", i, j);
    fflush(stdout);
    scanf("%lld", &b);
    return a + b;
}
void get(int i,int j,int k){
    ll ab = query(i,j),ac = query(i,k), bc = query(j,k);
    //a = ac - bc + ab / 2
    a[i] = (ac - bc + ab) / 2;
    a[j] = ab - a[i],a[k] = ac - a[i];
}
void solve(){
    int i;
    for(i = 1; i <= n; i += 3){
        if(i + 2 > n)break;
        //三个三个一起查。
        get(i, i + 1, i + 2);
    }
    while(i <= n){
        //通过i - 1得到。
        int x = query(1,i);
        a[i] = x - a[1];
        ++ i;
    }
    sort(a + 1, a + n + 1);
    printf("finish %lld\n", a[k]);
}
int main(){	
    scanf("%d%d", &n, &k);
    solve();
    return 0;
}