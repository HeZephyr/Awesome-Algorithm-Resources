/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 15:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n;
string s;
int ans;
void solve(){
}
int main(){
    cin >> n >> s;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '1'){
             if(!(i & 1)){
                cout << "Takahashi" << endl;
            }
            else{
                cout << "Aoki" << endl;
            }  
            break;
        }
    }
    solve();
    return 0;
}