/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-12 14:05
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
void solve(){
    int temp = n % 10;
    if(temp >= 5){
        n = n / 10 * 10 + 10;
    }
    else{
        n = n / 10 * 10;
    }
    cout << n << endl;
}
int main(){
    cin >> n;	
    solve();
    return 0;
}