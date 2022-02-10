#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int INF = 1e9;

map<pair<int, int>, int> mpb, mpw;
int cw, cb, fb[N], fw[N];
vector<int> b[N], w[N];
int tx = {0, 0, 1, -1};
int ty = {1, -1, 0, 0};
void sol(int x, int y, int opt){
    if(opt&1){
        for(int i = 0;i < 4;i++){
            int nx = x+tx[i];
            int ny = y+ty[i];
            if(mpb[{nx, ny}]){
                int 
            }
        }
    }
}
int main(){
    int t, n, x, y;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &x, &y);
            if(i&1){
                mpb[{x, y}] = ++cnt;
                sol(x, y, 1);
            } else {
                mpw[{x, y}] = ++cnt;
                sol(x, y, 2);
            }
        }
    }
    return 0;
}