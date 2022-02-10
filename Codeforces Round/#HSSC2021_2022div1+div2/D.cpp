#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int q;
char s[N], t[N];
//该位置只有删除或不删除。
bool solve(){
    int n = strlen(s + 1), m = strlen(t + 1);
    if(n < m)return false;
    //删除操作会减去两个。所以我们需保证开始的长度和目标字符串保持相同的奇偶性。
    int p = (n - m) & 1;
    int idx = 1;
    bool flag = false;
    for(int i = p + 1; i <= n; ++ i){
        if(flag){
            flag = false;
            continue;
        }
        if(idx <= m && s[i] == t[idx]){
            ++ idx;
        }
        else{
            //说明这里需要删除。则通过下一个字符删除。
            flag = true;
        }
    }
    return idx == m + 1;
}
int main(){	
    scanf("%d", &q);
    while(q -- ){
        scanf("%s%s", s + 1, t + 1);
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}