/**
  *@filename:B-纯质数
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-05 13:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20210610;
const int P = 1e9+7;

bool notprimer[N];
void init(){
    notprimer[0] = notprimer[1] = true;
    for(int i = 2; i < N ; ++ i){
        if(!notprimer[i]){
            for(int j = i * 2; j < N; j += i){
                notprimer[j] = true;
            }
        }
    }
}
bool check(int n){
    while(n){
        if(notprimer[n % 10])return false;
        n /= 10;
    }
    return true;
}
void solve(){
    init();
    int cnt = 0;
    for(int i = 1; i <= 20210605; ++ i){
        if(!notprimer[i] && check(i)){
            cnt ++;
        }
    }
    cout << cnt << endl;//1903
}
int main(){
    solve();
    return 0;
}