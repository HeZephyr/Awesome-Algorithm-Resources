#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int dist[N];//表示该点是否已经访问过了。
void solve(){
    queue<int> q;
    q.push(1);
    int head, temp;
    dist[1] = 0;
    while(!q.empty()){
        head = q.front();
        q.pop();
        //cout << head << " ";
        if(head == n)break;
        if(a[head] > 0){
            for(int i = head + 1; i <= min(head + a[head], n); ++ i){
                if(dist[i] == INF){
                    dist[i] = dist[head] + 1;
                    q.push(i);
                }
            }
        }
        else{
            for(int i = max(1, head + a[head]); i >= 1; -- i){
                if(dist[i] == INF){
                    dist[i] = dist[head] + 1;
                    q.push(i);
                }
            }
        }
    }
    if(dist[n] == INF)puts("-1");
    else printf("%d\n", dist[n]);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        dist[i] = INF;
    }
    solve();
    return 0;
}