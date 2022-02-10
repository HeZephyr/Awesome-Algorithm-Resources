/**
  *@filename:D1
  *@author: pursuit
  *@created: 2021-08-29 14:32
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,x;

int Stack[N],top,bottom;
void solve(){
    //最后栈顶元素小于等于1即可。因为其他的都已经配对好了可以变成任意高度。
    if(top - bottom <= 1){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        x %= 2;
        //如果栈为空或者栈顶元素不能和它匹配。就入栈。
        if(top - bottom == 0 || Stack[top - 1] != x){
            Stack[top ++] = x;
        }
        else{
            -- top;
        }
    }
    solve();
    return 0;
}