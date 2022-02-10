/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-21 12:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N];
char s[4];
bool flag[N];
map<char,int> p;
void cal(int l,int r){
    if(l > r)return;
    ll ans = 1;
    int lst = 1;
    for(int i = l; i <= r; ++ i){
        if(a[i] == 1){
            if(lst + 1 <= i - 1)
        }
    }
}
void solve(){
    p['+'] = 0,p['-'] = 1,p['*'] = 2;
    int len = strlen(s + 1), msk = 0;
    for(int i = 1; i <= len; ++ i)msk |= 1 << p[s[i]];
    //分类讨论判断。
    if(msk == 1 || msk == 2 || msk == 4){
        //说明只有一个符号，此时别无选择。
        for(int i = 1; i <= n; ++ i){
            printf("%d%c", a[i], i == n ? '\n' : s[1]);
        }
    }
    else if(msk == 3){
        //或者msk = 3说明只有+-，我们肯定是选择加。
        for(int i = 1; i <= n; ++ i){
            printf("%d%c", a[i], i == n ? '\n' : '+');
        }
    }
    else if(msk == 6){
        //说明只有* -，我们肯定是选择0前面全填*，连接0处填-可保证后面都为0.
        bool flag = false;
        printf("%d", a[1]);
        for(int i = 2; i <= n; ++ i){
            if(!a[i] && !flag){
                //说明出现了第一个0。
                flag = true;
                putchar('-');
            }
            else{
                putchar('*');
            }
            printf("%d",a[i]);
        }
    }
    else{
        //有 + *，由于-号和+号是对等的，且在我们这里不会选择-，所以有没有-号都没有影响。
        for(int i = 1; i <= n; ++ i){
            if(!a[i]){
                //即0前后一定都是+号的。
                if(i != 1)flag[i - 1] = true;
                if(i != n)flag[i] = true; 
            }
        }
        int pre = 0;
        for(int i = 1; i <= n; ++ i){
            if(!a[i])cal(pre + 1, i - 1),pre = i;
        }
        cal(pre + 1, n);
        for(int i = 1; i < n; ++ i){
            printf("%d%c", a[i], flag[i] ? '+' : '*');
        }
        pritnf("%d\n", a[n]);
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    scanf("%s", s + 1);
    solve();
    return 0;
}