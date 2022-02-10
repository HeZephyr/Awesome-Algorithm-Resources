/**
  *@filename:H
  *@author: pursuit
  *@created: 2021-08-14 12:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
ll pre[20],power[20];
void solve(){
    string temp = "";
    for(int i = 19; i >= 1; -- i){
        if(n > pre[i - 1]){
            //说明在这产生了一个。
            int cnt = 0;
            int temp1 = n - pre[i - 1];
            while(temp1 > power[i - 1]){
                cnt ++;
                temp1 -= power[i - 1]; 
            }
            if(cnt == 0){
                temp += "2";
            } 
            else if(cnt == 1){
                temp += "3";
            }
            else if(cnt == 2){
                temp += "6";
            }
            n -= (cnt + 1) * power[i - 1];
        }
    }
    cout << temp << endl;
}
int main(){
    pre[0] = 0;
    power[0] = 1;
    for(int i = 1; i < 20; ++ i){
        power[i] = power[i - 1] * 3;
        pre[i] = pre[i - 1] + power[i];
    }
    cin >> n;
    solve();
    return 0;
}