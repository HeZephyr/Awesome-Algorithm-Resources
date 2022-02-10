/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 10:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 1e9+7;

bool notPrimer[N];
int primer[N];
ll l,r,k,res[N];
void init(){
    for(int i = 2; i < N; ++ i){
        if(!notPrimer[i]){
            primer[++ primer[0]] = i;
            
        }
        for(int j = 1; j <= primer[0] && i * primer[j] < N; ++ j){
            notPrimer[i * primer[j]] = true;
            if(i % primer[j] == 0)break;//说明碰到了素因子，直接退出。
        }
    }
}
void solve(){
    init();
    for(int i = 0; i < r - l + 1; ++ i){
        res[i] = l + i;//平移区间。
    }
    for(int i = 1; i <= primer[0]; ++ i){
        if(primer[i] >= r)break;
        ll temp1 = (l - 1) / primer[i] + 1;
        if(temp1 == 1)temp1 = 2;
        ll temp2 = r / primer[i];
        for(ll j = temp1; j <= temp2 && j * primer[i] <= r; ++ j){
            if(res[j * primer[i] - l] == j * primer[i]){
                res[j * primer[i] - l] = primer[i];
                //cout << j * primer[i] << " " << primer[i] << endl;
                //cout << primer[i] << " ";
            }
        }
    }
    sort(res,res + r - l + 1);
    ll sum = 0;
    for(int i = 0; i < k; ++ i){
        sum += res[i];
    }
    cout << sum << endl;
}
int main(){
    cin >> l >> r >> k;
    solve();
    return 0;
}