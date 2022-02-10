/**
  *@filename:C_Challenging_Cliffs
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 22:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,h[N];
void solve(){
    sort(h + 1,h + 1 + n);
    int idx,minn = 0x3f3f3f3f;
    for(int i = 1; i <= n - 1; ++ i){
        if(h[i + 1] - h[i] < minn){
            minn = h[i + 1] - h[i];
            idx = i;
        }
    }
    //cout << idx << endl;
    cout << h[idx] << " ";
    for(int i = idx + 2; i <= n; ++ i){
        cout << h[i] << " ";
    }
    for(int i = 1; i < idx; ++ i){
        cout << h[i] << " ";
    }
    cout << h[idx + 1] << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &h[i]);
        }
        solve();
    }
    return 0;
}