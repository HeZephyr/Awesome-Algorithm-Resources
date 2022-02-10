/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-23 20:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,x,id[N];
char op[4];
//双端队列实现。
int q[N << 1],l,r;//实现一个偏移。
void solve(){
    scanf("%s%d", op, &x);
    if(op[0] == 'L'){
        id[x] = l;
        q[l --] = x;
    }
    else if(op[0] == 'R'){
        id[x] = r;
        q[r ++] = x;
    }
    else{
        //cout << id[x] << " " << l << " " << r << endl;
        printf("%d\n", min(id[x] - l - 1, r - id[x] - 1));
    }
}
int main(){	
    scanf("%d", &t);
    l = r = N;
    ++ r;
    while(t -- ){
        solve();
    }
    return 0;
}