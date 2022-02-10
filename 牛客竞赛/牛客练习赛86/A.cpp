/**
  *@filename:D_Deleting_Divisors
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 23:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    bool flag = false;
    //如果是奇数必败。
    if(n & 1){
        flag = true;
    }
    else{
        int cnt = 0;
        while(n % 2 == 0){
            cnt ++;
            n /= 2;
        }
        if(n > 1){
            flag = false;
        }
        else{
            if(cnt & 1){
                flag = true;
            }
            else{
                flag = false;
            }
        }
    }
    if(flag){
        puts("Bob");
    }
    else{
        puts("Alice");
    }
}
int main(){
    cin >> n;
    solve();
    return 0;
}