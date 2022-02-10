/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 20:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 5;
const int P = 1e9+7;

int n,k,a[N],cnt[N];
int pos[N];
bool flag;
bool cmp(int i,int j){
    return a[i] < a[j];
}
void solve(){
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        sort(pos + 1,pos + 1 + n,cmp);
        for(int i = 1; i <= n; ++ i){
            a[pos[i]] = i % k + 1;
        }
        for(int i = 1; i <= n; ++ i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        cnt[a[i]] ++;
        if(cnt[a[i]] > k){
            flag = true;
        }
        pos[i] = i;
    }
    solve();
    return 0;
}