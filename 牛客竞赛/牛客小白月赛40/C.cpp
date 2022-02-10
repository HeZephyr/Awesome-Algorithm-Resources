#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
void solve(){
    int cnt = 0;
    for(int x = 1; x <= n; ++ x){
        string s = "";
        int temp = x;
        while(temp){
            s = char(temp % 2 + '0') + s;
            temp /= 2;
        }
        for(int y = x + 1; y <= n; ++ y){
            string s1 = "";
            temp = y;
            while(temp){
                s1 = char(temp % 2 + '0') + s1;
                temp /= 2;
            }
            for(int i = 0; i + k <= s.size(); ++ i){
                if(s1.find(s.substr(i, k)) != -1){
                    //cout << x << " " << y << endl;
                    ++ cnt;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}
int main(){	
    scanf("%d%d", &n, &k);
    solve();
    return 0;
}