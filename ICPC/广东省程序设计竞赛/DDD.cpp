#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e5+7;
ll n, a[N], maxx;
bool ok[N];
int main(){
    scanf("%lld", &n);
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        maxx = max(maxx, a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        int l = i, r = i;
        ll ans = a[i];
        while(true){
            bool flag = false;
            if(l > 0 && ans >= a[l]){
                if(l != i)ans *= 2;
                flag = true;
                -- l;
            }
            if(r <= n && ans >= a[r]){
                if(r != i)ans *= 2;
                flag = true;
                ++ r;
            }
            if(ans >= maxx){
                ok[i] = true;
                break;
            }
            if(!flag)break;
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; ++ i){
        if(ok[i])res.push_back(i);
    }
    int len = res.size();
    cout << len << endl;
    for(int i = 0; i < len; ++ i){
        cout << res[i];
        if(i != len - 1)cout << " ";
        else cout << endl;
    }
    return 0;
}