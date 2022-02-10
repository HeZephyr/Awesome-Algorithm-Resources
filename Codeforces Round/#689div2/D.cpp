/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-18 18:49
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
mid为max + min / 2向下取整。
分块，即将数组拆分成left和right两部分。左半部分 <= mid, 右半部分大于mid
*/
int t,n,q,x;
int a[N];
ll sum[N];
map<int,bool> p;
void work(int l, int r){
    if(sum[r] - sum[l - 1] <= 1e9){
        p[sum[r] - sum[l - 1]] = true;
    }
    if(a[l] == a[r])return;//相等了就不用再分了，因为分下取一直是在左边。
    int mid = a[l] + a[r] >> 1;//获取中间值。从而得到分割点。
    int pos = upper_bound(a + l, a + r + 1, mid) - a;
    work(l,pos - 1),work(pos, r);
}
void solve(){
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i){
        sum[i] = sum[i - 1] + a[i];
    }
    work(1,n);
    while(q -- ){
        scanf("%d", &x);
        printf("%s\n", p[x] ? "YES" : "NO");
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &q);
        p.clear();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }	
    return 0;
}