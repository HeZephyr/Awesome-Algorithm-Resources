/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-20 15:38
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
struct node{
    int a,t;
    //按数量排序。
    bool operator < (const node &A){
        if(a == A.a){
            return t < A.t;
        }
        return a < A.a;
    }
}nodes[N];
priority_queue<int> q;
void solve(){
    sort(nodes + 1, nodes + n + 1);
    int i = 0;
    ll ans = 0,sum = 0,num;
    while(!q.empty() || i <= n){
        if(q.empty()) num = nodes[i].a;
        while(i <= n && nodes[i].a == num){
            //将相同值的入队。
            q.push(nodes[i].t);
            sum += nodes[i ++].t;
        }
        //相同值得都加1.留下最小的那个。
        sum -= q.top(),q.pop();
        ans += sum,num ++;//编号+1。
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &nodes[i].a);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &nodes[i].t);
    }
    solve();
    return 0;
}