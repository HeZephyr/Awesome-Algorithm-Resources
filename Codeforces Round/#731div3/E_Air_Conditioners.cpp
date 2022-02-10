/**
  *@filename:E_Air_Conditioners
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 23:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 300000 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int q,n,k,t[N],a[N];
int minn[N];
priority_queue<pii,vector<pii>,greater<pii> > p;
void solve(){
    pii head,temp;
    while(!p.empty()){
        head= p.top();
        p.pop();
        //这个点出来的对于此位置一定是最小温度值。
        if(minn[head.second] != INF){
            continue;
        }
        else{
            minn[head.second] = head.first;
        }
        if(head.second > 1){
            if(minn[head.second - 1] == INF)p.push({head.first + 1,head.second - 1});
        }
        if(head.second < n){
            if(minn[head.second + 1] == INF)p.push({head.first + 1,head.second + 1});
        }
    }
    for(int i = 1; i <= n; ++ i){
        cout << minn[i] << " ";
    }
    cout << endl;
}
int main(){
    scanf("%d", &q);
    while(q -- ){
        scanf("%d%d", &n, &k);
        while(!p.empty())p.pop();
        for(int i = 1; i <= n; ++ i){
            minn[i] = INF;
        }
        for(int i = 1; i <= k; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= k; ++ i){
            scanf("%d", &t[i]);
            p.push({t[i],a[i]});
        }
        solve();
    }
    return 0;
}