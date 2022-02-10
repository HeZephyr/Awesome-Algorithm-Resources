#include<bits/stdc++.h>

using namespace std;

int n,m;
char s[2010][2010];
char temp[2010];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i] + 1;
    }
    cin >> temp + 1;
    int ans = 0,cnt = 0;
    for(int i = 1 ; i <= n; ++ i){
        cnt = 0;
        for(int j = 1; j <= n; ++ j){
            if(s[i][j] == '0'){
                cnt ++;
            }
            else{
                if(cnt >= m){
                    ans += cnt - m + 1;
                }
                cnt = 0;
            }
        }
        if(cnt >= m){
            ans += cnt - m + 1;
        }
    }
    cout << ans << endl;
    return 0;
}