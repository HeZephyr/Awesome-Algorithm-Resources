/**
  *@filename:A_Stone_Game
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N];
int pos[N];
bool cmp(int i,int j){
    return a[i] < a[j];
}
void solve(){
    sort(pos + 1,pos + 1 + n,cmp);
    int minn = 0x3f3f3f3f;
    if(pos[1] >= pos[n]){
        minn = min(pos[1],min(n - pos[n] + 1,pos[n] + n - pos[1] + 1));
    }
    else{
        minn = min(pos[n],min(n - pos[1] + 1,pos[1] + n - pos[n] + 1));
    }
    cout << minn << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            pos[i] = i;
        }
        solve();
    }
    return 0;
}