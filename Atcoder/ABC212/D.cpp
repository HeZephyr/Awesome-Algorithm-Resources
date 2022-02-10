/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 20:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
priority_queue<ll,vector<ll>,greater<ll> > q;
void solve(){
    int op;
    ll sum = 0,x;
    while(t -- ){
        cin >> op;
        if(op == 3){
            cout << q.top() + sum << endl;
            q.pop();
            continue;
        }
        cin >> x;
        if(op == 1){
            x -= sum;
            q.push(x);
        }
        else{
            sum += x;
        }
    }
}
int main(){
    cin >> t;
    solve();
    return 0;
}