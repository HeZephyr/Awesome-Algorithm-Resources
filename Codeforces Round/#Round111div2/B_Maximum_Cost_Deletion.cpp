/**
  *@filename:B_Maximum_Cost_Deletion
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 20:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a,b;
string s;
void solve(){
    int cnt = 1;//判断cnt可以切割可以分成几部分。
    char pre = s[0];
    for(int i = 0; i < n; ++ i){
        if(s[i] != pre){
            pre = s[i];
            cnt ++;
        }
    }
    cnt = cnt / 2 + 1;//由于中间一段需要用来分割，剩下的左右两半自然迎刃而解。
    //由于a * l时不变的，即消掉n个必定消耗n * a，关键在于b。
    if(b >= 0){
        cout << (a + b) * n << endl;
    }
    else{
        cout << a * n + cnt * b << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        cin >> s;
        solve();
    }
    return 0;
}