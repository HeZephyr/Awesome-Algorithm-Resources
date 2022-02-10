#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
void solve(){
    //先去重。
    int l = 0, r = n - 1;
    while(l <= r){
        bool flag = false;
        for(int i = 0; i <= (r - l) / 2; ++ i){
            if(s[i + l] > s[r - i]){
                flag = true;
                break;
            }
            else if(s[i + l] < s[r - i]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%c", s[r --]);
        }
        else{
            printf("%c", s[l ++]);
        }
    }
    puts("");
}
int main(){	
    scanf("%d%s", &n, s);
    solve();
    return 0;
}