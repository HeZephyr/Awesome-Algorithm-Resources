/**
  *@filename:A_Windblume_Ode
  *@author: pursuit
  *@created: 2021-10-17 19:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
bool check(int x){
    for(int i = 2; i * i <= x; ++ i){
        if(x % i == 0)return true;
    }
    return false;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            sum += a[i];
        }
        if(n == 3 && sum == 3){
            puts("1\n1");
            continue;
        }
        if(check(sum)){
            cout << n << endl;
            for(int i = 1; i <= n; ++ i){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            cout << n - 1 << endl;
            bool flag = true;
            for(int i = 1; i <= n; ++ i){
                if(check(sum - a[i]) && flag){
                    flag = false;
                    continue;
                }
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}