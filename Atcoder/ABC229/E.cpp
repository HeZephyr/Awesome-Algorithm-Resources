#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, m;
vector<int> g[N];
int res[N];
int find(int x){
    int r = x;
    while(father[r] != r){
        r = father[r];
    }
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        if(u > v)swap(u, v);
        g[u].push_back(v);
    }
    res[n] = 0;
    for(int i = n - 1; i >= 1; -- i){
        //连上i这个结点。 
    }
    return 0;
}