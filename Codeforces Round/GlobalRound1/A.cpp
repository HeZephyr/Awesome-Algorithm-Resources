/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-16 15:56
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int b, k;
int a[N];
void solve(){
    int res = 0;
    for(int i = 1; i < k; ++ i){
        //a[k - i + 1] * pow(b, k - 1)
        //相乘有一个为偶数即可。
        if(a[i] % 2 && b % 2){
            ++ res;
        }
    }
    if(a[k] % 2){
        ++ res;
    }
    if(res % 2 == 0){
        cout << "even" << endl;
    }
    else{
        cout << "odd" << endl;
    }
}
int main(){
    cin >> b >> k;	
    for(int i = 1; i <= k; ++ i){
        cin >> a[i];
    }
    solve();
    return 0;
}