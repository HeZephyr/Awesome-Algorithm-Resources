/**
  *@filename:A_Two_Subsequences
  *@author: pursuit
  *@created: 2021-10-25 14:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e2 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
char s[N];
void solve(){
    int n = strlen(s);
    char c = 'z' + 1;
    int idx = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] < c){
            c = s[i];
            idx = i;
        }
    }
    cout << c << " ";
    for(int i = 0; i < n; ++ i){
        if(i != idx){
            cout << s[i];
        }
    }
    cout << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}