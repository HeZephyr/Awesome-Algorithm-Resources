#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;
struct node{
    ll x, sum;
    bool operator < (const node &A) const{
        return sum < A.sum;
    }
};
int main(){
    cin >> n >> m >> k;
    priority_queue<node, vector<node> > q;
    for(ll i = 1;i <= n;i++){
        q.push({i, i*m});
    }
    node tem;
    k--;
    while(k --){
        tem = q.top();
        q.pop();
        q.push({tem.x, tem.sum - tem.x});
    }
    ll ans = q.top().sum;
    cout << ans << endl;
    return 0;
}