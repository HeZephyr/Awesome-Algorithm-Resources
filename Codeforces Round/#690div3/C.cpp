/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-09 14:33
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    int maxx = (1 + 9) * 9 / 2;
    if(n > maxx){
        cout << - 1 << endl;
    }
    else{
        vector<int> num;
        int temp = 9;
        while(temp && n > 0){
            if(n >= temp){
                num.push_back(temp);
                n -= temp;
            }
            temp --;
        }
        for(int i = num.size() - 1; i >= 0 ; -- i){
            cout << num[i];
        }
        cout << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}