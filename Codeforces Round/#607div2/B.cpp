#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
string s, c;
void solve(){
    int len = min(int(s.size()), int(c.size()));
    bool flag = false;
    int i = 0;
    //only swap one
    for(; i < len; ++ i){
        if(s[i] < c[i]){
            break;
        }
        else{
            for(int j = i + 1; j < s.size(); ++ j){
                if(s[j] < c[i]){
                    swap(s[i], s[j]);
                    flag = true;
                    break;
                }
            }
            if(flag)break;
            if(s[i] > c[i]){
                for(int j = s.size() - 1; j >= i + 1; -- j){
                    if(s[j] == c[i]){
                        swap(s[i], s[j]);
                        break;
                    }
                }
                break;
            }
        }
    }
    i = 0;
    for(; i < len; ++ i){
        if(s[i] < c[i]){
            flag = true;
            break;
        }
        else if(s[i] > c[i]){
            flag = false;
            break;
        }
    }
    if(i == len){
        //说明前面都相等，对比长度；
        if(s.size() < c.size())flag = true;
        else flag = false;
    }
    if(flag)cout << s << endl;
    else cout << "---" << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s >> c;
        solve();
    }
    return 0;
}