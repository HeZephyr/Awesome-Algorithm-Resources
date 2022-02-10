/**
  *@filename:A_Omkar_and_Bad_Story
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-06 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9 +7;

int t,n,a[N];
bool flag;
int maxx;
void solve(){
    if(flag){
        puts("NO");
    }
    else{
        puts("YES");
        cout << maxx + 1 << endl;
        for(int i = 0; i <= maxx; ++ i){
            cout << i << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        flag = false;
        maxx = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            if(a[i] < 0){
                flag = true;
            }
            maxx = max(maxx,a[i]);
        }
        solve();
    }
    return 0;
}