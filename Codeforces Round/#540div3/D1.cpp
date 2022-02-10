/**
  *@filename:D1
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 11:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
const int P = 1e9+7;

int n,m;
ll a[N],ans;
bool check(int day){
    //为了最少消耗，我们均分day。
    ll ans = 0,cnt = 1,c = 0;
    while(true){
        for(int d = 1; d <= day && cnt <= n; ++ d){
            ans += max(1LL * 0,a[cnt ++] - c);
        }
        c++;
        if(cnt > n)break;
    }
    return ans >= m;
}
void solve(){
    sort(a + 1, a + 1 + n,greater<int>() );
    //此原理就是尽可能的浪费一些也可以行。ans为最大的数量。
    if(ans < m){
        cout << - 1 << endl;
    }
    else{
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
}
int main(){
    cin >> n >> m;
    for(int i= 1; i <= n; ++ i){
        cin >> a[i];
        ans += a[i];
    }
    solve();
    return 0;
}