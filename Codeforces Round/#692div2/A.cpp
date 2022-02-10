/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-25 22:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char s[N];
void solve(){
    int cnt1 = 0,cnt2 = 0;
    bool flag = true;
    for(int i = n; i >= 1; -- i){
        if(s[i] == ')' && flag){
            cnt1 ++;
        }
        else{
            flag = false;
            cnt2 ++;
        }
    }
    if(cnt1 > cnt2){
        puts("Yes");
    }
    else{
        puts("No");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}