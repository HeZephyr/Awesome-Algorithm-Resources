#include<bits/stdc++.h>
#define LOG 20
#define ll long long 
const int MAXN = 1e6 + 7;
int table[MAXN][LOG];
string sum;
namespace RMQ{
    void init(int n){
        for(int i = 1; i <= n; ++i)table[i][0] = i;
        for(int j = 1; (1 << j) <= n; ++j){
            for(int i = 1; i + (1 << j) - 1 <= n; ++i){
                int x = table[i][j - 1], y = table[i + (1 << (j - 1))][j - 1];
                table[i][j] = sum.substr(1, x) > sum.substr(1, y) ? x : y; 
            }
        }
    }
    int query(int l, int r){
        int k = log2(r - l + 1);
        int x = table[l][k], y = table[r - (1 << k) + 1][k];
        return sum.substr(1, x) > sum.substr(1, y) ? x : y; 
    }
}
struct element{
    int o, l, r, t;
    element(){}
    element(int o, int l, int r) : o(o), l(l), r(r), t(RMQ::query(l, r)){}
    friend bool operator < (const element& a, const element& b){
        return sum.substr(a.o, a.t - a.o + 1) < sum.substr(b.o, b.t - b.o + 1);
    }
};
using namespace std;
std::priority_queue<element > Q;
int main(){
    int n, k, L, R;
    cin >> sum;
    n = sum.length();
    sum = ' ' + sum;
    int m;
    L = 1, R = n;
    scanf("%d", &m);
    RMQ::init(n);
    for(int i = 1; i <= n; ++i){
        if(i + L - 1 <= n)
            Q.push(element(i, i + L -1, min(i + R - 1, n)));
    }
    ll ans = 0;
    while(k--){

    }

}