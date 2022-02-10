#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 100;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
char s[N];
void solve(){
    int cntb = 0, cntc = 0, cnta = 0, last1 = 0, last2 = 0, llast1, llast2;
    int cnt = 0;
    int minn = INF;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'a'){
            if(cnt >= 1 && 2 > (cntb - last1) && 2 > (cntc - last2)){
                //cout << cntb << " " << cntc << " " << last1 << " " << last2 << endl;
                minn = min(minn, 2 + cntb - last1 + cntc - last2);
            }
            if(cnt >= 2 && 3 > (cntb - llast1) && 3 > (cntc - llast2)){
                //cout << cntb << " " << cntc << " " << llast1 << " " << llast2 << endl;
                minn = min(minn, 3 + cntb - llast1 + cntc - llast2);
            }
            llast1 = last1, llast2 = last2;
            last1 = cntb, last2 = cntc;
            ++ cnt;
        }
        else if(s[i] == 'b')++ cntb;
        else{
            ++ cntc;
        }
    }
    if(minn == INF)puts("-1");
    else printf("%d\n", minn);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%s", &n, s + 1);
        solve();
    }
    return 0;
}