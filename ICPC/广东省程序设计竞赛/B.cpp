#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e7 + 10;
ll fib[35];
ll f[N];
void init(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 35; ++ i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}
void dfs(int idx, ll x, ll ans){
    if(x <= 1e7){
        f[x] += ans;
    }
    for(int i = idx; i < 35; ++ i){
        dfs(idx + 1, x + fib[i], ans * fib[i]);
    }
}
int main(){
    init();
    dfs(0, 0, 1);
    for(int i = 1; i <= 1e7; ++ i){

    }
    return 0;
}