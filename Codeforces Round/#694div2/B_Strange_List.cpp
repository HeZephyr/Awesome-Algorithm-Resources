/**
  *@filename:B_Strange_List
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 19:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,x;
queue<pii> q;
void solve(){
    ll ans = 0;
    pii head;
    bool flag = true;//机器运作标志。
    while(!q.empty()){
        head = q.front();
        q.pop();
        ans += 1LL * head.first * head.second;
        if(head.first % x != 0)flag = false;
        if(flag){
            q.push({head.first / x , head.second * x});
        }
        //cout << head.first << " " << head.second << endl;
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d", &t);
    while(t -- ){ 
        scanf("%d%d", &n, &x);
        int temp;
        while(!q.empty())q.pop();
        for(int i = 1; i <= n; ++ i){
            scanf("%d",&temp);
            q.push({temp,1});
        }
        solve();
    }
    return 0;
}