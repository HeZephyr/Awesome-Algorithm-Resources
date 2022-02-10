/**
  *@filename:D2
  *@author: pursuit
  *@created: 2021-08-29 14:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,x,maxx;
int Stack[N],top,bottom;
bool flag = false;
void solve(){
    if(top - bottom > 1 || (top - bottom && Stack[top - 1] < maxx))flag = true;
    printf("%s\n", flag ? "NO" : "YES");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        maxx = max(maxx,x);//更新最大值。
        if(top - bottom){
            if(Stack[top - 1] == x){
                -- top;
            }
            else if(Stack[top - 1] < x){
                //注意这里，只要当前值比x小，说明该值已经无法被挽救回来了。可以自己手动模拟一下。
                flag = true;
                break;
            }
            else{
                Stack[top ++] = x;
            }
        }
        else{
            Stack[top ++] = x;
        }
    }
    solve();
    return 0;
}