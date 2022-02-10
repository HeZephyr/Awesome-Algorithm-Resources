/**
  *@filename:D2_Seating_Arrangements_hard_version_
  *@author: pursuit
  *@created: 2021-09-12 23:16
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//若ai < aj，则si < sj
int t, n, m;
struct node{
    int a, b;
}nodes[N];
bool cmp1(node &A, node &B){
    if(A.a == B.a)return A.b < B.b;
    return A.a < B.a;
}
bool cmp2(node &A, node &B){
    if(A.a == B.a)return A.b > B.b;
    return A.a < B.a;
}
void solve(){
    ll res = 0;
    sort(nodes + 1, nodes + 1 + n * m, cmp1);
    for(int i = 1; i <= n; ++ i){
        sort(nodes + (i - 1) * m + 1, nodes + i * m + 1, cmp2);
        for(int j = 1; j <= m; ++ j){
            //cout << i << " " << nodes[(i - 1) * m + j].a << " " << nodes[(i - 1) * m + j].b << endl;
            for(int k = 1; k < j; ++ k){
                if(nodes[(i - 1) * m + j].b > nodes[(i - 1) * m + k].b)++ res;
            }
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n * m; ++ i){
            scanf("%d", &nodes[i].a);
            nodes[i].b = i;
        }
        solve();
    }
    return 0;
}