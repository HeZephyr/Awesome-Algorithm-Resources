/**
  *@filename:B_I_Hate_1111
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 22:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll x;
int main(){
    cin >> t;
    while(t -- ){
        cin >> x;
        if(x > 1099){
            cout << "YES" << endl;
        }
        else{
            bool flag = false;
            while(true){
                if(x % 11 == 0){
                    flag = true;
                    break;
                }
                x -= 111;
                if(x < 0)break;
            }
            if(flag){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}