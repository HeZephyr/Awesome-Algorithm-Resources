#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, x, y, k[12];
int m;
int p[12];
void solve(){
    bool flag1 = false, flag2 = false;
    if(x + m > n)flag1 = true;
    if(x - m < 1)flag2 = true;
    int idx = 1;
    for(int i = x + 1; i + m <= n; ++ i){
        if(p[idx ++] != k[i]){
            flag1 = true;
            break;
        }
    }
    idx = 1;
    for(int i = x - 1; i - m >= 1; -- i){
        if(p[idx ++] != k[i]){
            flag2 = true;
            break;
        }
    }
    if(x < y){
        if(!flag1 && flag2){
            puts("Right");
        }
        else if(flag1 && !flag2){
            puts("Wrong");
        }
        else{
            puts("Unsure");
        }
    }
    else{
        if(flag1 && !flag2){
            puts("Right");
        }
        else if(!flag1 && flag2){
            puts("Wrong");
        }
        else{
            puts("Unsure");
        }
    }
}
int main(){	
    scanf("%d%d%d", &n, &x, &y);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &k[i]);
    }
    scanf("%d", &m);//表示经过的站点数。
    for(int i = 1; i <= m; ++ i){
        scanf("%d", &p[i]);
    }
    solve();
    return 0;
}