#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;


int a[N], n, m;
int cnt[N];
vector<int> v;
bool check(int x){
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans += (cnt[i] + x - 1) / x;
    }
    return ans <= m;
}
int main(){
    scanf("%d%d", &n, &m);
    int maxx = 0;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        ++ cnt[a[i]];
    }
    int l = 1, r = n + 1, ans = -1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}