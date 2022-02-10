/**
  *@filename:A_Shortest_Path_with_Obstacle
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
int x[4],y[4];
void solve(){
}
int main(){
    cin >> t;
    while(t -- ){
        for(int i = 1; i <= 3; ++ i){
            cin >> x[i] >> y[i];
        }
        if(x[1] != x[2] && y[1] != y[2]){
            cout << abs(x[1] - x[2]) + abs(y[1] - y[2]) << endl;
        }
        else if(x[1] == x[2]){
            if(x[1] == x[3] && y[3] >= min(y[1],y[2]) && y[3] <= max(y[1],y[2])){
                cout << abs(y[1] - y[2]) + 2 << endl;
            }
            else{
                cout << abs(y[1] - y[2]) << endl;
            }
        }
        else{
            if(y[1] == y[3] && x[3] >= min(x[1],x[2]) && x[3] <= max(x[1],x[2])){
                cout << abs(x[1] - x[2]) + 2 << endl;
            }
            else{
                cout << abs(x[1] - x[2]) << endl;
            }
        }
    }
    solve();
    return 0;
}