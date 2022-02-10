#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

char s[N];
int n, last[N];
int vis[26];
bool check[26];
int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    string res = "a";
    for(int len = 1; len <= n; ++ len){
        //1 ~ len
        string cur = "";
        memset(vis, -1, sizeof(vis));
        for(int i = len; i >= 1; -- i){
            int cnt = 0;
            if(vis[s[i] - 'a'] != -1){
                cur = char(vis[s[i] - 'a'] + 'a') + cur;
            }
            else{
                memset(check, 0, sizeof(check));
                for(int j = i + 1; j <= len; ++ j){
                    if(s[i] != s[j] && !check[s[j] - 'a']){
                        ++ cnt;
                        check[s[j] - 'a'] = true;
                    }
                }
                vis[s[i] - 'a'] = cnt;
                cur = char((cnt + 'a') + cur;
            }
        }
        res = max(res, cur);
    }
    cout << res << endl;
    return 0;
}