/**
  *@filename:JJJ
  *@author: pursuit
  *@created: 2021-11-04 16:02
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int a[N];//如果可以使至少k次请求被缓存命中，则输出块中的最小容量。否则输出cbddl
int head, e[N], idx, l[N], r[N];
void init(){
    idx = 2, r[0] = 1, l[1] = 0;
}
void add(int k, int x){
    e[idx] = x, l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx, ++ idx;
}
void remove(int k){
    l[r[k]] = l[k], r[l[k]] = r[k];
}
bool check(int x){
    unordered_map<int, int> p; 
    head = 0, idx = 1;
    int i = 1;
    int cnt = 0, len = 0;
    while(len < x && i <= n){
    }
    //如果填满了内存。我们需要删除队头元素。往队尾插入。
    while(i <= n){
    }
    puts("");
    printf("cnt: %d\n", cnt);
    return cnt >= k;
}
void solve(){
    int l = 1, r = n + 2;
    while(l < r){
        int mid = (l + r) >> 1;
        printf("l: %d r: %d mid: %d\n", l, r, mid);
        if(!check(mid)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    if(l > n){
        puts("cbddl");
    }
    else{
        printf("%d\n", l);
    }
}
int main(){	
    // to hit the cache.
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}