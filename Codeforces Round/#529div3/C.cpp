#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[31];
void solve(){
    a[0] = 1;
    for(int i = 1; i < 31; ++ i){
        a[i] = a[i - 1] * 2;
    }
    //我们将n拆成二进制，那么二进制上的每一位都是2的次幂，而每一个不是1的2的次幂又可以拆分成2个2的次幂。通过这种思想去凑k。
    priority_queue<int> pos;
    for(int i = 0; i < 31; ++ i){
        if(n & a[i]){
            pos.push(i);
        }
    }
    //分解操作会使大小+1。如果可行那一定可以达到k。
    while(pos.size() < k && pos.top() > 0){
        int idx = pos.top();
        pos.pop();
        pos.push(idx - 1);
        pos.push(idx - 1);
    }
    if(pos.size() == k){
        cout << "YES" << endl;
        while(!pos.empty()){
            cout << a[(int)pos.top()] << " ";
            pos.pop();
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> n >> k;
    solve();
    return 0;
}