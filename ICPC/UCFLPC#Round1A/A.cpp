/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 21:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int a[7],b[7] = {0,1,5,10,20,50,100};
void solve(){
    int maxx = a[1], pos = 1;
    for(int i = 2; i <= 6; ++ i){
        if(a[i] >= maxx){
            maxx = a[i];
            pos = i;
        }
    }
    cout << b[pos] << endl;
}
int main(){
    for(int i = 1; i <= 6; ++ i){
        cin >> a[i];
        a[i] *= b[i];
    }
    solve();
    return 0;
}