/**
  *@filename:Happy_Number
  *@author: pursuit
  *@created: 2021-08-21 13:46
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
bool check(int n){
    set<int> t;
    while(n > 1){
        int temp = 0;
        while(n){
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = temp;
        if(t.count(n))break;
        t.insert(n);
    }
    return n == 1;
}
void solve(){
    if(check(n)){
        puts("HAPPY");
    }
    else{
        puts("UNHAPPY");
    }
}
int main(){	
    scanf("%d", &n);
    solve();
    return 0;
}