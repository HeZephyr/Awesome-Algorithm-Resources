/**
  *@filename:7-2
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-20 12:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,m,s;
void solve(){
}
int main(){
    cin>>n>>m>>s;
    if(m*s*2<n){
        printf("hai sheng %d mi! jia you ya!\n",n-s*m);
    }
    else{
        printf("hai sheng %d mi! chong ya!\n",n-s*m);
    }
    solve();
    return 0;
}