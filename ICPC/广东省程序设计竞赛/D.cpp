#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e5+7;
ll n, a[N], b[N];
bool cmp(int i, int j){
    return a[i] < a[j];
}
bool check(int x){
    ll ans = a[x];
    for(int i = 1; i <= n; ++ i){
        if(ans > 1e9)return true;
        if(b[i] == x)continue;
        if(ans >= a[b[i]])ans *= 2;
        else return false;
    }
    return true;
}
int main(){
    scanf("%lld", &n);
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        //cout << mid << endl;
        if(check(b[mid])){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    vector<int> res;
    for(int i = l; i <= n; ++ i){
        res.push_back(b[i]);
    }
    sort(res.begin(), res.end());
    int len = res.size();
    cout << len << endl;
    for(int i = 0; i < len; ++ i){
        cout << res[i];
        if(i != len - 1)cout << " ";
        else cout << endl;
    }
    return 0;
}