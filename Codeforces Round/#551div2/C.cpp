/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-11-04 21:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
void solve(){
    if(n & 1){
        puts(":(");
        return;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == '(')++ cnt1;
        else if(s[i] == ')')++ cnt2;
    }
    if(cnt1 > n / 2 || cnt2 > n / 2){
        puts(":(");
        return;
    }
    cnt1 = n / 2 - cnt1, cnt2 = n / 2 - cnt2;//需要分cnt1的(，cnt2个这个。
    for(int i = 1; i <= n; ++ i){
        if(s[i] == '?'){
            if(cnt1 > 0){
                s[i] = '(';
                -- cnt1;
            }
            else{
                s[i] = ')';
            }
        }
    }
    //检查是否合法。
    stack<char> t;
    int idx = 0;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == '('){
            t.push(s[i]);
        }
        else{
            if(t.empty()){
                idx = 1;
                break;
            }
            else{
                t.pop();
                if(t.empty()){
                    idx = i;
                    break;
                }
            }
        }
    }
    if(idx == n){
        printf("%s", s + 1);
    }
    else{
        puts(":(");
    }
}
int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);	
    solve();
    return 0;
}