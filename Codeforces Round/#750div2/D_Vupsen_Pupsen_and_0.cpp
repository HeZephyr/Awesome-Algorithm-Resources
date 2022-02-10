/**
  *@filename:D_Vupsen_Pupsen_and_0
  *@author: pursuit
  *@created: 2021-10-24 18:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];
int pos[N];
bool cmp(int i, int j){
    return abs(a[i]) < abs(a[j]);
}
void solve(){
    sort(pos + 1, pos + 1 + n);
    if(n % 2 == 0){
        for(int i = 1; i <= n; i += 2){
            int idx1 = pos[i], idx2 = pos[i + 1];
            int gcd = abs(__gcd(a[idx1], a[idx2]));
            b[idx1] = a[idx2] / gcd;
            b[idx2] = (-1) * a[idx1] / gcd;
        }
    }
    else{
        for(int i = 1; i < n - 2; i += 2){
            int idx1 = pos[i], idx2 = pos[i + 1];
            int gcd = abs(__gcd(a[idx1], a[idx2]));
            b[idx1] = a[idx2] / gcd;
            b[idx2] = (-1) * a[idx1] / gcd;
        }
        int x = a[pos[n - 1]] + a[pos[n]], y = a[pos[n - 2]];
        int gcd = abs(__gcd(x, y));
        b[pos[n - 2]] = (-1) * (x) / gcd;
        b[pos[n]] = y / gcd, b[pos[n - 1]] = y / gcd;
        gcd = abs(__gcd(a[pos[n - 2]], a[pos[n]]));
        while(b[pos[n - 2]] == 0){
            b[pos[n - 2]] -= a[pos[n]] / gcd;
            b[pos[n]] += a[pos[n - 2]] / gcd;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= n; ++ i){
        sum += a[i] * b[i];
        printf("%d ", b[i]);
    }
    puts("");
    //cout << sum << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            pos[i] = i;
        }
        solve();
    }
    return 0;
}           