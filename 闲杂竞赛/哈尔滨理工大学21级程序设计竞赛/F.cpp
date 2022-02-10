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
vector<pair<char, int> > p;
void solve(){
    //先去重。
    char c = s[1];
    int cnt = 1;
    for(int i = 2; i <= n + 1; ++ i){
        if(s[i] == c){
            ++ cnt;
        }
        else{
            p.push_back({c, cnt});
            c = s[i];
            cnt = 1;
        }
    }
    int l = 0, r = p.size() - 1;
    string res = "";
    while(l < r){
        if(p[l].first > p[r].first){
            for(int i = 0; i < p[r].second; ++ i){
                res += p[r].first;
            }
            -- r;
        }
        else if(p[l].first < p[r].first){
            for(int i = 0; i < p[l].second; ++ i){
                res += p[l].first;
            }
            ++ l;
        }
        else{
            //相等。
            if(p[l].second > p[r].second){
                if(r - l > 1 && p[r - 1].first < p[l].first){
                    for(int i = 0; i < p[r].second; ++ i){
                        res += p[r].first;
                    }
                    -- r;
                }
                else{
                    for(int i = 0; i < p[l].second; ++ i){
                        res += p[l].first;
                    }
                    ++ l;
                }
            }
            else if(p[l].second < p[r].second){
                if(r - l > 1 && p[l + 1].first < p[r].first){
                    for(int i = 0; i < p[l].second; ++ i){
                        res += p[l].first;
                    }
                    ++ l;
                }
                else{
                    for(int i = 0; i < p[r].second; ++ i){
                        res += p[r].first;
                    }
                    -- r;
                }
            }
            else{
                //相等。
                if(r - l > 2 && p[l + 1].first < p[r - 1].first){
                    for(int i = 0; i < p[l].second; ++ i){
                        res += p[l].first;
                    }
                    ++ l;
                }
                else{
                    for(int i = 0; i < p[r].second; ++ i){
                        res += p[r].first;
                    }
                    -- r;
                }
            }
        }
    }
    for(int i = 0; i < p[l].second; ++ i){
        res += p[l].first;
    }
    cout << res << endl;
}
int main(){	
    scanf("%d%s", &n, s + 1);
    solve();
    return 0;
}