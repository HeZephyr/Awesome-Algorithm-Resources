/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 12:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n;
pii a[N];
ll sum[N];
bool check(int mid){
    ll temp = sum[mid];
    for(int i = mid + 1; i <= n; ++ i){
        if(a[i].first > temp)return false;
        temp += a[i].first;
    }
    return true;
}
void solve(){
    //贪心获取，最小值一定不可以。利用最小值的前缀和。由于具有后效性，所以我们直接找到第一个获胜的人即可。
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= n; ++ i){
        sum[i] = sum[i - 1] + a[i].first;
    }
    int l = 1,r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << n - l + 1 << endl;
    vector<int> pos;
    for(int i = l; i <= n; ++ i){
        pos.push_back(a[i].second);
    }
    sort(pos.begin(),pos.end());
    for(auto & x : pos){
        cout << x << ' ';
    }
    cout << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        solve();
    }
    return 0;
}