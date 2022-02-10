/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 21:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int p,c,x;
vector<pair<int,int> > v;
void solve(){
    sort(v.begin(), v.end());
    for(auto &iter : v){
        cout << (char)(iter.second + 'A');
    }
    cout << endl;
}
int main(){
    cin >> p;
    for(int i = 0; i < p; ++ i){
        cin >> c;
        for(int j = 0; j < c; ++ j){
            cin >> x;
            v.push_back({x,i});
        }
    }
    solve();
    return 0;
}