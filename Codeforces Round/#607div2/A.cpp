#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
char s1[N];
string s[] = {"op", "used", "usam", "adinm"};
map<string, string> p;
void solve(){
    p["op"] = "FILIPINO", p["used"] = p["usam"] = "JAPANESE", p["adinm"] = "KOREAN";
    int len = strlen(s1 + 1);
    for(int j = 0; j < 4; ++ j){
        bool flag = false;
        for(int k = 0, i = len; k < s[j].size(); ++ k, ++ i){
            if(s1[i] != s[j][k]){
                flag = true;
                break;
            }
            if(!flag){
                cout << p[s[j]] << endl;
                return;
            }
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%s", s1 + 1);
        solve();
    }
    return 0;
}